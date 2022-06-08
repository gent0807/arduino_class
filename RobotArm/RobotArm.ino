   #include <DHT11.h>

#include <SoftwareSerial.h>

SoftwareSerial Master1(2,3);
//SoftwareSerial Slave2(4,5);
//const int led1=4;
byte action[]={5,6,9};
byte sensing[]={4,8};
const int cds_output=7;
void setup() {
  // put your setup code here, to run once:
  Master1.begin(9600);
  Serial.begin(9600);
  
  //Slave2.begin(9600);
  //pinMode(led1, OUTPUT);
  
  for(int i=0;i<3;i++){
    pinMode(action[i], OUTPUT);
    }
    
  pinMode(cds_output,OUTPUT);
  
  for(int i=0;i<1;i++){
    pinMode(sensing[i], INPUT);
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
  digitalWrite( led1, HIGH);
  }
}*/
byte receive[3];
byte state[3];
Master1.readBytes(receive,3);
for(int i=0;i<3;i++){
     if(i==0){
         if(receive[0]=='0'){
             if(digitalRead(sensing[0])==LOW){
                     state[0]='1';
             }
             else if(digitalRead(sensing[0])==HIGH){
                     state[0]='0';
             }
             digitalWrite(action[0], LOW);
         }
         if(receive[0]=='1'){
              if(digitalRead(sensing[0])==LOW){
                     state[0]='1';
             }
              else if(digitalRead(sensing[0])==HIGH){
                     state[0]='0';
             }
              digitalWrite(action[0], HIGH);
         }
         
      }
      if(i==1){
           if(receive[1]=='0'){
               if(digitalRead(sensing[1])==LOW){
                       state[1]='1';
               }
               else if(digitalRead(sensing[1])==HIGH){
                       state[1]='0';
               }
               digitalWrite(action[1], LOW);
              
           }
           if(receive[1]=='1'){
                if(digitalRead(sensing[1])==LOW){
                       state[1]='1';
                }
                else if(digitalRead(sensing[1])==HIGH){
                       state[1]='0';
                }
                digitalWrite(action[1], HIGH);
                }
                DHT11 dht11(sensing[1]);
                float temp=0.0, humi=0.0;
                if(dht11.read(humi,temp)==0){
                    state[1]=(byte)humi;
                    state[2]=(byte)temp;
                }
            }
        if(i==2){
                 if(receive[2]>=0){
                 analogWrite(action[2], receive[2]);
            }
            } 
}

Master1.write(state,3);

byte brightness=analogRead(A0);
if(brightness<60){
  digitalWrite(cds_output, HIGH);
  }
else digitalWrite(cds_output, LOW);
/*byte state[1];  
for(int i=0;i<1;i++){
  if(i==0&&digitalRead(sensing[i])==LOW){
    state[i]='1';
    }
  else if(i==0&&digitalRead(sensing[i])==HIGH){
    state[i]='0';
    }
}
Master1.write(state,1);
*/
}
