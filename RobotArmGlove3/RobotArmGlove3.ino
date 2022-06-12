#include <Wire.h>

#include <SoftwareSerial.h>
SoftwareSerial Slave1(10,3);

byte sensing[]={A1,A2,A3,A4};
uint32_t pasttime;
float filteredValue1;
float filteredValue2;
float filteredValue3;
float filteredValue4;
float sensitivity=0.1;
void setup() {

  Slave1.begin(9600);
  Serial.begin(9600);
  filteredValue1=analogRead(sensing[0]);
  filteredValue2=analogRead(sensing[1]);
  filteredValue3=analogRead(sensing[2]);
  filteredValue4=analogRead(sensing[3]);
}
void loop() {
    
    byte state[4];
    for(int i=0;i<4;i++){
       if(i==0){
            byte value=analogRead(sensing[0]);
            //Serial.println(value);
            
            filteredValue1=filteredValue1*(1-sensitivity)+value*sensitivity;


            
            //Serial.println((byte)filteredValue1);
            
            state[0]=(byte)filteredValue1;  
          }
       if(i==1){
            byte value=analogRead(sensing[1]);
            //Serial.println(value);
            
            filteredValue2=filteredValue2*(1-sensitivity)+value*sensitivity;
            
           
            Serial.println((byte)filteredValue2);
            state[1]=(byte)filteredValue2;  

          }
       if(i==2){
            byte value=analogRead(sensing[2]);
            //Serial.println(value);
            
            filteredValue3=filteredValue3*(1-sensitivity)+value*sensitivity;
            
            //Serial.println((byte)filteredValue3);
            state[2]=(byte)filteredValue3;  

             
         }
         if(i==3){
            byte value=analogRead(sensing[3]);
            //Serial.println(value);
            
            filteredValue4=filteredValue4*(1-sensitivity)+value*sensitivity;
            
            //Serial.println((byte)filteredValue4);
            state[3]=(byte)filteredValue4;  

          }
         
          
      }
    
       
     

       
       
       
       
       
       
       
       
       
       if(millis()-pasttime>250){
           pasttime=millis();
           Slave1.write(state,4);
        }
        
       
       
 
}
