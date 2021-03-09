#include <assert.h>
#include <iostream>
#include <vector>
#include "batteryInterface.h"
using namespace std;


int main() {

	/*-------------------------------------------input parameters----------------------------------------*/
	
	/*---------- temperature in Fahrenheit ----------*/
	string checkBatteryTemperature = "44C"; 
	/*---------- temperature in Fahrenheit ----------*/

	float setTodaysTemperature = 23;
	int   checkStatusofcharge  = 75;
	float checkBatteryVoltage  = 4;
	float checkBatteryCurrent  = 1.0;
	/*-------------------------------------------input parameters----------------------------------------*/

	/*--------------------------------------------weather status-----------------------------------------*/
	weatherIndicator WeatherHandler;
	WeatherHandler.TodaysTemperature(setTodaysTemperature);

	/*-------------------------------------------StatusOfCharge(soc)------------------------------------------*/
	StatusOfCharge statusofbattery;
	assert(statusofbattery.BatteryChargingStatus(checkStatusofcharge) == true);

	/*-------------------------------------------Weather status------------------------------------------*/
	StateOfChargeRate   battery_charging_check;
	assert(battery_charging_check.batteryRequirements_For_Charging() == true);

	/*---------------------------------------battery Charging rate conditions check---------------------------*/
	BatteryIndicator Batteryindicator(checkBatteryTemperature, checkBatteryVoltage, checkBatteryCurrent);
	TempratureIndicator T_Indicator;
	VoltageIndicator    V_Indicator;
	CurrentIndicator    C_Indicator;
	assert(T_Indicator.tempratureStatus() == true);
	assert(V_Indicator.voltageStatus()    == true);
	assert(C_Indicator.currentStatus()    == true);

	

	//system("pause");
}
