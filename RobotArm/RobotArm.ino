#include <SoftwareSerial.h>
SoftwareSerial Master1(2,3);
//SoftwareSerial Slave2(4,5);
//const int led1=4;
byte action[]={5,6,9};
void setup() {
  // put your setup code here, to run once:
  Master1.begin(9600);
  Serial.begin(9600);
  //Slave2.begin(9600);
  //pinMode(led1, OUTPUT);
  for(int i=0;i<3;i++){
    pinMode(action[i], OUTPUT);
    }
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
byte receive[3];
if(Master1.available()){
Master1.readBytes(receive,3);
for(int i=0;i<3;i++){
  if(receive[i]=='0'){
    digitalWrite(action[i],LOW);
    }
  else if(receive[i]=='1'){
    digitalWrite(action[i],HIGH);
    }  
  else if(receive[i]>=2){
    if(action[i]==action[2]){
    analogWrite(action[i],receive[i]-(byte)2);
    }
    }
  }
}
}
