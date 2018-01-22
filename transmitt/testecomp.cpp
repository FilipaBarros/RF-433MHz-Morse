#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;


int main()
{
    int operatingMode = 0;      //modes: English2Morse or Morse2English
    string latinPhrase;
    string morsePhrase;
    string latinAlphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',' };
    string morseAlphabet[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };
    string translatedMorsePhrase;
    int wordSearch = 0;


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
                        break;
                    }
            }
        }
         cout << "\t stop" << endl;
    }

    if (operatingMode == 2)
    {
        cout << "You have selected Morse to English." << endl;
        cout << endl << "Please enter the phrase you would like translated." << endl;

        cin.ignore();                                          // ignores everything previously in cin
        getline(cin, morsePhrase);                             // allows the user to insert full strings with spaces and special characters

        for(int i = 0; i < morsePhrase.length(); i++) {        // converts every char from lowercase to uppercase
            morsePhrase.at(i) = toupper(morsePhrase.at(i)); 
        }

        cout << "The translated phrase is: \t";
        for (unsigned i = 0; i<morsePhrase.length(); ++i)       //every char of the string
        {
            for (int counter = 0; counter < 30; counter++)      //is translated to the respective morse code 
            {
                    if (morsePhrase.c_str(i) == morseAlphabet[counter])    ////// AQUIIIIII PROBLEMMMMMMMM
                    {
                        cout << latinAlphabet[counter];
                        break;
                    }
            }
        }
         cout << "\t stop" << endl;
    }    

    return 0;
}