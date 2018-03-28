const int pin1MotorB=12;
const int pin2MotorB=13;
const int pinRMotorB=11;
int tiempo1=300;
int tiempo2=2000;

void setup() {
pinMode (pin1MotorB,OUTPUT);
pinMode (pin2MotorB,OUTPUT);
pinMode (pinRMotorB,OUTPUT);

}

void loop() {
analogWrite (pinRMotorB,90);

digitalWrite (pin1MotorB,HIGH);
digitalWrite (pin2MotorB,LOW);
delay (tiempo1);
digitalWrite (pin1MotorB,LOW);
digitalWrite (pin2MotorB,LOW);
delay (tiempo2);
digitalWrite (pin1MotorB,LOW);
digitalWrite (pin2MotorB,HIGH);
delay (tiempo1);
digitalWrite (pin1MotorB,LOW);
digitalWrite (pin2MotorB,LOW);
delay (tiempo2);

}
