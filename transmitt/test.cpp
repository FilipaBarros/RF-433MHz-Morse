#include <iostream>
#include <RH_ASK.h>
//ß#include <SPI.h> // Not actually used but needed to compile
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

RH_ASK driver(2000);

void setup()    //pins tx_pin=12
{
    Serial.begin(9600);   // Debugging only

    if (!driver.init())
         Serial.println("init failed");
    int operatingMode = 0;      //modes: English2Morse or Morse2English
    string latinPhrase;
    string morsePhrase;
    string latinAlphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',' };
    string morseAlphabet[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };
    string translatedMorsePhrase;
    int wordSearch = 0;

}

void loop()
{
    //const char *msg = "Hello World";
    const char *data;
        cout << endl << "Please select a mode of operation. " << endl << endl;
        cout << "Insert 1 for English to Morse"<< endl << "Insert 2 for Morse to English. " << endl;

        cin >> operatingMode;

        cout << endl << "Your mode of operation is " << operatingMode << endl;


        if (operatingMode == 1)
        {
            cout << "You have selected English to Morse." << endl;
            cout << endl << "Please enter the phrase you would like translated." << endl;

            cin.ignore();                                          // ignores everything previously in cin
            getline(cin, latinPhrase);                             // allows the user to insert full strings with spaces and special characters

            for(int i = 0; i < latinPhrase.length(); i++) {        // converts every char from lowercase to uppercase
                latinPhrase.at(i) = toupper(latinPhrase.at(i));
            }

            cout << "The translated phrase is: \t";
            for (unsigned i = 0; i<latinPhrase.length(); ++i)       //every char of the string
            {
                for (int counter = 0; counter < 30; counter++)      //is translated to the respective morse code
                {
                        if (latinPhrase.at(i) == latinAlphabet[counter])
                        {
                            cout << morseAlphabet[counter];
                            data = morseAlphabet[counter];
                            driver.send((uint8_t *)data, strlen(data));
                            driver.waitPacketSent();
                            delay(1000);
                            break;
                        }
                }
            }
             cout << "\t stop" << endl;
        }
}
