#include <SoftwareSerial.h>

int bluetoothTx = 2;
int bluetoothRx = 3;
int LED1 = 9;
int LED2 =10;
int LED3= 11;
int LED4=12;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
    Serial.begin(9600); 
    delay(100);
    bluetooth.begin(9600);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
}
void loop()    {
    char cmd;
    if(bluetooth.available() )
    {
        cmd = (char)bluetooth.read();
        Serial.print("Command = ");
        Serial.println(cmd);

        if( cmd == '8' )
        {
            Serial.println("LED1 ON");
            digitalWrite(LED1, HIGH);
        }
        if( cmd == '4' )
        {
            Serial.println("LED2 ON");
            digitalWrite(LED2, HIGH);
        } 
        if( cmd == '6' )
        {
            Serial.println("LED3 ON");
            digitalWrite(LED3, HIGH);
        } 
        if( cmd == '2' )
        {
            Serial.println("LED4 ON");
            digitalWrite(LED4, HIGH);
        } 
        if( cmd == '0' )
        {
            Serial.println("LED ALL OFF");
            digitalWrite(LED1, LOW);
            digitalWrite(LED2, LOW);
            digitalWrite(LED3, LOW);
            digitalWrite(LED4, LOW);
        } 
    }
}
