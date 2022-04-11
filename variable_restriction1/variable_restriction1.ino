
int sensorPin = A0; // select the input pin for the potentiometer
int led = 9; // the pin that the LED is attached to
void setup() {
  // put your setup code here, to run once:
    pinMode(led, OUTPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
    int sensorValue = 0;
    float voltage = 0.0;
    sensorValue = analogRead(sensorPin); 
    voltage = ((float)sensorValue/1023.0)*5.0;
    Serial.print(sensorValue);
    Serial.print(", ");
    Serial.println(voltage);
    analogWrite(led, sensorValue); 
    delay(10); 

}
