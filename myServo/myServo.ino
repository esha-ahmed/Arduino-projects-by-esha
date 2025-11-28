#include <Servo.h>       // includi libreria servo
Servo myServo;           // create servo object called myServo

// name pins 
const int onButtonPin = 3;
const int servoPin = 11; 

// dichiara variabile
int wiperState = 0;

void setup() {
  // dichiara pin input e output
  pinMode(onButtonPin,INPUT);
  myServo.attach(servoPin);
 
  // apri una serial connection 
  Serial.begin(9600);
  myServo.write(0);
}

void loop () {
  // cambia wiperstate se il bottone è premuto
  if (digitalRead(onButtonPin) == HIGH) {
    wiperState = wiperState + 1;
    if (wipwrState >= 2) {wiperState = 0;}
    
