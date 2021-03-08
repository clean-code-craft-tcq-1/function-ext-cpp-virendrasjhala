#pragma once
#include <assert.h>
#include <iostream>
#include "batteryInterface.h"
#include <iomanip>
#include <map>
using namespace std;

float BatteryElements::temprature;
float BatteryElements::voltage;
float BatteryElements::current;

float CurrentIndicator::currentMinThreshould = 0.8;
float CurrentIndicator::currentMaxThreshould = 1.2;
float CurrentIndicator::currentWarning = currentMaxThreshould * 0.05;
float CurrentIndicator::currentMaxWarning = currentMinThreshould + currentWarning;
float CurrentIndicator::currentMinWarning = currentMaxThreshould - currentWarning;

float VoltageIndicator::voltageMinThreshould = 3;
float VoltageIndicator::vOltageMaxThreshould = 6;
float VoltageIndicator::voltageWarning = vOltageMaxThreshould * 0.05;
float VoltageIndicator::voltageMaxWarning = voltageMinThreshould + voltageWarning;
float VoltageIndicator::voltageMinWarning = vOltageMaxThreshould - voltageWarning;

float TempratureIndicator::temperatureMinThreshould = -20;
float TempratureIndicator::temperatureMaxThreshould = 50;
float TempratureIndicator::temperatureWarning = temperatureMaxThreshould * 0.05;
float TempratureIndicator::temperatureMinThreshouldWarning = temperatureMinThreshould + temperatureWarning;
float TempratureIndicator::temperatureMaxThreshouldWarning = temperatureMaxThreshould - temperatureWarning;


int   StateOfChargeRate::fullBatteryStatus = 80;
int   StateOfChargeRate::lowBatteryStatus = 20;
int   StateOfChargeRate::warningThreshould = fullBatteryStatus * 0.05;
int   StateOfChargeRate::lowBatteryStatusEarlyWarning = lowBatteryStatus + warningThreshould;
int   StateOfChargeRate::fullBatteryStatusEarlyWarning = fullBatteryStatus - warningThreshould;

int   StatusOfCharge::currentBatteryStatus;
float weatherIndicator::todaysTemperature;
float weatherIndicator::hotWeather  = 70;
float weatherIndicator::coldWeather = -50;

void BatterySpecification::BatterySpecificationPrinter()
{
	
	cout << "-------------------------------------------------Battery Specification -------------------------------------------------------" << endl;
	cout << "    || Wheather status || " << "           ||Battery status || " << "                         ||Battery current/voltage||" << endl;
	cout << "Temp       "    <<"                        B_Tmptr| "<<"low| "<< "full| "<< "actual| "<<   "      C_Min| "<<"C_Max| "<<"Curr_actual| "<<"V_Min| "<<"V_Max| "<<"Volt_actual| "<<endl;
	cout << weatherIndicator::todaysTemperature     <<"`C"   << setw(33)   << BatteryElements::temprature            <<"`C" <<"    "    << StateOfChargeRate::lowBatteryStatus <<"%"<<"   "
		 << StateOfChargeRate::fullBatteryStatus <<"%"    <<"   "        << StatusOfCharge::currentBatteryStatus <<"%"  << setw(14) << CurrentIndicator::currentMinThreshould <<"E"
		 << "   "  << CurrentIndicator::currentMaxThreshould <<"E"<<"      "<< BatteryElements::current              <<"E"  << setw(9) 
		 << VoltageIndicator::voltageMinThreshould  <<"V"    << setw(7)     << VoltageIndicator::vOltageMaxThreshould <<"V" <<"      "  << BatteryElements::voltage               <<"V"<<endl;
}
bool CurrentIndicator::currentStatus()
{
	if (currentMinThreshould >= BatteryElements::current || currentMaxThreshould <= BatteryElements::current)
	{
		cout << "Charge current Rate out of range!\n";
		return true;
	}
	else
	{
		return true;
	}
}

bool VoltageIndicator::voltageStatus()
{
	CurrentIndicator Currentindicator;
	if (voltageMinThreshould >= BatteryElements::voltage || vOltageMaxThreshould <= BatteryElements::voltage)
	{
		cout << "Charge voltage Rate out of range!\n";
		return true;
	}
	return true;
}

bool TempratureIndicator::tempratureStatus()
{
	VoltageIndicator Voltageindicator;
	if (temperatureMinThreshould >= BatteryElements::temprature || temperatureMaxThreshould <= BatteryElements::temprature)
	{
		cout << "Charge tamperature of battery out of range!\n";
		return true;
	}
	return true;
}

BatteryIndicator::BatteryIndicator(float temp, float vol, float curr)
{
	current = curr;
	voltage = vol;
	temprature = temp;
}

bool weatherIndicator::weatherStatus()
{
	TempratureIndicator Tempratureindicator;
	if (hotWeather < todaysTemperature)
	{
		cout << "Very High Temperature!! charge is not allowed !" << endl;
		return true;
	}
	if (coldWeather > todaysTemperature)
	{
		cout << "Very Low Temperature!! charge is not allowed !" << endl;
		return true;
	}
	
}

void weatherIndicator::TodaysTemperature(float temp)
{
	todaysTemperature = temp;
}

bool StateOfChargeRate::batteryRequirements_For_Charging()
{
	weatherIndicator wheaterHandler;
	BatterySpecification Batteryspec;
	if (wheaterHandler.weatherStatus())
	{
		Batteryspec.BatterySpecificationPrinter();
		return true;
	}
	else
	{
		return true;
	}
}
bool lowWarning()
{
	if (StatusOfCharge::lowBatteryStatusEarlyWarning >= StatusOfCharge::currentBatteryStatus && StatusOfCharge::currentBatteryStatus >= StatusOfCharge::lowBatteryStatus)
	{
		cout << "warning : Battery is low !" << endl;
		return true;
	}
	return false;
}
bool highWarning()
{	

	if (StatusOfCharge::fullBatteryStatusEarlyWarning <= StatusOfCharge::currentBatteryStatus && StatusOfCharge::fullBatteryStatus != StatusOfCharge::currentBatteryStatus)
	{
		cout << "warning : Battery is about to charge !" << endl;
		return true;
	}
	return false;
}


bool StatusOfCharge::BatteryChargingStatus(float BatteryStatus)
{
	bool returnCode;
	StatusOfCharge::currentBatteryStatus = BatteryStatus;
	returnCode = lowWarning();
	if (!returnCode && currentBatteryStatus <= lowBatteryStatus )
	{
		cout << "Battery is critical !";
		return true;
	}
	returnCode = highWarning();
	if (!returnCode && currentBatteryStatus == fullBatteryStatus)
	{
		cout << "warning : Battery is full charged ! Please disconnect !" << endl;
		return true;
	}
	
}