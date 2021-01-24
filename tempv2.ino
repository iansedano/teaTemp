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

	// While themometer gets up to temperature
	while (temp < 71) 
	{
		temp = getTemp();
	}

	// While water is cooling to 70 degrees
	while (temp > 70)
	{
		temp = getTemp();
	}
	
	// Once cooled, play song
	int s = rand() % 2 + 1; 
	sing(s);
} 

void loop(){}
