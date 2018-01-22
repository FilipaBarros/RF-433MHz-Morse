#include "insertmodes.h"

RH_ASK driver(2000);

String latinPhrase;
String morsePhrase;
//String latinAlphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',' };
char latinAlphabet[30] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',' };
String morseAlphabet[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };
String translatedMorsePhrase;
char latinCharacter;
int wordSearch = 0;

void RF433init(){
  if (!driver.init())
       Serial.println("init failed");
}

void modeEngtoMorse()
{
    Serial.println("You have selected English to Morse.");
    Serial.println("Please enter the phrase you would like translated.");

    //cin.ignore();                                          // ignores everything previously in cin
    //getline(cin, latinPhrase);                             // allows the user to insert full strings with spaces and special characters
    while(!Serial.available());
    while(latinCharacter != '\n')
    {
      while(!Serial.available());
      latinCharacter = Serial.read();       //converts string to char
      if(latinCharacter == '\n')
        break;
      latinPhrase += latinCharacter;
    }

    Serial.print(latinPhrase);

    for(int i = 0; i < latinPhrase.length(); i++) {        // converts every char from lowercase to uppercase
        latinPhrase[i] = toupper(latinPhrase[i]);
    }

    Serial.print("The translated phrase is: \t");
    for (unsigned i = 0; i<latinPhrase.length(); ++i)       //every char of the string
    {
        for (int counter = 0; counter < 30; counter++)      //is translated to the respective morse code
        {
                if (latinPhrase[i] == latinAlphabet[counter])
                {
                    Serial.print(morseAlphabet[counter]);
                   for(unsigned j=0; j < morseAlphabet[counter].length(); j++)
                    {
                      //Serial.println("started send instruction");
                      Serial.print("antes");
                      driver.send((uint8_t *)&morseAlphabet[counter][j], 1);
                      //Serial.println("finished send instruction");
                      //Serial.println("wait for pakcket to be sent");
                      Serial.print("depois");
                      driver.waitPacketSent();
                      //Serial.println("packet sent");
                      delay(1000);
                    }
                    break;
                }
        }
    }
    latinPhrase = "";
    latinCharacter = NULL;
    Serial.println("\t stop");
}
