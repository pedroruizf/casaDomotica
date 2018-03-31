# Proyecto de Casa Domótica
Este proyecto es original de *Maribel Ruiz Martínez*, el cual lo he adaptado para mi alumnado de 4º de ESO.
Se trata de una maqueta de casa domotizada con tres estancias, controlada con dos arduinos uno comunicados por puerto serie:
![vista general](/images/vista_general.jpg)
* Estancia principal
  * Pulsador
  * Potenciómetro
  * LCD 2x16 I2C
  * Dos Leds
  * Motor DC de Puerta
  * Sensor de ultrasonidos (HC-SR04)
![estancia principal](/images/estancia_principal.jpg)
* Estancia 2
  * Sensor de temperatura y humedad (DHT11)
  * Ventilador
![estancia con ventilador](/images/ventilador.jpg)
* Estancia 3
  * Ldr
  * Motor DC de persiana
![estancia con persiana](/images/persiana.jpg)
## Funcionamiento
Tiene 4 programas, que se escogen con el potenciómetro y pulsación de pulsador:
* **Programa 1 (Acceso a vivienda)**: te pide el código pin de 4 digitos de acceso, en caso de acertar abre y cierra la puerta y desactiva la alarma formada por sensor de ultrasonidos y zumbador. Si la alarma no se desactiva cuando hay alguien en la estancia principal el zumbador suena al ser detectado por el ultrasonidos.
* **Programa 2 (desactivación de la alarma de acceso)**: al pulsar desactiva o activa la alarma de acceso, cambiando el estado de la misma.
* **Programa 3 (activación de ventilación)**: activa o desactiva la ventilación automática de la segunda estancia. Para esto el arduino 1 manda la orden al arduino 2. Cuando la temperatura es mayor o igual a 25 ºC, se activa el ventilador.
* **Programa 4 (activación persiana automática)**: activa o desactiva el funcionamiento automático de la persiana. Para esto el arduino 1 manda la orden al arduino 2. Cuando hay luz la persiana baja y cuando no hay luz en la estancia sube.  
## Recursos utilizados
* [Sensor DHT11](https://programarfacil.com/blog/arduino-blog/sensor-dht11-temperatura-humedad-arduino/)
* [Driver L298N para motores DC](https://electronilab.co/tutoriales/tutorial-de-uso-driver-dual-l298n-para-motores-dc-y-paso-a-paso-con-arduino/)
* [Sensor de Ultrasonidos HC-SR04](https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/)
