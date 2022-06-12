#include <Servo.h>
Servo elbow1;
int a=90;
void setup() {
  // put your setup code here, to run once:
  elbow1.attach(10);
  elbow1.write(a);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(a=60; a<180; a++){
    elbow1.write(a);
    delay(12);
    }
   if(a==180){
    for(a=180; a>60;a--){
      elbow1.write(a);
      delay(12);
      }
    }
}
