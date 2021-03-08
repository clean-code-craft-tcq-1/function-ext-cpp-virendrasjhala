#pragma once
#include <assert.h>
#include <iostream>
using namespace std;


class BatteryElements
{
public:
	static float current;
	static float voltage;
	static float temprature;
};
class BatterySpecification:public BatteryElements
{
public:
	void BatterySpecificationPrinter();
};
class CurrentIndicator
{
public:
	static float currentMinThreshould;
	static float currentMaxThreshould;
	static float currentWarning;
	static float currentMaxWarning;
	static float currentMinWarning;
	bool currentStatus();
	
};
class VoltageIndicator 
{
public:
	static float voltageMinThreshould;
	static float vOltageMaxThreshould;
	static float voltageWarning;
	static float voltageMaxWarning;
	static float voltageMinWarning;

	bool voltageStatus();
	
};
class TempratureIndicator 
{
public:
	static float temperatureMinThreshould;
	static float temperatureMaxThreshould;
	static float temperatureWarning;
	static float temperatureMinThreshouldWarning;
	static float temperatureMaxThreshouldWarning;

	bool tempratureStatus();
	
};
class BatteryIndicator :public BatteryElements
{
public:
	BatteryIndicator() {}
	BatteryIndicator(float temp, float vol, float curr);
	
};
class StateOfChargeRate
{
public:
	static int fullBatteryStatus;
	static int lowBatteryStatus;
	static int warningThreshould;
	static int lowBatteryStatusEarlyWarning;
	static int fullBatteryStatusEarlyWarning;
	StateOfChargeRate() {}
	bool batteryRequirements_For_Charging();
};
class StatusOfCharge :public StateOfChargeRate, public VoltageIndicator
{
public:
	static int currentBatteryStatus;
	StatusOfCharge() {}
	bool lowStatus(string checkFor);
	bool highStatus(string checkFor);
	bool BatteryChargingStatus(float remainBatteryStatus);
	
};
class weatherIndicator 
{
public:
	static float hotWeather;
	static float coldWeather;
	static float todaysTemperature;
	void TodaysTemperature(float temp);
	bool weatherStatus();
};
