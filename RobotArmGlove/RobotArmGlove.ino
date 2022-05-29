#include <SoftwareSerial.h>
SoftwareSerial Slave1(2,3);
//SoftwareSerial Master2(4.5);

//const int button1=4;
//const int button2=5;
byte button[]={4,5};
void setup() {
  // put your setup code here, to run once:
  Slave1.begin(9600);
  Serial.begin(9600);
  for(int i=0; i<2;i++){
    pinMode(button[i], INPUT);
    }
  //Master2.begin(9600);
  //pinMode(button1,INPUT);
  //pinMode(button2,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  /*if(Serial.available()){
    Slave1.write(Serial.read());
    }
  if(Slave1.available()){
    Serial.write(Slave1.read());
    }
  */
  /*if(Slave1.available()){
    String text=Slave1.readStringUntil(0x0d);
    Serial.println(text);
    }
    delay(1000);
   */
   /*if(Slave1.available()){
    char receive[2];

    Slave1.readBytes(receive, 2);
    Serial.print(receive[0]);
    Serial.println(receive[1]);
    }
    */
    /*
    if(Serial.available()){
    Slave1.write(Serial.read());
    }
    */
    /*if(digitalRead(button1)==LOW){
      Slave1.write('0');
    }
    else if(digitalRead(button1)==HIGH){
      Slave1.write('1');
      }
      */
      char led_state[2];
      for(int i=0;i<2;i++){
        if(digitalRead(button[i])==LOW){
          led_state[i]='0';
         }
        else if(digitalRead(button[i])==HIGH){
          led_state[i]='1';
          }
        }
      Slave1.write(led_state,2);
      for(int i=0;i<2;i++){
        int r=analogRead(A0);
        byte s=map(r,0,1023,0,255);
      Slave1.write(s);
      }
}
