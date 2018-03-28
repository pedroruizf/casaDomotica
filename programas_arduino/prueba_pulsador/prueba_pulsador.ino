const int pulsador=12;

void setup() {
pinMode (12,INPUT);
Serial.begin (9600);
}

void loop() {

if (digitalRead (pulsador)==HIGH ) {

  Serial.println ("pulsado");
  delay(150);
}

}
