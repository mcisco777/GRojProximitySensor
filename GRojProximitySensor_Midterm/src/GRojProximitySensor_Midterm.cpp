/* 
 * Project Garage Proximity Sensor
 * Author: Mario Cisneros
 * Date: 3/7/2026
 */

#include "Particle.h"
#include "IoTClassroom_CNM.h"
#include "neoPixel.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_BME280.h"
#include <Encoder.h>

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(DISABLED);

const int RLEDPIN = D3; // Encoder LED red
const int GLEDPIN = D4; // Encoder LED green
const int BLEDPIN = D6; // Encoder LED blue
const bool MOTIONPIN = D19; // Motion sensor data pin
int pirState = LOW;
int val;

int currentTime = millis();
int lastSecond;

void setup() {
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);
  pinMode(MOTIONPIN, INPUT); // Set PIR Motion pin as input
  val = 0;
  digitalWrite(RLEDPIN, HIGH); // Turn off encoder LED's
  digitalWrite(GLEDPIN, HIGH);
  digitalWrite(BLEDPIN, HIGH);
  Serial.begin(9600);  
  waitFor(Serial.isConnected, 1000);
  delay(100);
  WiFi.on();
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");
  WiFi.connect();
  while(WiFi.connecting()){
    //if((currentTime - lastSecond)>10){
      //lastSecond = millis();
      Serial.print(".");
    //}
  }
  Serial.printf("\n\n");
}


void loop() {
  val = digitalRead(MOTIONPIN);
  if(val == HIGH){
    digitalWrite(RLEDPIN, LOW);
    if(pirState == LOW){
      Serial.printf("Motion Detected!\n");
      pirState = HIGH;
    }
  }
  else{
    digitalWrite(RLEDPIN, HIGH);
    if(pirState == HIGH){
      Serial.printf("Motion ended\n");
      pirState = LOW;
    }
  }
}
