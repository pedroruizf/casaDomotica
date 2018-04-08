const int ldr=0;
int luz;

void setup() {
  pinMode (13,OUTPUT);
  Serial.begin (9600);
}

void loop() {
  //Serial.print ("medida de ldr ...");
  Serial.println (analogRead (ldr));
  delay (1000);
luz=analogRead (ldr);
  if (luz<=700) {

    digitalWrite (13,HIGH);
  }

  else {

    digitalWrite (13,LOW);
  }
}
