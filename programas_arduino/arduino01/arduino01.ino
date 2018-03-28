#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

//Pines
const int ledVerde = 2;
const int ledRojo = 3;
const int pulsador = 12;
const int zumbador = 11;
const int poten = 0;
// Pines de motor de puerta
const int pin1MotorB = 6;
const int pin2MotorB = 7;
const int pinRMotorB = 5;
int tiempo = 1000;// tiempo de apertura y cierre de puerta
const int pinCorrecto [4] = {4, 5, 6, 7}; //matriz de código pin de entrada a vivienda
int pin [4] = {0, 0, 0, 0}; //matriz de código introducido
int contador = 0;
int opcion = 0;//opción a introducir con potenciómetro y pulsador en un princpio es 0
boolean alarma = true;// estado de la alarma para controlar presencia con ultrasonidos
//pines del ultrasonidos
const int echoPin = 9;
const int triggerPin = 8;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode (ledRojo, OUTPUT);
  pinMode (pulsador, INPUT);
  pinMode (zumbador, OUTPUT);
  pinMode (pin1MotorB, OUTPUT);
  pinMode (pin2MotorB, OUTPUT);
  pinMode (pinRMotorB, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (9600);
  lcd.init();// inicializa el lcd
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print ("Opcion:");

}

void loop() {
  lcd.setCursor (11, 0);
  lcd.print (map (analogRead (poten), 0, 1021, 1, 9));
  lcd.setCursor (12, 0); lcd.print ("  ");

  if (digitalRead(pulsador) == HIGH) {
    opcion = map (analogRead (poten), 0, 1021, 1, 9);
    lcd.setCursor (12, 0); lcd.print ("//");
    digitalWrite (zumbador, HIGH);
    delay (200);
    digitalWrite (zumbador, LOW);
    delay (300);// tiempo de antirebote
  }



  if (alarma == true) {
    digitalWrite (ledRojo, HIGH);
    int cm = ping(triggerPin, echoPin);
    static char charCm[2];
    dtostrf(cm, 2, 0, charCm);
    lcd.setCursor (0, 1); lcd.print ("dis(cm):");
    lcd.setCursor(8, 1); lcd.print ( charCm);

    if (cm < 30) {
      digitalWrite (zumbador, HIGH);
    }
    else {

      digitalWrite (zumbador, LOW);
    }


  }


  switch (opcion) {
    case 1:
      borraLcd();
      controlPuerta();
      borraLcd();
      opcion = 0;
      break;
    case 2:
      alarma = true;
      opcion = 0;
      break;
  }

}



void controlPuerta () {
  // introducción de pin
  contador = 0;
  while (contador < 4) {
    lcd.setCursor (15, 0);
    lcd.print (map (analogRead (A0), 0, 1021, 1, 9));
    lcd.setCursor (12, 0); lcd.print ("  ");
    lcd.setCursor (3, 1); lcd.print ("pin:");

    if (digitalRead (pulsador) == HIGH) {

      pin[contador] = map (analogRead (poten), 0, 1021, 1, 9);
      lcd.setCursor (contador + 8, 1);
      lcd.print (pin[contador]);
      //digitalWrite (zumbador, HIGH);
      //delay (200);
      //digitalWrite (zumbador, LOW);
      contador++;
      delay (300);
    }

  }
  //comprueba si los pines son iguales en caso contrario activa la alarma con el ultrasonidos y zumbador

  if (pinCorrecto[0] == pin[0] && pinCorrecto[1] == pin[1] && pinCorrecto[2] == pin[2] && pinCorrecto[3] == pin[3]) {

    alarma = false;

    //abrimos y cerramos la puerta
    analogWrite (pinRMotorB, 180);

    digitalWrite (pin1MotorB, LOW);
    digitalWrite (pin2MotorB, HIGH);
    digitalWrite (ledRojo, LOW);
    digitalWrite (ledVerde, HIGH);
    delay (tiempo);
    digitalWrite (pin1MotorB, LOW);
    digitalWrite (pin2MotorB, LOW);
    delay (tiempo);
    digitalWrite (pin1MotorB, HIGH);
    digitalWrite (pin2MotorB, LOW);
    digitalWrite (ledRojo, HIGH);
    digitalWrite (ledVerde, LOW);
    delay (tiempo);
    digitalWrite (pin1MotorB, LOW);
    digitalWrite (pin2MotorB, LOW);
    delay (tiempo);

  }

  else {// si el pin no es correcto activamos la alarma
    alarma = true;
  }


}


int ping(int triggerPin, int echoPin) {
  long duration, distanceCm;

  digitalWrite(triggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(triggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
}

void borraLcd() {

  lcd.setCursor(0, 1); lcd.print("                "); //borra todos los caracteres usados
  lcd.setCursor (15, 0); lcd.print(" ");
}




