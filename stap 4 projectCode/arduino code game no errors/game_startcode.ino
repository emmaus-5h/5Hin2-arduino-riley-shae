/*****************************************
   Game Startcode
   met toestansdiagrammen
   Emmauscollege
   v20201114GEE
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
   variabelen die je gebruikt maken
 *****************************************/
// gebruikte pinnen
const int pinLedRood   = 12; // pin van LED rood
const int pinLedGeel   = 11; // pin van LED geel
const int pinLedGroen   = 10; // pin van LED groen
const int pinKnopBlauw = 6; // pin van knop blauw
const int pinKnopGroen  = 4; // pin van knop groen




// variabelen voor de toestanden
const int TELAF = 1; // tel af tot spel start
const int SPEEL = 2; // speel het spel
const int WIN   = 3; // laat zien wie de winnaar is
int toestand = TELAF;
unsigned long toestandStartTijd = 0;

const int rood = 3;
const int geel = 4;
const int groen = 5;


/*****************************************
   functies die je gebruikt maken
 *****************************************/
// code die steeds wordt uitgevoerd in toestand TELAF
void telafLoop() {
  // tel af
}

// code die steeds wordt uitgevoerd in toestand SPEEL
void speelLoop() {
  // speel spel
}

// code die steeds wordt uitgevoerd in toestand SPEEL
void winLoop() {
  // toon wie gewonnen heeft
}


/*****************************************
   setup() en loop()
 *****************************************/

void setup() {
  // enable console en stuur opstartbericht
  Serial.begin(9600);
  Serial.println("Game start");

  // zet pinmode voor leds
  pinMode(pinLedGroen, OUTPUT);
  pinMode(pinLedGeel, OUTPUT);
  pinMode(pinLedRood, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopBlauw, INPUT);
  pinMode(pinKnopGroen, INPUT);
}

void loop() {
  // lees sensorwaarden

  
  
  // bepaal toestand
  if (toestand == TELAF) {
    telafLoop();
    if (millis() - toestandStartTijd > 2000) { // 2 seconden voorbij
      toestandStartTijd = millis();
      toestand = SPEEL;
      Serial.println("Nieuwe toestand: SPEEL");
    }
  }
  if (toestand == SPEEL) {
    speelLoop();
    if (millis() - toestandStartTijd > 5000) { // 5 seconden voorbij
      toestandStartTijd = millis();
      toestand = WIN;
      Serial.println("Nieuwe toestand: WIN");
    }
  }
  if (toestand == WIN) {
    winLoop();
    if (millis() - toestandStartTijd > 1000 &&  // 1 seconde voorbij en
        pinKnopBlauw == HIGH && pinKnopGroen == HIGH) {       // beide knoppen ingedrukt
      toestandStartTijd = millis();
      toestand = TELAF;
      Serial.println("Nieuwe toestand: TELAF");
    }
  }

  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
