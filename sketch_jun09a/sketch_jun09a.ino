const int flamepin=4;
const int buzzer=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(flamepin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(flamepin)==LOW){
    digitalWrite(buzzer, HIGH);
    }
  if(digitalRead(flamepin)==HIGH){
    digitalWrite(buzzer, LOW);
    }
}
