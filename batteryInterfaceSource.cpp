#pragma once
#include <assert.h>
#include <iostream>
#include "batteryInterface.h"
#include <iomanip>
#include <map>
#include <sstream>  

using namespace std;

int BatteryElements::temprature;
float BatteryElements::voltage;
float BatteryElements::current;

float CurrentIndicator::currentMinThreshould = 0.8;
float CurrentIndicator::currentMaxThreshould = 1.2;

float VoltageIndicator::voltageMinThreshould = 3;
float VoltageIndicator::vOltageMaxThreshould = 6;

float TempratureIndicator::temperatureMinThreshould = -20;
float TempratureIndicator::temperatureMaxThreshould = 50;

int   StateOfChargeRate::fullBatteryStatus = 80;
int   StateOfChargeRate::lowBatteryStatus = 20;

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

int temperatureConversion(string temp)
{
	int measurement;
	string unit;
	std::stringstream ss;
	ss << temp;
	ss >> measurement >> unit;

	if ("F" == unit)
	{
		return  (measurement - 32) * 5 / 9;
	}
	
	return measurement;
}
BatteryIndicator::BatteryIndicator(string temp, float vol, float curr)
{
	current = curr;
	voltage = vol;

	/*----temperature conversion----*/

	temprature = temperatureConversion(temp);

	/*----temperature conversion----*/

	BatterySpecification Batteryspec;
	Batteryspec.BatterySpecificationPrinter();
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
	
	if (wheaterHandler.weatherStatus())
	{
		return true;
	}
	else
	{
		return true;
	}
}

bool StatusOfCharge::BatteryChargingStatus(float BatteryStatus)
{
	cout << "-------------------------------------------------Battery StateOfCharge(SOC) --------------------------------------------------" << endl;
	StatusOfCharge::currentBatteryStatus = BatteryStatus;
	if (currentBatteryStatus <= lowBatteryStatus )
	{
		cout << "Battery is critical !" << endl;
		return true;
	}
	if (currentBatteryStatus == fullBatteryStatus)
	{
		cout << "warning : Battery is full charged ! Please disconnect !" << endl;
		return true;
	}
	
}