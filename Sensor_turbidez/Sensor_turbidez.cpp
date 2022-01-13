#include "sensor_turbidez.h"
#include <Arduino.h>

// Date constructor
Sensor_turbidez::Sensor_turbidez(int pinTurbidez)
{
  pin = pinTurbidez;
}

float Sensor_turbidez::read()
{float turbidez = analogRead(pin);
 Serial.print("leyendo Turbidez: \n");
 Serial.println(turbidez);
 return turbidez;
}
