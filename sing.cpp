#include <Arduino.h>
#include "songs.h"

#define melodyPin 8

void buzz(int targetPin, long frequency, long length)
{
  pinMode(targetPin, OUTPUT);
  // calculate the delay value between transitions
  // 1 second's worth of microseconds, divided by the frequency, then split in half since
  // there are two phases to each cycle
  long delayValue = (1000000 / frequency) / 2; 
  
  // calculate the number of cycles for proper timing
  // multiply frequency, which is really cycles per second, by the number of seconds to 
  // get the total number of cycles to produce
  long numCycles = frequency * length / 1000;

  for (long i=0; i < numCycles; i++) // for the calculated length of time...
  { 
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }

}

void sing(int s)
{      

	// iterate over the notes of the melody:
	int song = s;
	if(song==2)
	{
		Serial.println(" 'Underworld Theme'");
		int size = sizeUnderworld / sizeof(int);
		for (int thisNote = 0; thisNote < size; thisNote++)
		{
			// to calculate the note duration, take one second
			// divided by the note type.
			//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			int noteDuration = 1000 / underworldTempo[thisNote];

			buzz(melodyPin, underworldMelody[thisNote],noteDuration);

			 // to distinguish the notes, set a minimum time between them.
			 // the note's duration + 30% seems to work well:
			int pauseBetweenNotes = noteDuration * 1.30;
			delay(pauseBetweenNotes);

			 // stop the tone playing:
			buzz(melodyPin, 0,noteDuration);
		}
	} else {

		 Serial.println(" 'Mario Theme'");
		 int size = sizeMainTheme / sizeof(int);
		 for (int thisNote = 0; thisNote < size; thisNote++) {

				 // to calculate the note duration, take one second
				 // divided by the note type.
				 //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			 int noteDuration = 1000/mainThemeTempo[thisNote];

			 buzz(melodyPin, mainThemeMelody[thisNote],noteDuration);

				 // to distinguish the notes, set a minimum time between them.
				 // the note's duration + 30% seems to work well:
			 int pauseBetweenNotes = noteDuration * 1.30;
			 delay(pauseBetweenNotes);

				 // stop the tone playing:
			 buzz(melodyPin, 0,noteDuration);

		 }
	 }
}
