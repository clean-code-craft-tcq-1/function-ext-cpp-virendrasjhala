#include <assert.h>
#include <iostream>
#include <vector>
#include "batteryInterface.h"
using namespace std;


int main() {

	/*-------------------------------------------input parameters----------------------------------------*/
	
	/*---------- temperature in Fahrenheit ----------*/
	string checkBatteryTemperature = "-10F"; 
	/*---------- temperature in Fahrenheit ----------*/

	int setTodaysTemperature = 100;
	int checkStatusofcharge  = 80;
	float checkBatteryVoltage  = 1;
	float checkBatteryCurrent  = 2;

	/*---------- select language ----------*/
	string language = "Gmn";
	/*---------- select language ----------*/

	/*-------------------------------------------input parameters----------------------------------------*/
	
	LanguageSupported languagesupported;
	languagesupported.selectLanguage(language);

	StatusOfCharge statusofbattery;
	assert(statusofbattery.BatteryChargingStatus(checkStatusofcharge) == true);
	
	weatherIndicator   weatherindicator;
	assert(weatherindicator.weatherStatus(setTodaysTemperature) == true);

	BatteryIndicator Batteryindicator(checkBatteryTemperature, checkBatteryVoltage, checkBatteryCurrent);

	TempratureIndicator T_Indicator;
	VoltageIndicator    V_Indicator;
	CurrentIndicator    C_Indicator;
	assert(T_Indicator.temperatureStatus() == true);
	assert(V_Indicator.voltageStatus()    == true);
	assert(C_Indicator.currentStatus()    == true);

	//system("pause");
}
