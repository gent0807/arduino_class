int led = 3;
int sensor = 2;

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(sensor, INPUT);
}
void loop()
{
    if( digitalRead(sensor) == HIGH ){
        digitalWrite(led, HIGH);
        delay (1000);
    }
    else
        digitalWrite(led, LOW); 
    
    delay(100);
}
