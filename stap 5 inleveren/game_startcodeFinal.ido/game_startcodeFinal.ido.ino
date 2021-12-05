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

// Er was een probleem met optellen, want de arduino bleef doortellen ookal was die ingedrukt omdat de knop aleen op HIGH of LOW kan dus met de bool kan je wel apart optellen. ( met behulp van Riley's vader en khan academy. Alles met de bool is duidelijk uitgelegt.)
bool isPressed = false; 


// variabelen voor de toestanden
const int TELAF = 1; // tel af tot spel start
const int BEGIN = 2; // speel het spel
const int END   = 3; // laat zien wie de winnaar is
const int RED1 = 4; // led aftellen voor rood
const int YELLOW1 = 5; // led aftellen voor geel
const int GREEN1 = 6; // led aftellen voor groen 

rgb_lcd lcd = rgb_lcd(); // definitie van lcd

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
      if (digitalRead(pinKnopBegin)==HIGH) {
        toestandStartTijd = millis();
        toestand = RED1;
        Serial.println("Nieuwe toestand: RED1");
        // lcd berichten 
        lcd.clear();
        lcd.begin(16,2);
        lcd.print("3");
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
        lcd.clear();
        lcd.begin(16,2);
        lcd.print("2");
        
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
        lcd.clear();
        lcd.begin(16,2);
        lcd.print("1");
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
        spelerPunten = 0;
        Serial.println("Nieuwe toestand: BEGIN");  
        // lcd berichten 
        lcd.clear();
        lcd.begin(16,2);
        lcd.print("Begin met tikken");
    }
  }
  // Begin van het tikken 
   if (toestand == BEGIN) {
    digitalWrite(pinLedRood, LOW);
    digitalWrite(pinLedGeel, LOW);
    digitalWrite(pinLedGroen, LOW);

    // Punten optellen van de speler 
    if(digitalRead(pinKnopSpeler)==HIGH) { // checken of de knop is ingedrukt 
      isPressed = true;
    }
    
    if(digitalRead(pinKnopSpeler)==LOW) { // checken of de knop is ingedrukt en vervolgens weer losgelaten
      if(isPressed){
      isPressed=false;
      spelerPunten = spelerPunten + 1;  // <-- voor optellen
         // lcd berichten 
         lcd.clear();
         lcd.begin(16,2);
         lcd.print("Punten=" + String(spelerPunten)); // punten met String();
      }
    }
    
    // tijdsduur van het spel 
    if (millis() - toestandStartTijd > 10000) {
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
          // lcd berichten 
          lcd.clear();
          lcd.begin(16,2);
          lcd.print("Totaal=" + String(spelerPunten));
      }
   }

  // kleine vertraging, 100 keer per seconde loopen is genoeg
  delay(10);
}

// commentaar Vader van Riley : maak functies van de code, het is moeilijk te zien. :[
