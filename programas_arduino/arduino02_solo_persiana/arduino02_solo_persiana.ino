
boolean persianaAbajo = true;
const int ldr = 0;
const int pinMotorBR = 11;
const int pinMotorB1 = 12;
const int pinMotorB2 = 13;

void setup() {

  Serial.begin (9600);


  pinMode (pinMotorBR, OUTPUT);
  pinMode (pinMotorB1, OUTPUT);
  pinMode (pinMotorB2, OUTPUT);

}

void loop() {
  controlaPersiana();
}



void controlaPersiana() {//la persiana tiene que partir desde posición inferior (abajo)
  int luz = analogRead(ldr);
  int tiempo = 400;
  Serial.println(luz);

  if (luz <= 512 && persianaAbajo == true) { //si hay poca luz y la persiana está abajo la sube
    analogWrite (pinMotorBR, 90);
    digitalWrite (pinMotorB1, HIGH);
    digitalWrite (pinMotorB2, LOW);
    delay (tiempo);
    digitalWrite (pinMotorB1, LOW);
    digitalWrite (pinMotorB2, LOW);
    persianaAbajo = !persianaAbajo;

  }

  else if (luz > 512 && persianaAbajo == false) { // si hay mucha luz y la persiana está arriba la baja
    analogWrite (pinMotorBR, 90);
    digitalWrite (pinMotorB1, LOW);
    digitalWrite (pinMotorB2, HIGH);
    delay (tiempo);
    digitalWrite (pinMotorB1, LOW);
    digitalWrite (pinMotorB2, LOW);
    persianaAbajo = !persianaAbajo;


  }

  else {
    digitalWrite (pinMotorB1, LOW);
    digitalWrite (pinMotorB2, LOW);
  }

}




