// C++ code
//
#include <Adafruit_LiquidCrystal.h>// include la libreria di controllo del display


int sensorValue =A0; // definisce la variabile  della sonda di livello da leggere sul pin analogico A0
int x=sensorValue; // definisce la variabile X 

Adafruit_LiquidCrystal lcd_1(0);// assegna il nome al display
void setup()
{
  pinMode(A0, INPUT);// assegna al pin analogico la modalità di ingresso dati
  lcd_1.begin(16, 2);// inizializza il display
 
}

void loop()
{
  sensorValue = analogRead(A0);// assegna alla variabile del sensore il valore del pin analogico
  delay(5);
  int val=analogRead(A0);//definisce la variabile val come il valore analogico letto sul pin A0
  
  x=map(val,0,876,0,100);// esegue lo scaling della variabile da bit a % 
  
  analogWrite(9,val);//scrive sul pin 9 il valore della lettura analogica
  
  lcd_1.setCursor(0,0); //posiziona il cursore per la scrittura

  lcd_1.print(x);// stampa a video la nostra variabile X
  lcd_1.print("% riempimento");// stampa il testo desiderato
  
  
  delay(50);
  
  
  

}