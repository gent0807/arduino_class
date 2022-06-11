#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <SoftwareSerial.h>
SoftwareSerial Slave1(10,3);
LiquidCrystal_I2C lcd(0x27,16,2);

byte sensing[]={4,5,A0};
byte action[]={8}; 
void setup() {
  lcd.begin();
  lcd.backlight();
  Slave1.begin(9600);
  Serial.begin(9600);
 
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);  
  

}
void loop() {
    byte receive[3];
    byte state[3];
    Slave1.readBytes(receive,3);
    for(int i=0;i<3;i++){
       if(i==0){
            if(digitalRead(sensing[0])==LOW){
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
                     lcd.print("humi :");
                     lcd.print(receive[1]);
                     lcd.setCursor(0,1);
                     lcd.print("temp :");
                     lcd.print(receive[2]);
                 }  
                
                         
          
               }
               if(digitalRead(sensing[1])==HIGH){
                     state[1]='1';

                  if(receive[1]>=0){
                     lcd.clear();
                     lcd.setCursor(0,0);
                     lcd.print("humi :");
                     lcd.print(receive[1]);
                     lcd.setCursor(0,1);
                     lcd.print("temp :");
                     lcd.print(receive[2]);
                 }  
                 
           
                }

          }
         if(i==2){
            if(analogRead(sensing[2])>=0){
               int r=analogRead(sensing[2]);
               r=map(r,0,1023,0,255);
               state[2]=(byte)r;
            }

               
             
         }
        
          
      }
    
       Slave1.write(state,3);
 
}
