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

float BatteryElements::temperature;
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
double weatherIndicator::todaysTemperature;
float weatherIndicator::hotWeather  = 70;
float weatherIndicator::coldWeather = -50;

string LanguageSupported::language;
LanguageSupported languagesupported;

vector<string> B_spec;


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
		<<StateOfChargeRate::lowBatteryStatus     << "%"  << setw(4)  <<StateOfChargeRate::fullBatteryStatus    << "%"  << setw(4) 
		<<StatusOfCharge::currentBatteryStatus    << "%"  << setw(18) <<CurrentIndicator::currentMinThreshould  << "E"  << setw(5)  
		<<CurrentIndicator::currentMaxThreshould  << "E"  << setw(6)  <<BatteryElements::current                << "E"  << setw(12) 
		<<VoltageIndicator::voltageMinThreshould  << "V"  << setw(4)  <<VoltageIndicator::vOltageMaxThreshould  << "V"  << setw(6)  
		<<BatteryElements::voltage                << "V"  << endl;
			
}

bool BatterySpecification::batteryErrorPrinter() 
{
	cout << "-------"  << languagesupported.status[{"B_SOC", LanguageSupported::language }]           << "/"
		 << "-------"  << languagesupported.status[{"W_condition", LanguageSupported::language }]     << "/"
		 << "-------"  << languagesupported.status[{"B_charging_rate", LanguageSupported::language }] 
		 << "-------"  << endl;
	if (B_spec.empty())
	{
		return true;
	}
	else
	{
		for (const auto & printError : B_spec)
		{
			cout << printError.data()<<endl;
		}
		return true;
	}

}

void BatterySpecification::BatteryParametersCheck(string parameterStatus1, string parameterStatus2, double actualValue, double minValue, double MaxVAlue)
{
	
	if (minValue >= actualValue)
	{
		B_spec.push_back(languagesupported.status[{parameterStatus1, LanguageSupported::language }]);
	}
	if (MaxVAlue <= actualValue)
	{
		B_spec.push_back(languagesupported.status[{parameterStatus2, LanguageSupported::language }]);
	}
	
}

void CurrentIndicator::currentStatus()
{
	BatterySpecification B_PCheck;
	B_PCheck.BatteryParametersCheck("LOW_CURRENT_BREACH","HIGH_CURRENT_BREACH", BatteryElements::current, currentMinThreshould, currentMaxThreshould);

}

void VoltageIndicator::voltageStatus()
{
	BatterySpecification B_PCheck;
	B_PCheck.BatteryParametersCheck("LOW_VOLTAGE_BREACH","HIGH_VOLTAGE_BREACH", BatteryElements::voltage, voltageMinThreshould, vOltageMaxThreshould);
	
}

void TempratureIndicator::temperatureStatus()
{
	BatterySpecification B_PCheck;
	B_PCheck.BatteryParametersCheck("LOW_B_TEMP_BREACH","HIGH_B_TEMP_BREACH", BatteryElements::temperature, temperatureMinThreshould, temperatureMaxThreshould);

}

float temperatureConvertToCelsius(string temp)
{
	float measurement;
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

void BatteryParameters::Batteryparameters(string temp, float vol, float curr)
{
	cout << "-------------------------------------------------" << languagesupported.status[{"B_specification", LanguageSupported::language }] << " ---------------------- ------------------" << endl;
	
	current = curr;
	voltage = vol;

	/*----temperature conversion----*/

	temperature = temperatureConvertToCelsius(temp);

	/*----temperature conversion----*/

	BatterySpecification Batteryspec;
	Batteryspec.BatterySpecificationPrinter();
}

void weatherIndicator::weatherStatus(string today_Temperature)
{
	weatherIndicator::todaysTemperature =temperatureConvertToCelsius(today_Temperature);
	BatterySpecification B_PCheck;
	B_PCheck.BatteryParametersCheck("LOW_TEMP_BREACH","HIGH_TEMP_BREACH", todaysTemperature, coldWeather, hotWeather);
}

void StatusOfCharge::BatteryChargingStatus(int BatteryStatus)
{	
	currentBatteryStatus = BatteryStatus;
	BatterySpecification B_PCheck;
	B_PCheck.BatteryParametersCheck("LOW_SOC_BREACH","HIGH_SOC_BREACH", currentBatteryStatus, lowBatteryStatus, fullBatteryStatus);
}

void LanguageSupported::selectLanguage(string lang)
{
	language = lang;
	cout << "-------------------------------------------------" << languagesupported.status[{"C_Language", LanguageSupported::language }] << "--------------------------------------------------" << endl;
	cout << language << endl;
}