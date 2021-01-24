#include <Arduino.h>
#include <OneWire.h> 
#include <DallasTemperature.h>

#include <stdlib.h>

#include "pitches.h"
#include "sing.h"
#include "temp.h"


void setup() 
{ 
	Serial.begin(9600); 

	initTemp();

	int temp = getTemp();
	Serial.print("Starting temp is: ");
	Serial.println(temp);

	// While themometer gets up to temperature
	while (temp < 71) 
	{
		temp = getTemp();
		Serial.print("Getting up to temp: ");
		Serial.println(temp);
	}

	// While water is cooling to 70 degrees
	while (temp > 70)
	{
		temp = getTemp();
		Serial.print("Cooling: ");
		Serial.println(temp);
	}
	
	// Once cooled, play song

	for (int i=0; i<10; i++)
	{
		Serial.println(rand() % 2 + 1);
	}

	int s = rand() % 2 + 1;

	while(true)
	{
		sing(s);
	}
	
} 

void loop(){}
