#pragma once
#include <assert.h>
#include <iostream>
#include "batteryInterface.h"
#include <iomanip>
#include <sstream>  
#include <map>
#include <utility>
#include <vector>
using namespace std;

int BatteryElements::temperature;
float BatteryElements::voltage;
float BatteryElements::current;

double CurrentIndicator::currentMinThreshould = 0.8;
double CurrentIndicator::currentMaxThreshould = 1.2;

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

string LanguageSupported::language;
LanguageSupported languagesupported;


void BatterySpecification::BatterySpecificationPrinter()
{
	
	
	vector<string> batteryHeadingsPrinter{ languagesupported.status[{"W_status", LanguageSupported::language}],  string(20,' '),
								   languagesupported.status[{"B_status", LanguageSupported::language}],          string(20,' '),
								   languagesupported.status[{"B_current_voltage", LanguageSupported::language}], "\n",
								   languagesupported.status[{"Temp", LanguageSupported::language}],              string(24,' '),
								   languagesupported.status[{"B_Tmptr", LanguageSupported::language}],			 string(1, '|'),
								   languagesupported.status[{"low", LanguageSupported::language}],				 string(1, '|'),
								   languagesupported.status[{"full", LanguageSupported::language}],				 string(1, '|'),
								   languagesupported.status[{"actual", LanguageSupported::language}],			 string(12,' '),
								   languagesupported.status[{"C_Min", LanguageSupported::language}],			 string(1, '|'),
								   languagesupported.status[{"C_Max", LanguageSupported::language}],			 string(1, '|'),
								   languagesupported.status[{"Curr_actual", LanguageSupported::language}],		 string(3, ' '),
								   languagesupported.status[{"V_Min", LanguageSupported::language}],			 string(1, '|'),
								   languagesupported.status[{"V_Max", LanguageSupported::language}],			 string(1, '|'),
								   languagesupported.status[{"Volt_actual", LanguageSupported::language}]
								};
	for (const auto & print : batteryHeadingsPrinter)
	{
		cout << print.data();
	}
	cout << endl;
	cout<<weatherIndicator::todaysTemperature     << "`C" << setw(29) <<BatteryElements::temperature            << "`C" << setw(4) 
		<<StateOfChargeRate::lowBatteryStatus     << "%"  << setw(4)  << StateOfChargeRate::fullBatteryStatus   << "%"  << setw(4) 
		<<StatusOfCharge::currentBatteryStatus    << "%"  << setw(18) <<CurrentIndicator::currentMinThreshould  << "E"  << setw(5)  
		<<CurrentIndicator::currentMaxThreshould  << "E"  << setw(6)  <<BatteryElements::current                << "E"  << setw(12) 
		<<VoltageIndicator::voltageMinThreshould  << "V"  << setw(4)  <<VoltageIndicator::vOltageMaxThreshould  << "V"  << setw(6)  
		<<BatteryElements::voltage                << "V"  << endl;
			
}

bool CurrentIndicator::currentStatus()
{
	if (currentMinThreshould >= BatteryElements::current)
	{
		cout << languagesupported.status[{"LOW_CURRENT_BREACH", LanguageSupported::language}] << endl;
	}
	if (currentMaxThreshould <= BatteryElements::current)
	{
		cout << languagesupported.status[{"HIGH_CURRENT_BREACH", LanguageSupported::language}] << endl;
	}
	return true;
}

bool VoltageIndicator::voltageStatus()
{
	if (voltageMinThreshould >= BatteryElements::voltage)
	{
		cout << languagesupported.status[{"LOW_VOLTAGE_BREACH", LanguageSupported::language}] << endl;
	}
	if (vOltageMaxThreshould <= BatteryElements::voltage)
	{
		cout << languagesupported.status[{"HIGH_VOLTAGE_BREACH", LanguageSupported::language}] << endl;
	}
	return true;
}

bool TempratureIndicator::temperatureStatus()
{
	cout << "-------------------------------------------------"<< languagesupported.status[{"B_charging_rate", LanguageSupported::language}] <<"-------------------------------------------------------" << endl;
	
	if (temperatureMinThreshould >= BatteryElements::temperature)
	{
		cout << languagesupported.status[{"LOW_B_TEMP_BREACH", LanguageSupported::language}] << endl;
	}
	if (temperatureMaxThreshould <= BatteryElements::temperature)
	{
		cout << languagesupported.status[{"HIGH_B_TEMP_BREACH", LanguageSupported::language}] << endl;
	}
	return true;
}

int temperatureConvertToCelsius(string temp)
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

BatteryParameters::BatteryParameters(string temp, float vol, float curr)
{
	cout << "-------------------------------------------------"<< languagesupported.status[{"B_specification", LanguageSupported::language}]<<" ---------------------- ------------------" << endl;
	
	current = curr;
	voltage = vol;

	/*----temperature conversion----*/

	temperature = temperatureConvertToCelsius(temp);

	/*----temperature conversion----*/

	BatterySpecification Batteryspec;
	Batteryspec.BatterySpecificationPrinter();
}

bool weatherIndicator::weatherStatus(int todaysTemperature)
{
	cout << "-------------------------------------------------"<< languagesupported.status[{"W_condition", LanguageSupported::language}] <<" ---------------------------------------------" << endl;
	
	if (hotWeather < todaysTemperature)
	{
		cout << languagesupported.status[{"LOW_TEMP_BREACH", LanguageSupported::language}] << endl;
	}
	if (coldWeather > todaysTemperature)
	{
		cout << languagesupported.status[{"HIGH_TEMP_BREACH", LanguageSupported::language}] << endl;
	}
	return true;
}

bool StatusOfCharge::BatteryChargingStatus(int BatteryStatus)
{
		StatusOfCharge::currentBatteryStatus = BatteryStatus;
		cout << "-------------------------------------------------"<< languagesupported.status[{"B_SOC", LanguageSupported::language}]<<" --------------------------------------------------" << endl;
		
		if (currentBatteryStatus <= lowBatteryStatus)
		{
			cout << languagesupported.status[{"LOW_SOC_BREACH", LanguageSupported::language}] << endl;
			
		}
		if (currentBatteryStatus == fullBatteryStatus)
		{
			cout << languagesupported.status[{"HIGH_SOC_BREACH", LanguageSupported::language}] << endl;
		}
	
	return true;
}

void LanguageSupported::selectLanguage(string lang)
{
	language = lang;
	cout << "-------------------------------------------------"<< languagesupported.status[{"C_Language", LanguageSupported::language}]<< "--------------------------------------------------" << endl;
	cout << language << endl;
}