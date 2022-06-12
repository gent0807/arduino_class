
#include <Servo.h>



Servo thumbs;
Servo index;
Servo middle;
Servo ring;
Servo week;

Servo wrist1;
Servo wrist2;
Servo elbow1;
Servo elbow2;
Servo axis;

int thumbs_sensing=A0;
int middle_sensing=A2;
int ring_sensing=A3;


void setup() {
  
  
  
  thumbs.attach(3);
  index.attach(4);
  middle.attach(5);
  ring.attach(6);
  week.attach(7);
  
  axis.attach(8);
  elbow1.attach(9);
  elbow2.attach(10);
  wrist1.attach(11);
  wrist2.attach(12);
  
  

  thumbs.write(0);
  index.write(0);
  middle.write(0);
  ring.write(0);
  week.write(0);
  
  axis.write(0);
  elbow1.write(0);
  elbow2.write(180);
  wrist1.write(0);
  wrist2.write(180);
  
 }

void loop() {
 int thumbs_sensing_val=analogRead(thumbs_sensing);
 int middle_sensing_val=analogRead(middle_sensing);
 int ring_sensing_val=analogRead(ring_sensing);

 thumbs_sensing_val=map(thumbs_sensing_val, 200, 280, 0, 180);
 middle_sensing_val=map(middle_sensing_val, 210, 300, 0, 180);
 ring_sensing_val=map(ring_sensing_val, 200, 280, 0, 180 );
 
 
 thumbs.write(thumbs_sensing_val);

 index.write(middle_sensing_val); 

 middle.write(middle_sensing_val); 

 ring.write(ring_sensing_val);

 week.write(ring_sensing_val);

 
 delay(200);

  

}

  
