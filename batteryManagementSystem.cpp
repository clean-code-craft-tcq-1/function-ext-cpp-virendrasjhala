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
	float checkBatteryVoltage  = 4;
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
	BatteryParameters *batteryparameters;
	BatterySpecification satteryspecification;
	batteryparameters = &satteryspecification;
	batteryparameters->Batteryparameters(checkBatteryTemperature, checkBatteryVoltage, checkBatteryCurrent);

	/*-------------------------------------------battery errorPrinter--------------------------------------*/
	CurrentIndicator current_indicator;
	VoltageIndicator voltage_indicator;
	TempratureIndicator temprature_indicator;
	current_indicator.currentStatus();
	voltage_indicator.voltageStatus();
	temprature_indicator.temperatureStatus();
	BatterySpecification battery_error_printer;
	assert(battery_error_printer.batteryErrorPrinter() == true);

	
}
