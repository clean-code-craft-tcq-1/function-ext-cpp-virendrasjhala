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

bool StatusOfCharge::lowStatus(string checkFor)
{
	
	if (checkFor == "B_status")
	{

		if (currentBatteryStatus <= lowBatteryStatus)
		{
			cout << "Battery is critical! Please Recharge battery !" << endl;
			return true;
		}
		if (currentBatteryStatus <= lowBatteryStatusEarlyWarning)
		{
			cout << "Warning : Battery is low! Please Recharge battery !" << endl;
			return true;
		}
		else
		{
			cout << "Battery charge is normal !" << endl;
			return true;
		}
		
	}

	if (checkFor == "Voltage")
	{
		if (BatteryElements::voltage <= VoltageIndicator::voltageMinThreshould)
		{
			cout << "Low voltage Breach! Please check the Voltage level !";
			return true;
		}
		if (BatteryElements::voltage <= VoltageIndicator::voltageMinWarning)
		{
			cout << "warning : Low voltage! Please check the Voltage level !";
			return true;
		}
		else
		{
			cout << "voltage is normal !";
			return true;
		}
	}

	if (checkFor == "Current")
	{
		if (BatteryElements::voltage <= CurrentIndicator::currentMinThreshould)
		{
			cout << "Low current Breach! Please check the current level !";
			return true;
		}
		if (BatteryElements::current <= CurrentIndicator::currentMinWarning)
		{
			cout << "warning : Low current! Please check the current level !";
			return true;
		}
		else
		{
			cout << "Battery current is normal !" << endl;
			return true;
		}
	}

	if (checkFor == "Temperature")
	{
		if (BatteryElements::temprature <= TempratureIndicator::temperatureMinThreshould)
		{
			cout << "Low voltage Breach! Please check the Voltage level !";
			return true;
		}
		if (BatteryElements::temprature <= TempratureIndicator::temperatureMinThreshouldWarning)
		{
			cout << "Low voltage Warning! Please check the Voltage level !";
			return true;
		}
		else
		{
			cout << "! Battery Temperature is normal !";
			return true;
		}
	}

}

bool StatusOfCharge::highStatus(string checkFor)
{
	if (checkFor == "B_status")
	{
		if (currentBatteryStatus == fullBatteryStatus)
		{
			cout << "Battery is completely charged!! please disconnect charger !" << endl;
			return true;
		}
		if(currentBatteryStatus >= fullBatteryStatusEarlyWarning)
		{
			cout << "warning : Battery is about to charge!! please disconnect charger !" << endl;
			return true;
		}
		
	}
	return false;
}

bool CurrentIndicator::currentStatus()
{
	if(currentMinThreshould >= BatteryElements::current || currentMaxThreshould <= BatteryElements::current)
		{
			cout << "Charge current Rate out of range!\n";
			return false;
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
			return false;
		}
	else
		{
			return Currentindicator.currentStatus();
		}
}

bool TempratureIndicator::tempratureStatus()
{
	VoltageIndicator Voltageindicator;
	if (temperatureMinThreshould >= BatteryElements::temprature || temperatureMaxThreshould <= BatteryElements::temprature)
		{
			cout << "Charge tamperature of battery out of range!\n";
			return false;
		}
	else
		{
			return Voltageindicator.voltageStatus();
		}
}

BatteryIndicator::BatteryIndicator(float temp, float vol, float curr)
{
	current    = curr;
	voltage    = vol;
	temprature = temp;
}

bool weatherIndicator::weatherStatus()
{
	TempratureIndicator Tempratureindicator;
	if (hotWeather < todaysTemperature)
	{
		cout << "Very High Temperature!! charge is not allowed !" << endl;
		return false;
	}
	if (coldWeather > todaysTemperature)
	{
		cout << "Very Low Temperature!! charge is not allowed !" << endl;
		return false;
	}
	return Tempratureindicator.tempratureStatus();
}

void weatherIndicator::TodaysTemperature(float temp)
{
	todaysTemperature = temp;
}

bool StateOfChargeRate::batteryRequirements_For_Charging()
{
	weatherIndicator weatherHandler;
	BatterySpecification Batteryspec;
	if (weatherHandler.weatherStatus())
		{
		    Batteryspec.BatterySpecificationPrinter();
			return true;
		}
	else
		{
			return false;
		}
}

bool StatusOfCharge::BatteryChargingStatus(float remainBatteryStatus)
{
	StatusOfCharge::currentBatteryStatus = remainBatteryStatus;
	cout << "-------------------------------------------------Battery status (SOC) --------------------------------------------------------" << endl;
	if (highStatus("B_status"))
	{
		return true;
	}
	if (lowStatus("B_status"))
	{
		return true;
	}

	
}
	