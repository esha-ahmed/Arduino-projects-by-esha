// C++ code
//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address and dimensions as needed

const int buttonPin = 2; // Button connected to pin 2
int buttonState = 0; // Variable to store the button state
int count = 0; // Variable to store the count
const int buzzer = 12; 
const int button = 13;

void setup() {
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with pull-up resistor
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP); // Use internal pull-up resistor
  Serial.begin(9600);
  lcd.backlight(); 
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state
  if (buttonState == LOW) { // If the button is pressed
    count++; // Increment the count
    if (count == 10) { // If the count is greater than 10
      count = 0; // Reset the count
      tone(buzzer, 1000);
    }
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("Count: "); // Print the label
    lcd.print(count); // Print the count
    noTone(buzzer);
  }
  delay(10); // Debounce delay
}