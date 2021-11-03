/*****************************************
   Voorbeeld TestCode
   Voor circuit met 2 leds en 2 knoppen
   en een display
   Breid de code zelf uit
   zodat je deze kunt gebruiken om te testen
   of alle componenten (nog) goed
   zijn aangesloten op je Arduino
   Emmauscollege
   v20210210GEE
 *****************************************/

/*****************************************
   libraries die je gebruikt 
   LCD met 2 regels van 16 karakters 
   (de RGB backlit kan niet van kleur worden veranderd)
   https://www.arduino.cc/reference/en/libraries/grove-lcd-rgb-backlight/
 *****************************************/
#include <Wire.h>
#include "rgb_lcd.h"

/*****************************************
   variabelen die je gebruikt
 *****************************************/
// gebruikte pinnen
const int pinLedA   = 12; // pin van LED A
const int pinLedB   = 11; // pin van LED B
const int pinLedC   = 10; // pin van LED C
const int pinKnopA  = 6; // pin van knop A
const int pinKnopB  = 4; // pin van knop B
const int pinKnopC  = 5; // pin van knop C

// display 
rgb_lcd lcd;

/*****************************************
   setup()
 *****************************************/
void setup() {
  // enable console en stuur opstartbericht
  Serial.begin(9600);
  Serial.println("Test start");

  // zet pinmode voor leds
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinLedC, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopA, INPUT);
  pinMode(pinKnopB, INPUT);
  pinMode(pinKnopC, INPUT);

  // zet LEDs aan
  digitalWrite(pinLedA, HIGH);
  digitalWrite(pinLedB, HIGH);
  digitalWrite(pinLedC, HIGH);

  // zet het aan kolommen en rijen van het LCD
  lcd.begin(16, 2);
  // Zet een bericht op het LDC
  lcd.print("hello, world!");
  
  // wacht seconde zodat je kunt zien dat de LEDs het doen en het display kunt aflezen
  delay(1000);
}

/*****************************************
   loop()
 *****************************************/
void loop() {
  // zet LedA aan/uit afhankelijk van stand van knopA
  if (digitalRead(pinKnopA) == LOW) {
    digitalWrite(pinLedA, LOW);
  } else {
    digitalWrite(pinLedA, HIGH);
  }

  // zet LedB aan/uit afhankelijk van stand van knopB
  if (digitalRead(pinKnopB) == LOW) {
    digitalWrite(pinLedB, LOW);
  } else {
    digitalWrite(pinLedB, HIGH);
  }

  // zet LedC aan/uit afhankelijk van stand van knopC
  if (digitalRead(pinKnopC) == LOW) {
    digitalWrite(pinLedC, LOW);
  } else {
    digitalWrite(pinLedC, HIGH);
  }
  
  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
