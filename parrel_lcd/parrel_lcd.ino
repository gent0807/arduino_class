#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
    // set up the LCD's number of columns and rows: 
    lcd.begin(8, 2);
}
void loop() 
{
    lcd.setCursor(0, 0); 
    // Print a message to the LCD.
    lcd.print("hello, w");
    // set the cursor to column 0, line 1
    lcd.setCursor(0, 1); 
    lcd.print("orld!");
    delay(1000);
}