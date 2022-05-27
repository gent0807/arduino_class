#include <SoftwareSerial.h>
SoftwareSerial HC06(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC06.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    HC06.write(Serial.read());
    }
  if(HC06.available()){
    Serial.write(HC06.read());
    }
}
