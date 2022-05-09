#include <Servo.h>

int motor_control = 8;
Servo servo;

void setup()
{
  servo.attach(motor_control);
}


void loop()
{
  int i;
  
  servo.write(0);
  delay(1000);
  
  for(i=0;i<=180;i+=10) /* i<=90 */
  {
    servo.write(i);
    delay(100);
  }
  
  delay(1000);
}
