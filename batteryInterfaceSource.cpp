#pragma once
#include <assert.h>
#include <iostream>
#include "batteryInterface.h"
#include <iomanip>
#include <map>
#include <sstream>  

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

void BatterySpecification::BatterySpecificationPrinter()
{
	cout << "    || "<< database::status[{"W_status", LanguageSupported::language}]<<"|| " << "           ||"<< database::status[{"B_status", LanguageSupported::language}]<<"|| " << "                         ||"<< database::status[{"B_current_voltage", LanguageSupported::language}] <<"||" << endl;
	cout << ""      << database::status[{"Temp", LanguageSupported::language}]    <<"       "     <<"                        "<< database::status[{"B_Tmptr", LanguageSupported::language}] <<"| "<<""<< database::status[{"low", LanguageSupported::language}] <<"| "<< ""<< database::status[{"full", LanguageSupported::language}]
		 <<"| "<< ""<< database::status[{"actual", LanguageSupported::language}]<<"| "<<   "      "<< database::status[{"C_Min", LanguageSupported::language}]<<"| "<<""<< database::status[{"C_Max", LanguageSupported::language}]<<"| "<<""<< database::status[{"Curr_actual", LanguageSupported::language}] <<"| "<<""
		 << database::status[{"V_Min", LanguageSupported::language}]<<"| "<<""<< database::status[{"V_Max", LanguageSupported::language}]<<"| "<<""<< database::status[{"Volt_actual", LanguageSupported::language}]<<"| "<<endl;

	cout << weatherIndicator::todaysTemperature     <<"`C"   << setw(33)   << BatteryElements::temperature <<"`C" <<"    "    << StateOfChargeRate::lowBatteryStatus <<"%"<<"   "
		 << StateOfChargeRate::fullBatteryStatus <<"%"    <<"   "        << StatusOfCharge::currentBatteryStatus <<"%"  << setw(14) << CurrentIndicator::currentMinThreshould <<"E"
		 << "   "  << CurrentIndicator::currentMaxThreshould <<"E"<<"      "<< BatteryElements::current              <<"E"  << setw(9) 
		 << VoltageIndicator::voltageMinThreshould  <<"V"    << setw(7)     << VoltageIndicator::vOltageMaxThreshould <<"V" <<"      "  << BatteryElements::voltage               <<"V"<<endl;
}

bool CurrentIndicator::currentStatus()
{
	if (currentMinThreshould >= BatteryElements::current)
	{
		cout << database::status[{"LOW_CURRENT_BREACH", LanguageSupported::language}] << endl;
	}
	if (currentMaxThreshould <= BatteryElements::current)
	{
		cout << database::status[{"HIGH_CURRENT_BREACH", LanguageSupported::language}] << endl;
	}
	return true;
}

bool VoltageIndicator::voltageStatus()
{
	if (voltageMinThreshould >= BatteryElements::voltage)
	{
		cout << database::status[{"LOW_VOLTAGE_BREACH", LanguageSupported::language}] << endl;
	}
	if (vOltageMaxThreshould <= BatteryElements::voltage)
	{
		cout << database::status[{"HIGH_VOLTAGE_BREACH", LanguageSupported::language}] << endl;
	}
	return true;
}

bool TempratureIndicator::temperatureStatus()
{
	cout << "-------------------------------------------------"<< database::status[{"B_charging_rate", LanguageSupported::language}] <<" -------------------------------------------------------" << endl;
	
	if (temperatureMinThreshould >= BatteryElements::temperature)
	{
		cout << database::status[{"LOW_B_TEMP_BREACH", LanguageSupported::language}] << endl;
	}
	if (temperatureMaxThreshould <= BatteryElements::temperature)
	{
		cout << database::status[{"HIGH_B_TEMP_BREACH", LanguageSupported::language}] << endl;
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
	cout << "-------------------------------------------------"<< database::status[{"B_specification", LanguageSupported::language}]<<" -------------------------------------------------------" << endl;
	
	current = curr;
	voltage = vol;

	/*----temperature conversion----*/

	temperature = temperatureConversion(temp);

	/*----temperature conversion----*/

	BatterySpecification Batteryspec;
	Batteryspec.BatterySpecificationPrinter();
}

bool weatherIndicator::weatherStatus(int todaysTemperature)
{
	cout << "-------------------------------------------------"<< database::status[{"W_condition", LanguageSupported::language}] <<" ---------------------------------------------" << endl;
	
	if (hotWeather < todaysTemperature)
	{
		cout << database::status[{"LOW_TEMP_BREACH", LanguageSupported::language}] << endl;
	}
	if (coldWeather > todaysTemperature)
	{
		cout << database::status[{"HIGH_TEMP_BREACH", LanguageSupported::language}] << endl;
	}
	return true;
}

bool StatusOfCharge::BatteryChargingStatus(int BatteryStatus)
{
		StatusOfCharge::currentBatteryStatus = BatteryStatus;
		cout << "-------------------------------------------------"<< database::status[{"B_SOC", LanguageSupported::language}]<<" --------------------------------------------------" << endl;
		
		if (currentBatteryStatus <= lowBatteryStatus)
		{
			cout << database::status[{"LOW_SOC_BREACH", LanguageSupported::language}] << endl;
			
		}
		if (currentBatteryStatus == fullBatteryStatus)
		{
			cout << database::status[{"HIGH_SOC_BREACH", LanguageSupported::language}] << endl;
		}
	
	return true;
}
void LanguageSupported::selectLanguage(string lang)
{
	language = lang;
	cout << "-------------------------------------------------"<< database::status[{"C_Language", LanguageSupported::language}]<< "--------------------------------------------------" << endl;
	cout << language << endl;
}