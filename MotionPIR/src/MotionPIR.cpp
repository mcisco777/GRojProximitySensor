/* 
 * Project Motion PIR tester
 * Author: Mario Cisneros
 * Date: 3/5/2026
 */

#include "Particle.h"
#include <Encoder.h>

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

const int RLEDPIN = D3;
const int GLEDPIN = D4;
const int BLEDPIN = D6;
int inputPin = D19;
int pirState = LOW;
int val = 0;

// setup() runs once, when the device is first turned on
void setup() {
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);
  digitalWrite(GLEDPIN, HIGH);
  digitalWrite(BLEDPIN, HIGH);
  pinMode(inputPin,INPUT);
  Serial.begin(9600);
  waitFor(Serial.isConnected, 3000);
  Serial.printf("Ready to go\n");
}

void loop() {
  val = digitalRead(inputPin);
  if(val == HIGH){
    digitalWrite(RLEDPIN, LOW);
    if (pirState == LOW){
      Serial.printf("Motion detected!\n");
    pirState = HIGH;
  }
}
  else{
    digitalWrite(RLEDPIN, HIGH);
    if (pirState == HIGH){
      Serial.printf("Motion ended!\n");
      pirState = LOW;
    }
  }
}
