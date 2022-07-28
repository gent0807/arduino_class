#include <MPU6050_light.h>

#include <LiquidCrystal_I2C.h>

#include <Wire.h>

#include <SoftwareSerial.h>
SoftwareSerial Slave1(10,3);
LiquidCrystal_I2C lcd(0x27,16,2);

byte sensing[]={4,5,A0,A1,A2,A3,A4,A5,A6};
byte action[]={8}; 
float filteredValue1;
float filteredValue2;
float filteredValue3;
float filteredValue4;
float sensitivity=0.1;
uint32_t pasttime;
void setup() {
  lcd.begin();
  lcd.backlight();
  Slave1.begin(9600);
  Serial.begin(9600);
 
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(8, OUTPUT);  

  filteredValue1=analogRead(sensing[3]);
  filteredValue2=analogRead(sensing[4]);
  filteredValue3=analogRead(sensing[5]);
  filteredValue4=analogRead(sensing[6]);

}
void loop() {
    
    byte receive[3];
    byte state[7];
    Slave1.readBytes(receive,3);
    for(int i=0;i<7;i++){
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
         if(i==3){
              byte value=analogRead(sensing[i]);
            //Serial.println(value);
            
            filteredValue1=filteredValue1*(1-sensitivity)+value*sensitivity;


            
            //Serial.println((byte)filteredValue1);
            
            state[i]=(byte)filteredValue1;            
         }
        if(i==4){
              byte value=analogRead(sensing[i]);
            //Serial.println(value);
            
            filteredValue2=filteredValue2*(1-sensitivity)+value*sensitivity;


            
            //Serial.println((byte)filteredValue1);
            
            state[i]=(byte)filteredValue2;            
         }
         if(i==5){
               byte value=analogRead(sensing[i]);
            //Serial.println(value);
            
            filteredValue3=filteredValue3*(1-sensitivity)+value*sensitivity;


            
            //Serial.println((byte)filteredValue1);
            
            state[i]=(byte)filteredValue3;             
         }
         if(i==6){
               byte value=analogRead(sensing[i]);
            //Serial.println(value);
            
            filteredValue4=filteredValue4*(1-sensitivity)+value*sensitivity;


            
            //Serial.println((byte)filteredValue4);
            
            state[i]=(byte)filteredValue4;              
         }
         
        
          
      
    
      if(millis()-pasttime>220){
           pasttime=millis();
           Slave1.write(state,4);
        }
   
    }
}
