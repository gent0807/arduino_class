#include <SoftwareSerial.h>
SoftwareSerial AT09(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AT09.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    AT09.write(Serial.read());
    }
  if(AT09.available()){
    Serial.write(AT09.read());
    }
}
