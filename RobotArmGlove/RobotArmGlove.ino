#include <SoftwareSerial.h>
SoftwareSerial slave1(2,3);
//SoftwareSerial master2(4.5);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  slave1.begin(9600);
  //master2.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    slave1.write(Serial.read());
    }
  if(slave1.available()){
    Serial.write(slave1.read());
    }
}
