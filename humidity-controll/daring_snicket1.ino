#include <Servo.h>

#define HUMIDITY_PIN A0
#define SERVO_PIN 9

Servo servo_ahmed;

void setup() {
  servo_ahmed.attach(SERVO_PIN);
}

void loop() {
  int humidityValue = analogRead(HUMIDITY_PIN);
  int angle = map(humidityValue, 0, 1023, 0, 180);
  servo_ahmed.write(angle);
  delay(1000);

if (humidityValue < 550) {
  servo_ahmed.write(0);
} else if (humidityValue > 750) {
  servo_ahmed.write(180);
}

}