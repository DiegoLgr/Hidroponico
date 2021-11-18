#include "sensor_nivel.h"
#include <Arduino.h>

// Date constructor
Sensor_nivel::Sensor_nivel(int pinNivelBuffer)
{
  pin = pinNivelBuffer;
}

int Sensor_nivel::read()
{int nivel = (digitalRead(pin)+1)%2;
 Serial.print("leyendo nivel: \n");
 Serial.println(nivel);
 return nivel;
}
