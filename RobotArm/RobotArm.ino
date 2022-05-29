#include <SoftwareSerial.h>
SoftwareSerial Master1(2,3);
//SoftwareSerial Slave2(4,5);
//const int led1=4;
byte led[]={5,6};
const int led3=9;
void setup() {
  // put your setup code here, to run once:
  Master1.begin(9600);
  Serial.begin(9600);
  //Slave2.begin(9600);
  //pinMode(led1, OUTPUT);
  for(int i=0;i<2;i++){
    pinMode(led[i], OUTPUT);
    }
  pinMode(led3, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  /*if(Serial.available()){
    Master1.write(Serial.read());
    }
  */
  /*if(Master1.available()){
    char c=Master1.read();
    Serial.write(c);
  */  
    
/*Master1.println("SYS");*/
/*char data[]={'0','K'};
Master1.write(data,2);
delay(1000);
*/
/*
if(c=='0'){
  digitalWrite(led1, LOW);
  }
else if(c=='1'){
  digitalWrite(led1,HIGH);
  }  
*/
/*if(c=='0'){
  digitalWrite(led1, LOW);
  }
else if(c=='1'){
  digitalWrite(led1, HIGH);
  }
}*/
/*char receive[2];
Master1.readBytes(receive,2);
for(int i=0;i<2;i++){
  if(receive[i]=='0'){
    digitalWrite(led[i],LOW);
    }
  else if(receive[i]=='1'){
    digitalWrite(led[i],HIGH);
    }  
  }
  */
  if(Master1.available()){
    analogWrite(led3,Master1.read());
    }


}
