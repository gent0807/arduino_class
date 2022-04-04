int led = 9; // the pin that the LED is attached to

int fadeAmount = 5; // how many points to fade the LED by

void setup() 
{ 
    pinMode(led, OUTPUT);
} 

void loop() 
{ 
  for(brightness=0; brightness<=255; brightness+=fadeAmount){
    analogWrite(led, brightness); 
    delay(30);
    
    } 
    
   
}
