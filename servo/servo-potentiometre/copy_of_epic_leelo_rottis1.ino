
//controllo semplice del servo con potenziometro

#include <Servo.h> //includi libreria per il controllo del servo
#define PIN_SERVO 9 // assegna  col comando define il pin del servo
#define PIN_POTENZIOMETRO A0 // assegna il pin del potenziometro
 
Servo servo;//da il nome al servo
 
void setup(){
  servo.attach(PIN_SERVO);//inizializza il pin del servo
}
 
void loop(){
  int input = analogRead(PIN_POTENZIOMETRO);// definisce la variabile input come lettura del pin analogico assegnato al potenziometro
  int angolo = map(input, 0, 1023, 0, 179);//effettua lo scaling della rotazione del servo da gradi sessagesimali a bit
  servo.write(angolo);//imposta il servo sui gradi mappati in bit
  delay(20);
}