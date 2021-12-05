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
const int pinKnopBegin = 6; // pin van knop blauw
const int pinKnopSpeler  = 4; // pin van knop groen

// punten van de speler
int spelerPunten = 0;


// variabelen voor de toestanden
const int TELAF = 1; // tel af tot spel start
const int BEGIN = 2; // speel het spel
const int END   = 3; // laat zien wie de winnaar is
const int RED1 = 4; // led aftellen voor rood
const int YELLOW1 = 5; // led aftellen voor geel
const int GREEN1 = 6; // led aftellen voor groen 

// begin van ledjes die het spel gaan starten
int toestand = TELAF;

unsigned long toestandStartTijd = 0;
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
  pinMode(pinKnopBegin, INPUT);
  pinMode(pinKnopSpeler, INPUT);
}

void loop() {
  // Begin van het spel
 
   if (toestand == TELAF) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, LOW);
      if (digitalRead(pinKnopBegin)==LOW) {
        toestandStartTijd = millis();
        toestand = RED1;
      Serial.println("Nieuwe toestand: RED1");
    }
  }
// begin van de countdown tot het begin van tikken. begint met rood Ledje
   if (toestand == RED1) {
    digitalWrite(pinLedRood, HIGH);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, LOW);
      if (millis() - toestandStartTijd > 1000) { // hoelang de rode pin aanblijft voordat de volgende toestand begint, in dit geval 1 seconde
        toestandStartTijd = millis();
        toestand = YELLOW1; // volgende toestand 
        Serial.println("Nieuwe toestand: YELLOW1");
    }
  }
  // 2de ledje dat aan gaat 
   if (toestand == YELLOW1) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, HIGH);
    digitalWrite(pinLedGroen, LOW);
      if (millis() - toestandStartTijd > 1000){ // hoelang de gele pin aanblijft
        toestandStartTijd = millis();
        toestand = GREEN1;
        Serial.println("Nieuwe toestand: GREEN1");
    } 
  }
  // laatste Ledje dat aan gaat
   if (toestand == GREEN1) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, HIGH);
      if (millis() - toestandStartTijd > 1000) {
        toestandStartTijd = millis();
        toestand = BEGIN;
        Serial.println("Nieuwe toestand: BEGIN");  
    }
  }
  // Begin van het tikken 
   if (toestand == BEGIN) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, LOW);

    // Punten optellen van de speler 
    if(digitalRead(pinKnopSpeler)==LOW) {
      spelerPunten = spelerPunten + 1;  // <-- voor optellen
    }
    
    // tijdsduur van het spel 
    if (millis() - toestandStartTijd > 15000) {
      toestandStartTijd = millis();
      toestand = END;
      Serial.println("Nieuwe toestand: END");
    }
  }
   if (toestand == END) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, LOW);
      if (digitalRead(pinKnopBegin)==LOW) {
        toestandStartTijd = millis();
        toestand = TELAF;
        Serial.println("Nieuwe toestand: TELAF");
      }
   }

  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}
