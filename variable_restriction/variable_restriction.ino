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

    sensorValue = analogRead(sensorPin); 
    analogWrite(led, sensorValue/4);
    Serial.println(sensorValue);

    delay(10); 

}
