const int pin1MotorA=6;
const int pin2MotorA=7;
const int pinRMotorA=5;
int tiempo=1000;

void setup() {
pinMode (pin1MotorA,OUTPUT);
pinMode (pin2MotorA,OUTPUT);
pinMode (pinRMotorA,OUTPUT);

}

void loop() {
analogWrite (pinRMotorA,130);

digitalWrite (pin1MotorA,HIGH);
digitalWrite (pin2MotorA,LOW);
delay (tiempo);
digitalWrite (pin1MotorA,LOW);
digitalWrite (pin2MotorA,LOW);
delay (tiempo);
digitalWrite (pin1MotorA,LOW);
digitalWrite (pin2MotorA,HIGH);
delay (tiempo);
digitalWrite (pin1MotorA,LOW);
digitalWrite (pin2MotorA,LOW);
delay (tiempo);

}
