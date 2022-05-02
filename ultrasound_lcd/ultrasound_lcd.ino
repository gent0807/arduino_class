#define trigPin 13 
#define echoPin 12 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() 
{ 
    lcd.begin(); 
    lcd.backlight();
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
} 
long microsecondsToInches(long microseconds)
{
    // According to Parallax's datasheet for the PING))), there are
    // 73.746 microseconds per inch 

    return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
    
    return microseconds / 29 / 2;
}
void loop() 
{ 
    long duration, inches, cm;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); 

    // convert the time into a distance
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(inches);
    lcd.print("inch, ");
    lcd.setCursor(0,1);
    lcd.print(cm);
    lcd.print(" cm"); 

    delay(100); 
}
