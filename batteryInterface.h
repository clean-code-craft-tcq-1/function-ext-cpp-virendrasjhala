#pragma once
#include <assert.h>
#include <iostream>
using namespace std;


class BatteryElements
{
public:
	static float current;
	static float voltage;
	static int temprature;
};
class BatterySpecification:public BatteryElements
{
public:
	void BatterySpecificationPrinter();
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

	bool tempratureStatus();
	
};
class BatteryIndicator :public BatteryElements
{
public:
	BatteryIndicator() {}
	BatteryIndicator(string temp, float vol, float curr);
	
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
	bool warining();
};
class weatherIndicator 
{
public:
	static float hotWeather;
	static float coldWeather;
	static float todaysTemperature;

	bool weatherStatus(int todaysTemperature);
};
