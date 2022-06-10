#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <SoftwareSerial.h>
SoftwareSerial Slave1(10,3);
LiquidCrystal_I2C lcd(0x27,16,2);

//const int button1=4;
//const int button2=5;
byte sensing[]={4,5,A0,A1,A2,A3,A4,A5};
byte action[]={8}; 
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
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
    byte state[7];
    Slave1.readBytes(receive,3);
    for(int i=0;i<7;i++){
       if(i==0){
            if(digitalRead(sensing[0]==LOW)){
                  state[0]='0';
               

                if(receive[0]=='0'){
                   digitalWrite(action[0], LOW);
                }
                
                
                if(receive[0]=='1'){
                   digitalWrite(action[0], HIGH);
                }
              
             }
             if(digitalRead(sensing[0])==HIGH){
                   state[0]='1';
                if(receive[0]=='0'){
                   digitalWrite(action[0], LOW);
                }
                
                
                if(receive[0]=='1'){
                   digitalWrite(action[0], HIGH);
                }
                  
          
                   
             }


          }
       if(i==1){
              if(digitalRead(sensing[1]==LOW)){
                    state[1]='0';
 
                 if(receive[1]>=0){
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("humid :");
                    lcd.print(receive[1]);
                }  
          
               }
               if(digitalRead(sensing[1])==HIGH){
                     state[1]='1';

                  if(receive[1]>=0){
                     lcd.clear();
                     lcd.setCursor(0,0);
                     lcd.print("humid :");
                     lcd.print(receive[1]);
                 }  
           
                }

          }
         if(i==2){
            if(analogRead(sensing[2])>=0){
               int r=analogRead(sensing[2]);
               r=map(r,0,1023,0,255);
               state[2]=(byte)r;

               if(receive[2]>=0){
                  lcd.setCursor(0,1);
                  lcd.print("temperature:");
                  lcd.print(receive[2]);
               }          
             }
         }
         if(i==3){
            byte value=analogRead(sensing[3]);
            Serial.println(value);
            state[3]=(byte)analogRead(sensing[3]);          
          }
          if(i==4){
            byte value=analogRead(sensing[4]);
            //Serial.println(value);
            state[4]=(byte)analogRead(sensing[4]);          
          }
          if(i==5){
            byte value=analogRead(sensing[5]);
            //Serial.println(value);
            state[5]=(byte)analogRead(sensing[5]);    
          }
          if(i==6){
            byte value=analogRead(sensing[6]);
            //Serial.println(value);
            state[6]=(byte)analogRead(sensing[6]);             
          }
          if(i==7){
            byte value=analogRead(sensing[7]);
            //Serial.println(value);
            state[7]=(byte)analogRead(sensing[7]);             
          }
          
      }
    
       Slave1.write(state,8);
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
