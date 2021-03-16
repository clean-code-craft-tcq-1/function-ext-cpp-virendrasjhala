#include <assert.h>
#include <iostream>
#include <vector>
#include "batteryInterface.h"
using namespace std;


int main() {

	/*-------------------------------------------input parameters----------------------------------------*/
	
	/*---------- temperature in Fahrenheit ----------*/
	string checkBatteryTemperature = "33F"; 
	/*---------- temperature in Fahrenheit ----------*/

	string setTodaysTemperature = "100C";
	int checkStatusofcharge  = 50;
	float checkBatteryVoltage  = 12;
	float checkBatteryCurrent  = 0.9;

	/*---------- select language ----------*/
	string language = "eng";
	/*---------- select language ----------*/

	/*-------------------------------------------input parameters----------------------------------------*/
	
	/*-------------------------------------------language selection--------------------------------------*/
	LanguageSupported languagesupported;
	languagesupported.selectLanguage(language);

	/*-------------------------------------------stateOfCharge(SOC)--------------------------------------*/
	StatusOfCharge statuscfcharge;
	statuscfcharge.BatteryChargingStatus(checkStatusofcharge);
	
	/*-------------------------------------------weather Condition---------------------------------------*/
	weatherIndicator   weatherindicator;
	weatherindicator.weatherStatus(setTodaysTemperature);

	/*-------------------------------------------battery requirements-------------------------------------*/
	BatteryParameters   *batteryparameters;
	BatterySpecification batteryspecification;
	batteryparameters = &batteryspecification;
	batteryparameters->Batteryparameters(checkBatteryTemperature, checkBatteryVoltage, checkBatteryCurrent);

	/*-------------------------------------------battery errorPrinter--------------------------------------*/
	CurrentIndicator    current_indicator;
	VoltageIndicator    voltage_indicator;
	TempratureIndicator temprature_indicator;
	current_indicator.currentStatus();
	voltage_indicator.voltageStatus();
	temprature_indicator.temperatureStatus();

	BatteryParameters *battery_parameter_error;
	BatterySpecification battery_error_printer;
	battery_parameter_error = &battery_error_printer;
	assert(battery_parameter_error->batteryErrorPrinter() == true);
	
}
