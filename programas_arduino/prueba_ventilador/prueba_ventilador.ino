const int pin1MotorA=4;
const int pin2MotorA=5;
const int pinRMotorA=3;
int tiempo=3000;

void setup() {
pinMode (pin1MotorA,OUTPUT);
pinMode (pin2MotorA,OUTPUT);
pinMode (pinRMotorA,OUTPUT);

}

void loop() {
analogWrite (pinRMotorA,255);
digitalWrite (pin1MotorA,HIGH);
digitalWrite (pin2MotorA,LOW);
delay (tiempo);
digitalWrite (pin1MotorA,LOW);
digitalWrite (pin2MotorA,LOW);
delay (tiempo);
/*digitalWrite (pin1MotorA,LOW);
digitalWrite (pin2MotorA,HIGH);
delay (tiempo);
digitalWrite (pin1MotorA,LOW);
digitalWrite (pin2MotorA,LOW);
delay (tiempo);*/

}
