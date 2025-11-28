// C++ code
//
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop()
{
  Serial.println(analogRead(A0));
  if (analogRead(A0) > 500) {
    digitalWrite(4, LOW);
  } else {
    digitalWrite(4, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}