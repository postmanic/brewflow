// 
// 
// 

#include "Temperatures.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define One_Wire_Bus 3
OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&oneWire);

const DeviceAddress SENSOR_NR1 = { 0x28, 0x75, 0xE8, 0x26, 0x06, 0x00, 0x00, 0x21 };
const DeviceAddress SENSOR_NR2 = { 0x28, 0x75, 0xE8, 0x26, 0x06, 0x01, 0x00, 0x21 };

void Temperatures_init()
{
	sensors.begin();
	Temperatures_sensorCount();
	sensors.setResolution(SENSOR_NR1, 11);
	sensors.setResolution(SENSOR_NR2, 11);
}

void Temperatures_update(float arr[])
{

	sensors.requestTemperatures();
	arr[0] = sensors.getTempC(SENSOR_NR1);
	arr[1] = sensors.getTempC(SENSOR_NR2);
	arr[2] = (arr[0] + arr[1]) / 2;

}

int Temperatures_sensorCount()
{
	sensors.getDeviceCount(), DEC;
}


