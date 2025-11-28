//variabili globali

#include <Adafruit_LiquidCrystal.h>// includo libreria
Adafruit_LiquidCrystal lcd_1(0);// assegno nome al mio display
int val_Adc = 0;// dichiaro le variabili0
float temp = 0;
void setup()
{
  //init seriale
  lcd_1.begin(16,2);
  // inizializzazione display
  
}
void loop()
{
  val_Adc = analogRead(0);              //leggo dalla porta A0
                                      //converto il segnale acquisito in un valore
                                       //espresso in gradi centigradi
  temp = ((val_Adc * 0.00488) - 0.5) / 0.01; //Calcolo ed attribuisco il dato 
                                            //temperatura
  lcd_1.setCursor(0,0);//posiziono il cursore
  lcd_1.print(temp);//stampo a video la variabile mappata
  lcd_1.print ("  °C"); //aggiungo un testo fisso
  delay(500);
  
}