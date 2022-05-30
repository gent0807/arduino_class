#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <SoftwareSerial.h>
SoftwareSerial Slave1(2,3);
LiquidCrystal_I2C lcd(0x27,16,2);

//const int button1=4;
//const int button2=5;
byte sensing[]={4,5,A0};
byte action[]={7};
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Slave1.begin(9600);
  Serial.begin(9600);
  for(int i=0; i<3;i++){
    if(i==0||i==1)
    pinMode(sensing[i], INPUT);
    }
  for(int i=0; i<1;i++){
    if(i==0)
    pinMode(action[i], OUTPUT);
    }
  
  //Master2.begin(9600);
  //pinMode(button1,INPUT);
  //pinMode(button2,INPUT);
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
   /*if(Slave1.available()){
    char receive[2];

    Slave1.readBytes(receive, 2);
    Serial.print(receive[0]);
    Serial.println(receive[1]);
    }
    */
    /*
    if(Serial.available()){
    Slave1.write(Serial.read());
    }
    */
    /*if(digitalRead(button1)==LOW){
      Slave1.write('0');
    }
    else if(digitalRead(button1)==HIGH){
      Slave1.write('1');
      }
      */
    byte receive[3];
    byte state[3];
    Slave1.readBytes(receive,3);
    for(int i=0;i<3;i++){
        if((i==0||i==1)&&digitalRead(sensing[i])==LOW){
          state[i]='0';
          
          if(i==0&&receive[i]=='0'){
          noTone(action[i]);
          }
          else if(i==0&&receive[i]=='1'){
          
          tone(action[i],294);
          
           
          } 
          else if(i==1&&receive[i]>=0){
            lcd.print("humid :");
            lcd.print(receive[i]);
            }
          
         }
        else if((i==0||i==1)&&digitalRead(sensing[i])==HIGH){
          state[i]='1';
          if(i==0&&receive[i]=='0'){
          noTone(action[i]);
          }
          else if(i==0&&receive[i]=='1'){
         
          tone(action[i],294);
         
          
          } 
          else if(i==1&&receive[i]>=0){
            lcd.print("humid :");
            lcd.print(receive[i]);
            }
          
          }
        else if((i==2)&&analogRead(sensing[i])>=0){
          int r=analogRead(sensing[i]);
          r=map(r,0,1023,2,255);
          state[i]=(byte)r;
          if(receive[i]>=0){
            lcd.print(" temperature :");
            lcd.println(receive[i]);
            }          
        }
      }
    
       Slave1.write(state,3);
   /*byte receive[1];
   if(Slave1.available()){
    Slave1.readBytes(receive,1);
    for(int i=0; i<1; i++){
      if(i==0&&receive[i]=='0'){
        noTone(action[i]);
        }
      else if(i==0&&receive[i]=='1')
        for(int i=0;i<10;i++){
          tone(action[i],294);
          delay(1000);
          } 
        } 
      }
    }
   }*/
}
