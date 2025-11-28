
//controllo semplice del servo con potenziometro
#include <Adafruit_LiquidCrystal.h>// include la libreria di controllo del displa
#include <Servo.h> //includi libreria per il controllo del servo
#define PIN_SERVO 9 // assegna  col comando define il pin del servo
#define PIN_POTENZIOMETRO A0 // assegna il pin del potenziometro
 
Servo servo;//da il nome al servo
Adafruit_LiquidCrystal lcd_1(0);// assegna il nome al display 
void setup(){
  servo.attach(PIN_SERVO);//inizializza il pin del servo
  lcd_1.begin(16, 2);// inizializza il display
}
 
void loop(){
  int input = analogRead(PIN_POTENZIOMETRO);// definisce la variabile input come lettura del pin analogico assegnato al potenziometro
  int angolo = map(input, 0, 1023, 0, 179);//effettua lo scaling della rotazione del servo da gradi sessagesimali a bit
  servo.write(angolo);//imposta il servo sui gradi mappati in bit
  lcd_1.setCursor(0,0); //posiziona il cursore per la scrittura
  lcd_1.print(angolo);// stampa a video la nostra variabile angolo
  lcd_1.print(" Gradi");// stampa il testo desiderato
  delay(20);
}