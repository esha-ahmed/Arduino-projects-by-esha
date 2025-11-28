// C++ code
//
int piezo = 0;

void setup()
{
  pinMode(7, INPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  Meow = digitalRead(7);
  if (piezo == 0) {
    tone(3, 523, 1000); // play tone 60 (C5 = 523 Hz)
  } else {
    noTone(3);
  }
  delay(10); // Delay a little bit to improve simulation performance
}