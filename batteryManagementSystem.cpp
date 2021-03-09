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

	int setTodaysTemperature = -60;
	int checkStatusofcharge  = 80;
	float checkBatteryVoltage  = 1;
	float checkBatteryCurrent  = 1.0;
	/*-------------------------------------------input parameters----------------------------------------*/

	cout << "-------------------------------------------------Battery StateOfCharge(SOC) --------------------------------------------------" << endl;
	StatusOfCharge statusofbattery;
	assert(statusofbattery.BatteryChargingStatus(checkStatusofcharge) == true);
	
	cout << "-------------------------------------------------Weather condition -----------------------------------------------------------" << endl;

	weatherIndicator   weatherindicator;
	assert(weatherindicator.weatherStatus(setTodaysTemperature) == true);

	cout << "-------------------------------------------------Battery specification -------------------------------------------------------" << endl;
	BatteryIndicator Batteryindicator(checkBatteryTemperature, checkBatteryVoltage, checkBatteryCurrent);

	cout << "-------------------------------------------------Battery charging rate -------------------------------------------------------" << endl;
	TempratureIndicator T_Indicator;
	VoltageIndicator    V_Indicator;
	CurrentIndicator    C_Indicator;
	assert(T_Indicator.tempratureStatus() == true);
	assert(V_Indicator.voltageStatus()    == true);
	assert(C_Indicator.currentStatus()    == true);

	//system("pause");
}
