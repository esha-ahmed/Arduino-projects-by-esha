int pinRelay = 2;
int pinButton = 3;

void setup()
{
  pinMode(pinRelay, OUTPUT);
  pinMode(pinButton, OUTPUT);
}

void loop()
{
  int valButton = digitalRead(pinButton);
  if(valButton==HIGH){
    digitalWrite(pinRelay, HIGH);
    delay(5000);
    }
  else{
    digitalWrite(pinRelay, LOW);
    }
}