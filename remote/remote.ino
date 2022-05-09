
#include <IRremote.h>                    //adds the library code to the sketch

const int irReceiverPin = 2;             //pin the receiver is connected to
const int ledPin = 12;

IRrecv irrecv(irReceiverPin);            //create an IRrecv object
decode_results decodedSignal;   //stores results from IR detectorvoid

void setup()
{
  // Open serial communications and wait for port to open:
   Serial.begin(9600);
   while (!Serial) {
   ; // wait for serial port to connect. Needed for Leonardo only
   }
     
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn();                   // Start the receiver object
}
boolean lightState = false;     //keep track of whether the LED is on
unsigned long last = millis();  //remember when we last received an IR message

void loop()  {
  if (irrecv.decode(&decodedSignal) == true) 
  {
    if (millis() - last > 250/*250*/) 
    {       
      lightState = !lightState;  //Yes: toggle the LED
      digitalWrite(ledPin, lightState);
      Serial.print("value=");
      Serial.println(decodedSignal.value, HEX);
      Serial.print("decode_type=");
      Serial.println(decodedSignal.decode_type);
    }
    
    last = millis();
    irrecv.resume();       // watch out for another message
  }
}
