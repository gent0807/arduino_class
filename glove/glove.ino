#include <Servo.h>
const int thumb_finger=A0;
const int index_finger=A1;
const int mid_figer=A2;
const int ring_finger=A3;
const int little_finger=A4;

const int robot_thumb_finger=3;
const int robot_index_finger=4;
const int robot_mid_finger=5;
const int robot_ring_finger=6;
const int robot_little_finger=7;

Servo thumb_servo;
Servo index_servo;
Servo mid_servo;
Servo ring_servo;
Servo little_servo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  thumb_servo.attach(robot_thumb_finger);
  index_servo.attach(robot_index_finger);
  mid_servo.attach(robot_mid_finger);
  ring_servo.attach(robot_ring_finger);
  little_servo.attach(robot_little_finger);

  thumb_servo.write(0);
  index_servo.write(0);
  mid_servo.write(0);
  ring_servo.write(0);
  little_servo.write(0);
}
void loop() {
  // put your main code here, to run repeatedly:
  int value1=analogRead(thumb_finger);
  int value2=analogRead(index_finger);
  int value3=analogRead(mid_finger);
  int value4=analogRead(ring_finger);
  int value5=analogRead(little_finger);

 thumb_servo.write(map(value1,0,1023,0,255));
 index_ ervo2.write(map(value2,0,1023,0,255));
 mid_servo3.write(map(value3,0,1023,0,255));
 ring_servo4.write(map(value4,0,1023,0,255));
 little_servo5.write(map(value5,0,1023,0,255));

  
}
