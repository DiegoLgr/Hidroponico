#include "sensor_PH.h"
#include <Arduino.h>

// Date constructor
Sensor_PH::Sensor_PH(int pinPH)
{
  pin = pinPH;
}

float Sensor_PH::read()
{float PH = analogRead(pin);
 Serial.print("leyendo PH: \n");
 Serial.println(PH);
 return PH;
}
