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
const int pinLedRood   = 12; // pin van LED rood
const int pinLedGeel   = 11; // pin van LED geel
const int pinLedGroen  = 0; // pin van led groen
const int pinKnopBlauw  = 6; // pin van knop blauw
const int pinKnopGroen = 4; // pin van knop groen

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
  pinMode(pinLedRood, OUTPUT);
  pinMode(pinLedGeel, OUTPUT);
  pinMode(pinLedGroen, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopBlauw, INPUT);
  pinMode(pinKnopGroen, INPUT);

  // zet LEDs aan
  digitalWrite(pinLedRood, HIGH);
  digitalWrite(pinLedGeel, HIGH);
  digitalWrite(pinLedGroen, HIGH);

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
  // zet LedRood aan/uit afhankelijk van stand van knopBlauw
  if (digitalRead(pinKnopBlauw) == LOW) {
    digitalWrite(pinLedRood, LOW);
  } else {
    digitalWrite(pinLedRood, HIGH);
  }

  // zet LedGeel en LedGroen aan/uit afhankelijk van stand van knopGroen
  if (digitalRead(pinKnopGroen) == LOW) {
    digitalWrite(pinLedGeel&&pinLedGroen, LOW);
  } else {
    digitalWrite(pinLedGeel&&pinLedGroen, HIGH);
  }

  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
