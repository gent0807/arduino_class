#include <Wire.h>

#include <SoftwareSerial.h>
SoftwareSerial Slave1(10,3);

byte sensing[]={A1,A2,A3,A4};
uint32_t pasttime;
void setup() {

  Slave1.begin(9600);
  Serial.begin(9600);

  

}
void loop() {
    
    byte state[4];
    for(int i=0;i<4;i++){
       if(i==0){
            byte value=analogRead(sensing[i]);
            //Serial.println(value);
            state[i]=(byte)analogRead(sensing[i]);   
          }
       if(i==1){
            byte value=analogRead(sensing[i]);
            Serial.println(value);
            state[i]=(byte)analogRead(sensing[i]);

          }
       if(i==2){
           byte value=analogRead(sensing[i]);
           //Serial.println(value);
           state[i]=(byte)analogRead(sensing[i]);


             
         }
         if(i==3){
            byte value=analogRead(sensing[i]);
            //Serial.println(value);
            state[i]=(byte)analogRead(sensing[i]);

          }
         
          
      }
    
       
    
       

       if(millis()-pasttime>220){
           pasttime=millis();
           Slave1.write(state,4);
        }
       
       
 
}
