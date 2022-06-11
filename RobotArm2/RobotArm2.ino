
#include <SoftwareSerial.h>
#include <Servo.h>



SoftwareSerial Master1(2,3);
Servo finger1;
Servo finger2;
Servo finger3;
Servo finger4;

void setup() {
  
  
  
  Master1.begin(9600);
  Serial.begin(9600);

  finger1.attach(10);
  finger1.write(0);
  finger2.attach(11);
  finger2.write(0);
  finger3.attach(5);
  finger3.write(0);
  finger4.attach(6);
  finger4.write(0);
  

  
}
void loop() {
byte receive[4];
Master1.readBytes(receive,4);
for(int i=0; i<4; i++){
  if(i==0){
      if(receive[0]<240){
           finger1.write(180);  
       }
      if(receive[0]>=240){
           finger1.write(0);
       }            
   }
  if(i==1){
       if(receive[1]>180){
            finger2.write(180);
        } 
       if(receive[1]<=180){
            finger2.write(0);
        }     
    }
  if(i==2){   
       if(receive[2]<60){
            finger3.write(180);
        }
       if(receive[2]>=57){
            finger3.write(0);
        }
      }
  if(i==3){
       if(receive[3]>230){
            finger4.write(0);
      }
       if(receive[3]<200){
            finger4.write(180);
      }    
     }  
 }


}
/*if(receive[0]<240){
  finger1.write(180);  
  }
if(receive[0]>=240){
  finger1.write(0);
  } 
if(receive[1]>180){
  finger2.write(180);
  } 
if(receive[1]<=180){
  finger2.write(0);
  } 
 if(receive[2]<60){
  finger3.write(180);
  }
 if(receive[2]>=57){
  finger3.write(0);
  }
 if(receive[3]>230){
 finger4.write(0);
 }
 if(receive[3]<200){
  finger4.write(180);
 }*/  

 
