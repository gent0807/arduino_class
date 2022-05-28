#include <SoftwareSerial.h>
SoftwareSerial Slave1(2,3);
//SoftwareSerial Master2(4.5);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Slave1.begin(9600);
  //Master2.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  /*if(Serial.available()){
    Slave1.write(Serial.read());
    }
  if(Slave1.available()){
    Serial.write(Slave1.read());
    }
  */
  /*if(Slave1.available()){
    String text=Slave1.readStringUntil(0x0d);
    Serial.println(text);
    }
    delay(1000);
   */
   if(Slave1.available()){
    char receive[2];

    Slave1.readBytes(receive, 2);
    Serial.print(receive[0]);
    Serial.println(receive[1]);
    }
}
