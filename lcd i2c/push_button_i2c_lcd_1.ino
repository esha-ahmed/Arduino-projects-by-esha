#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display 
const int button = 13; 
int count = 0;

bool buttonState = HIGH;
bool lastButtonState = HIGH;
bool displayNo1 = false;

void setup() {
  pinMode(button, INPUT_PULLUP); // Use internal pull-up resistor
  
  Serial.begin(9600);

  lcd.init();
  lcd.clear();
  lcd.backlight(); 
}

void loop() {
  buttonState = digitalRead(button);

  if (buttonState == LOW && lastButtonState == HIGH) {
    displayNo1 = !displayNo1;
    if (count >=10){ // If the count is greater than 10
      count = 0; // Reset the count
    }
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("Count: "); // Print the label
    lcd.print(count); // Print the count
    delay(10); // Debounce delay
  }

  lastButtonState = buttonState;
}
