#include <LiquidCrystal_I2C.h>
#define relay_pin 13  //definisce il pin 13 per sollecitare il relè
#define pot_temp A0 //definisce il pin A0 per il potenziometro
#define tmp36 A1 //definisce il pin A1 per il sensore di temperatura


LiquidCrystal_I2C lcd(32, 16, 2);

int temperatura = 0;
int target = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.display();
  pinMode(relay_pin, OUTPUT);
  lcd.clear();
}

void loop()
{
  target = analogRead(pot_temp); //lettura potenziometro per settare temperatura target collegato al pin A0
  temperatura = analogRead(tmp36); //lettura sonda TMP36 collegata al pin A1
  target = map(target,0,1024,-40,125); //mappatura potenziometro per settare range di temperatura
  temperatura = ((temperatura * 0.00488) - 0.5) / 0.01; //conversione valore tmp36 in gradi celsius
  lcd_status();
  relay_status();
  delay(50);
}

void relay_status()
{
  if ( target < temperatura ){
    digitalWrite(relay_pin, HIGH);
  }
  else if( target >= temperatura ){
    digitalWrite(relay_pin, LOW);
  }
  else{
    digitalWrite(relay_pin, LOW);
  }
}

void lcd_status()
{
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.setCursor(13,0);
  lcd.print(temperatura);
  lcd.print("   ");
  lcd.setCursor(0,1);
  lcd.print("Temp Target: ");
  lcd.setCursor(13,1);
  lcd.print(target);
  lcd.print("   ");
}