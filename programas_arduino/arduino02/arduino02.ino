//Configuración necesaria para DHT11
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2  // Pin which is connected to the DHT sensor.
#define DHTTYPE           DHT11     // DHT 11 
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
//fin DHT11

boolean ventilador = false;
boolean persiana = false;
const int dht11 = 2;
const int pinMotorAR = 3;
const int pinMotorA1 = 4;
const int pinMotorA2 = 5;
const int ldr = 0;
const int pinMotorBR = 11;
const int pinMotorB1 = 12;
const int pinMotorB2 = 13;

void setup() {

  Serial.begin (9600);

  // Inicializa el DHT11.
  dht.begin();
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
  // Fin DHT11

  pinMode (dht11, INPUT);
  pinMode (pinMotorAR, OUTPUT);
  pinMode (pinMotorA1, OUTPUT);
  pinMode (pinMotorA2, OUTPUT);
  pinMode (pinMotorBR, OUTPUT);
  pinMode (pinMotorB1, OUTPUT);
  pinMode (pinMotorB2, OUTPUT);

}

void loop() {
  compruebaSerie();

  if (ventilador == true) {

    controlaVentilador();
    compruebaSerie();

  }

  else {

    digitalWrite (pinMotorA1, LOW);
    digitalWrite (pinMotorA2, LOW);
  }

}

void controlaVentilador() {

  int temperatura = mideDHT11();
  Serial.println (temperatura);
  delay (1000);
  if (temperatura >= 25) {//pone en marcha al ventilador
    analogWrite (pinMotorAR, 255);
    digitalWrite (pinMotorA1, HIGH);
    digitalWrite (pinMotorA2, LOW);
  }
  else {//en caso contrario lo apaga
    digitalWrite (pinMotorA1, LOW);
    digitalWrite (pinMotorA2, LOW);

  }
}

int mideDHT11() {//función que devuelve la temperatura de la sala con el DHT11
  int temperatura;
  int humedad;
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    //Serial.println("Error reading temperature!");
  }
  else {
    temperatura = event.temperature;
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    //Serial.println("Error reading humidity!");
  }
  else {
    humedad = event.relative_humidity;
  }

  return temperatura;
}


void controlaPersiana() {


}

void compruebaSerie() {

  if (Serial.available() > 0) {

    int dato = Serial.read();

    if (dato == 3) {
      ventilador = !ventilador;

    }

  }


}



