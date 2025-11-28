// C++ code
//
#define LED 13
#define PHOTORESISTOR A1
#define BUZZER 8
#define TEMPERATURE_SENSOR A0

void setup(){
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  pinMode(PHOTORESISTOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(TEMPERATURE_SENSOR, INPUT);
  
}

void loop() {
  
  int V_temp = analogRead(A0);
  int C_temp = ((V_temp * 0.00488) - 0.5) / 0.01;
  
  if(C_temp > 30) {
    digitalWrite(BUZZER, HIGH);}
  else{
    digitalWrite(BUZZER, LOW);
      }
  
	int value = analogRead(A1);

   Serial.println("Analog  Value: ");
   Serial.println(value);
   
   if (value > 30) {
       digitalWrite(LED, LOW);
   } else {
       digitalWrite(LED,  HIGH);
   }
   
   delay(250);
}
    