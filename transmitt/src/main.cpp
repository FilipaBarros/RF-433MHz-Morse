//#include <iostream>
#include "insertmodes.h"

using namespace std;

void setup()    //pins tx_pin=12
{
    Serial.begin(9600);   // Debugging only
    RF433init();
}

int operatingMode = 0;      //modes: English2Morse or Morse2English

void loop()
{
    //const char *msg = "Hello World";
        Serial.println("Please select a mode of operation.\n\nInsert 1 for English to Morse.\nInsert 2 for Morse to English.");

        while(!Serial.available());
        operatingMode = Serial.readString().toInt();

        Serial.printf("Your mode of operation is %d\n", operatingMode);


        if (operatingMode == 1)
        {
            modeEngtoMorse();
        }
}
