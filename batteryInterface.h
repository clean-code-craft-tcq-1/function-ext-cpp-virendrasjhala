#pragma once
#include <assert.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;


class BatteryElements
{
public:
	static float current;
	static float voltage;
	static int temperature;
};
class BatterySpecification:public BatteryElements
{
public:
	void BatterySpecificationPrinter();
	
	vector<string>batteryHeadingsPrinter;
	
};
class CurrentIndicator
{
public:
	static double currentMinThreshould;
	static double currentMaxThreshould;

	bool currentStatus();
	
};
class VoltageIndicator 
{
public:
	static float voltageMinThreshould;
	static float vOltageMaxThreshould;

	bool voltageStatus();
	
};
class TempratureIndicator 
{
public:
	static float temperatureMinThreshould;
	static float temperatureMaxThreshould;

	bool temperatureStatus();
	
};
class BatteryParameters :public BatteryElements
{
public:
	BatteryParameters() {}
	BatteryParameters(string temp, float vol, float curr);
	
};
class StateOfChargeRate
{
public:
	static int fullBatteryStatus;
	static int lowBatteryStatus;
	
	StateOfChargeRate() {}
};
class StatusOfCharge :public StateOfChargeRate
{
public:
	static int currentBatteryStatus;
	StatusOfCharge() {}
	bool BatteryChargingStatus(int BatteryStatus);
	
};
class weatherIndicator 
{
public:
	static float hotWeather;
	static float coldWeather;
	static float todaysTemperature;

	bool weatherStatus(int todaysTemperature);
};
class LanguageSupported
{
public:
	static string language;
	void selectLanguage(string lang);
	map<pair<string, string>, string > status{ { make_pair("LOW_SOC_BREACH","eng"),"Battery is critical !" },{ make_pair("HIGH_SOC_BREACH","eng"),     "Battery is full charged ! Please disconnect !" },
	{ make_pair("LOW_TEMP_BREACH","eng") ,    "Very Low weather Temperature!! charge is not allowed !" },    { make_pair("HIGH_TEMP_BREACH","eng"),    "Very high weather Temperature!! charge is not allowed !" },
	{ make_pair("LOW_CURRENT_BREACH","eng"),  "Charge current Rate is low !" },           { make_pair("HIGH_CURRENT_BREACH","eng"), "Charge current Rate is high !" },
	{ make_pair("LOW_VOLTAGE_BREACH","eng"),  "Charge voltage Rate is low !" },           { make_pair("HIGH_VOLTAGE_BREACH","eng"), "Charge voltage Rate is high !" },
	{ make_pair("LOW_B_TEMP_BREACH","eng"),   "Charge tamperature of battery is low !" }, { make_pair("HIGH_B_TEMP_BREACH","eng"),  "Charge tamperature of battery is high !" },
	{ make_pair("C_Language","eng"),          "Current Language" },                       { make_pair("B_SOC","eng"),               "Battery StateOfCharge(SOC)" },
	{ make_pair("W_condition","eng"),         "Weather condition" },                      { make_pair("B_specification","eng"),     "Battery specification" },
	{ make_pair("B_charging_rate","eng"),     "Battery charging rate" },

	{ make_pair("LOW_SOC_BREACH","Gmn"),      "Batterie ist kritisch !" },                                      { make_pair("HIGH_SOC_BREACH","Gmn"),     "Akku ist voll aufgeladen! Bitte trennen Sie die Verbindung !" },
	{ make_pair("LOW_TEMP_BREACH","Gmn") ,    "Sehr niedrige Wettertemperatur !! Aufladen ist nicht erlaubt!" },{ make_pair("HIGH_TEMP_BREACH","Gmn"),    "Sehr hohe Wettertemperatur !! Aufladen ist nicht erlaubt!" },
	{ make_pair("LOW_CURRENT_BREACH","Gmn"),  "Ladestromrate ist niedrig!" },                                   { make_pair("HIGH_CURRENT_BREACH","Gmn"), "Ladestromrate ist hoch!" },
	{ make_pair("LOW_VOLTAGE_BREACH","Gmn"),  "Ladespannungsrate ist niedrig!" },                               { make_pair("HIGH_VOLTAGE_BREACH","Gmn"), "Ladespannungsrate ist hoch!" },
	{ make_pair("LOW_B_TEMP_BREACH","Gmn"),   "Die Ladetemperatur des Akkus ist niedrig!" },                    { make_pair("HIGH_B_TEMP_BREACH","Gmn"),  "Die Ladetemperatur des Akkus ist hoch!" },
	{ make_pair("C_Language","Gmn"),          "Aktuelle Sprache" },                                             { make_pair("B_SOC","Gmn"),               "Batteriestatus der Ladung(SOC)" },
	{ make_pair("W_condition","Gmn"),         "Wetterlage" },                                                   { make_pair("B_specification","Gmn"),     "Batteriespezifikation" },
	{ make_pair("B_charging_rate","Gmn"),     "Batterieladegeschwindigkeit" },

	{ make_pair("W_status","eng"),            "Wheather status" },             { make_pair("B_status","eng"),        "Battery status" },
	{ make_pair("B_current_voltage","eng"),   "Battery current/voltage" },     { make_pair("Temp","eng"),            "Temp" },
	{ make_pair("B_Tmptr","eng"),             "B_Tmptr" },                     { make_pair("low","eng"),	            "low" },
	{ make_pair("full","eng"),				  "full" },                        { make_pair("actual","eng"),		    "actual" },
	{ make_pair("C_Min","eng"),			      "C_Min" },                       { make_pair("C_Max","eng"),			"C_Max" },
	{ make_pair("Curr_actual","eng"),		  "Curr_actual" },                 { make_pair("V_Min","eng"),		    "V_Min" },
	{ make_pair("V_Max","eng"),		          "V_Max" },                       { make_pair("Volt_actual","eng"),     "Volt_actual" },

	{ make_pair("W_status","Gmn"),            "Wetterstatus" },                { make_pair("B_status","Gmn"),      "Batteriestatus" },
	{ make_pair("B_current_voltage","Gmn"),   "Batteriestrom / -spannung" },   { make_pair("Temp","Gmn"),          "Temp" },
	{ make_pair("B_Tmptr","Gmn"),             "B_Tmptr" },                     { make_pair("low","Gmn"),	        "niedrig" },
	{ make_pair("full","Gmn"),				  "voll" },                        { make_pair("actual","Gmn"),        "tatsächlich" },
	{ make_pair("C_Min","Gmn"),			      "C_Mindest" },                   { make_pair("C_Max","Gmn"),	        "C_Max" },
	{ make_pair("Curr_actual","Gmn"),		  "C_tatsächlich" },               { make_pair("V_Min","Gmn"),		    "V_Mindest" },
	{ make_pair("V_Max","Gmn"),		          "V_Max" },                       { make_pair("Volt_actual","Gmn"),   "V_tatsächlich" },
	};
};

