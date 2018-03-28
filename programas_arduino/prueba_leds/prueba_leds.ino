int tiempo=50;
const int ledVerde=2;
const int ledRojo=3;
void setup() {
  // put your setup code here, to run once:
pinMode (ledVerde,OUTPUT);
pinMode (ledRojo,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite (ledVerde,HIGH);
delay (tiempo);
digitalWrite (ledVerde,LOW);
delay (tiempo);
digitalWrite (ledRojo,HIGH);
delay (tiempo);
digitalWrite (ledRojo,LOW);
delay (tiempo);
}
