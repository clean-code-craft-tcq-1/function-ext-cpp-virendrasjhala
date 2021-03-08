#include <assert.h>
#include <iostream>
#include <vector>
#include "batteryInterface.h"
using namespace std;


int main() {

	/*-------------------------------------------input parameters----------------------------------------*/
	float setTodaysTemperature    = 23;
	int   checkStatusofcharge     = 60;
	float checkBatteryTemperature = 21;
	float checkBatteryVoltage     = 4;
	float checkBatteryCurrent     = 1.0;
	/*-------------------------------------------input parameters----------------------------------------*/

	/*--------------------------------------------weather status-----------------------------------------*/
	weatherIndicator WeatherHandler;
	WeatherHandler.TodaysTemperature(setTodaysTemperature);

	/*-------------------------------------------StatusOfCharge(soc)------------------------------------------*/
	StatusOfCharge statusofbattery;
	assert(statusofbattery.BatteryChargingStatus(checkStatusofcharge) == true);

	/*---------------------------------------battery Charging rate conditions check---------------------------*/
	BatteryIndicator Batteryindicator(checkBatteryTemperature, checkBatteryVoltage, checkBatteryCurrent);
	StateOfChargeRate battery_charging_check;
	assert(battery_charging_check.batteryRequirements_For_Charging() == true);

	//system("pause");
}
