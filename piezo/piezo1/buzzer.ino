// C++ code

//name the pin used in the circuit
const int buzzerPin= 8;

//declare variables
int rate= 1;
void setup()
{
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  digitalWrite(buzzerPin, HIGH);
  delay(9000); // Wait for 1000 millisecond(s)
  digitalWrite(buzzerPin, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
