#include <SoftwareSerial.h>
SoftwareSerial Master1(2,3);
//SoftwareSerial Slave2(4,5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Master1.begin(9600);
  //Slave2.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    Master1.write(Serial.read());
    }
  if(Master1.available()){
    Serial.write(Master1.read());
    }
}
