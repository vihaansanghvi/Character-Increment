#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the LCD I2C address as needed

const int buttonPin = 2; // The pin that the pushbutton is attached to
int lastButtonState = HIGH; // The previous state of the button
char currentChar = 'A'; // Starting character

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Initialize the pushbutton pin as an input with an internal pull-up resistor
  lcd.init(); // Initialize the LCD (for some libraries, use lcd.begin(16, 2);)
  lcd.backlight(); // Turn on the backlight
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Check if the button is pressed and the button state has changed
  if (buttonState == LOW && lastButtonState == HIGH) {
    lcd.clear(); // Clear the LCD
    lcd.print(currentChar); // Display the current character

    // Increment the character. Reset to 'A' after 'Z'.
    currentChar++;
    if (currentChar > 'Z') {
      currentChar = 'A';
    }

    delay(250); // Debounce delay
  }
  
  lastButtonState = buttonState; // Save the current button state for the next loop iteration
}
