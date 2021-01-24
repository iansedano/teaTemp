#include <OneWire.h> 
#include <DallasTemperature.h>


OneWire oneWire(2);
DallasTemperature sensors(&oneWire);

void initTemp(){
	sensors.begin();
}

int getTemp()
{
	sensors.requestTemperatures();
	int temp = sensors.getTempCByIndex(0);
	return temp;
}
