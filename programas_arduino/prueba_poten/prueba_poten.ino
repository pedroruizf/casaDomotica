const int poten=A0;

void setup() {
Serial.begin (9600);

}

void loop() {
  Serial.println (analogRead (poten));
  delay (100);

}
