
#include <SoftwareSerial.h>
#include <Servo.h>



SoftwareSerial Master1(2,3);
Servo finger1;
Servo finger2;
Servo finger3;
Servo finger4;

int action[]={10,11,12,13};



void setup() {
  
  
  
  Master1.begin(9600);
  Serial.begin(9600);
  finger1.attach(11);
  /*finger1.attach(10);
  finger1.write(70);
  finger2.attach(11);
  finger2.write(70);
  finger3.attach(12);
  finger3.write(70);
  finger4.attach(13);
  finger4.write(70);
  */

  
}
void loop() {
//byte receive[4];
//int i;


finger1.write(60);
delay(1000);
finger1.write(180);
delay(1000);


/*finger1.write(0);
delay(1000);

for(i=0; i<90;i+=10){
  finger1.write(i);
  delay(300);
  }

delay(1000);
*/
/*Master1.readBytes(receive,4);*/


/*for(int i=0;i<4;i++){
     if(i==0){
      byte value=receive[i];
      value=
      
      
        
         
      }
    if(i==1){
       
       
       }

     if(i==2){
       
      

       }          
     if(i==3){
       
        
             
               
        } 
  
    }*/


}
