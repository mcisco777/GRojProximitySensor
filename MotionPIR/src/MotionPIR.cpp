/* 
 * Project Motion PIR tester
 * Author: Mario Cisneros
 * Date: 3/5/2026
 */

#include "Particle.h"
#include <Encoder.h>

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

const int RLEDPIN = D5;
int inputPin = D2;
int pirState = LOW;
int val = 0;

// setup() runs once, when the device is first turned on
void setup() {
  pinMode(RLEDPIN, OUTPUT);
  pinMode(inputPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);
  if (pirState == HIGH){
    digitalWrite(RLEDPIN, HIGH);
    if (pirState == LOW){
    Serial.printf("Motion detected!");
    pirState = HIGH;
  }
}
  else{
    digitalWrite(RLEDPIN, LOW);
    if (pirState == HIGH){
      Serial.printf("Motion ended!");
      pirState = LOW;
    }
  }
}
