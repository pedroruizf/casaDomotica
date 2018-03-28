const int ldr=0;

void setup() {
  Serial.begin (9600);
}

void loop() {
  Serial.print ("medida de ldr ...");
  Serial.println (analogRead (ldr));
  delay (1000);
}
