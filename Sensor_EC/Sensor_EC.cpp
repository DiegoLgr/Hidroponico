#include "sensor_EC.h"
#include <Arduino.h>

// Date constructor
Sensor_EC::Sensor_EC(int pinEC)
{
  pin = pinEC;
}

float Sensor_EC::read()
{float EC = analogRead(pin);
 Serial.print("pin:\n");
 Serial.print(pin);
 Serial.print(" leyendo EC:  ");
 Serial.println(EC);
 return EC;
}
