#include <DHT11.h>
#include <SoftwareSerial.h>



SoftwareSerial Master1(2,3);
DHT11 dht11(8);
Servo finger1;
Servo finger2;
Servo finger3;
Servo finger4;

Servo wrist1;
Servo wrist2;
Servo elbow1;
Servo elbow2;
Servo axis;



int action[]={12,13,9}; 
byte sensing[]={4,8};
const int cds_output=7;
float temp=0.0, humi=0.0;

void setup() {
  
  Master1.begin(9600);
  Serial.begin(9600);
  
  
  for(int i=0;i<3;i++){
    pinMode(action[i], OUTPUT);
    }
    
  pinMode(cds_output,OUTPUT);
  
  pinMode(4, INPUT);


    
}
void loop() {


byte receive[7];
byte state[3];
Master1.readBytes(receive,7);
for(int i=0;i<3;i++){
byte brightness=analogRead(A0);
if(brightness<70){
  digitalWrite(cds_output, HIGH);
  }
else digitalWrite(cds_output, LOW);
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
             digitalWrite(action[1], LOW);
             if(dht11.read(humi,temp)==0){
                    state[1]=(byte)humi;
                    state[2]=(byte)temp;
                }             
              
           }
           if(receive[1]=='1'){
              digitalWrite(action[1], HIGH);
              if(dht11.read(humi,temp)==0){
                    state[1]=(byte)humi;
                    state[2]=(byte)temp;
                }             
           }   

          
    
         }
        if(i==2){
                 if(receive[2]>=0  ){
                 analogWrite(action[2], receive[2]);
            }
            finger1.write(receive[3]);
            finger2.write(receive[3]);
            finger3.write(receive[3]);
            finger4.write(receive[3]);
        }
      
        
}


}
