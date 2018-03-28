const int echoPin = 9;
const int triggerPin = 8;
 
void setup() {
   Serial.begin(9600);
   pinMode(LedPin, OUTPUT);
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);
}
 
void loop() {
   int cm = ping(triggerPin, echoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);
   delay(1000);
}
 
int ping(int triggerPin, int echoPin) {
   long duration, distanceCm;
   
   digitalWrite(triggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(triggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(triggerPin, LOW);
   
   duration = pulseIn(echoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
