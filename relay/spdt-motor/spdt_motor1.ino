#include <LiquidCrystal_I2C.h>
#define relay_pin 13  //definisce il pin 13 per sollecitare il relè
#define pot_temp A0 //definisce il pin A0 per il potenziometro
#define tmp36 A1 //definisce il pin A1 per il sensore di temperatura


// Define constants for the pins
const int motorPin = 3; // Motor connected to PWM pin 3
const int relayPin = 8; // SPDT Relay connected to pin 8
const int photoresistorPin = A0; // Photoresistor connected to analog pin A0

void setup() {
  // Set all pins as outputs
  pinMode(motorPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Set relay to normally open position
}

void loop() {
  // Read the value from the photoresistor
  int photoresistorValue = analogRead(photoresistorPin);

  // Map the photoresistor value to a motor speed range of 0-255
  int motorSpeed = map(photoresistorValue, 0, 1023, 0, 255);

  // Write the motor speed to the motor pin
  analogWrite(motorPin, motorSpeed);

  // Wait for a short period of time before reading the photoresistor again
  delay(100);
}