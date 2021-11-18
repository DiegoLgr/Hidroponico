#include <iostream>

#include "cubeta.h"
#include "buffer.h"
#include "reservorio.h"
#include "sensor_nivel.h"
#include "bomba.h"
#include "notificador.h"

#define ALTO true
#define BAJO false

int i = 0;

Sensor_nivel sensor_nivelBufferAlto(27);
Sensor_nivel sensor_nivelBufferBajo(27);
Sensor_nivel sensor_nivelReservorioAlto(27);
Sensor_nivel sensor_nivelReservorioBajo(27);

Cubeta cubeta { Bomba{13} };
Buffer bbuffer { Bomba{13}, sensor_nivelBufferBajo, sensor_nivelBufferAlto};
Reservorio reservorio {cubeta, sensor_nivelReservorioBajo, sensor_nivelReservorioAlto, Notificador{}};

void setup(){
  pinMode(27, INPUT);
  Serial.begin(115200);
  }

void loop(){
        if (i ==20)
        bbuffer.tick(10);
        reservorio.tick(10);
        delay(200);
    }
