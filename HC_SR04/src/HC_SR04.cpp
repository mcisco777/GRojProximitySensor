/* 
 * Project HC_SR04 tester
 * Author: Mario Cisneros
 * Date: 3/5/2026
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include <Encoder.h>

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

const int TRIGPIN = D12;
const int ECHOPIN = D13;

const int RLEDPIN = D3;
const int GLEDPIN = D4;
const int BLEDPIN = D6;

float duration, distance;

void setup() {
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);
  digitalWrite(RLEDPIN, HIGH);
  digitalWrite(GLEDPIN, HIGH);
  digitalWrite(BLEDPIN, HIGH);

  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Serial.begin(9600);
  waitFor(Serial.isConnected, 3000);
}


void loop() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration*.0343)/2;
  Serial.printf("Distance: %f\n", distance);
  delay(100);
}
