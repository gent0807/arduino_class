#include <Servo.h>
const int thumb_finger=A0;
const int index_finger=A1;
const int mid_figer=A2;
const int ring_finger=A3;
const int little_finger=A4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(robot_tf);
  servo.attach(robot_if);
  servo.attach(robot_mf);
  servo.attach(robot_rf);
  servo.attach(robot_lf);
}
void loop() {
  // put your main code here, to run repeatedly:
  int value1=analogRead(thumb_finger);
  int value2=analogRead(index_finger);
  int value3=analogRead(mid_finger);
  int value4=analogRead(ring_finger);
  int value5=analogRead(little_finger);

  servo.write(robot_tf,map(value1,0,1023,0,255));
  servo.write(robot_if,map(value2,0,1023,0,255));
  servo.write(robot_mf,map(value3,0,1023,0,255));
  servo.write(robot_rf,map(value4,0,1023,0,255));
  servo.write(robot_lf,map(value5,0,1023,0,255));

  
}
