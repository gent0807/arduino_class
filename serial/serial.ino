void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello Arduino");
}

void loop() {
  // put your main code here, to run repeatedly:
  char read_data;

  if(Serial.available()){
    read_data=Serial.read();
    Serial.print(read_data);
    }

   delay(10);
}
