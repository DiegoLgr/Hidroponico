#include <Arduino.h>
#include <WiFi.h>           // WiFi control for ESP32
#include <ThingsBoard.h>    // ThingsBoard SDK

#include "sensor.h"
#define THINGSBOARD_SERVER  "demo.thingsboard.io"
#define TOKEN              "lGhZDVbx1y5M0cm8WM8o" // "TOKEN"
//-------------------------------------------------------------------------------
//Sensor constructor
Sensor::Sensor(int temperatura1, int ec1, int ph1, int nivel_reservorio1, ThingsBoard tb1)
 {
    temperatura0=temperatura1;
    ec0=ec1;
    ph0=ph1;
    nivel_reservorio0=nivel_reservorio1;
    tb0=tb1;
  }

//Sensor member function
void Sensor::set_temperatura(int temperatura){temperatura0 = temperatura;}

void Sensor::set_EC(int ec){ec0 = ec;}

void Sensor::set_nivel_reservorio(int nivel_reservorio){nivel_reservorio0 = nivel_reservorio;}

void Sensor::set_PH(int ph){ph0 = ph;}
//-------------------------------------------------------------------------------
void Sensor::actualizar_thingsboard(int temperatura, int ec, int ph, int nivel_reservorio)
{


  // Reconnect to ThingsBoard, if needed
  if (!tb0.connected()) {
    // Connect to the ThingsBoard
    Serial.print("Connecting to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);
    if (!tb0.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
    }
  }


if (isnan(temperatura) || isnan(ec) || isnan(ph) || isnan(nivel_reservorio)) {
      Serial.println("Failed to read from DHT sensor!");
    } else {
      Serial.print("Temperature:");
      Serial.print(temperatura);
      Serial.print(" Sales ");
      Serial.println(ec);
	  Serial.print(" pH ");
      Serial.println(ph);
	  Serial.print(" Nivel reservorio ");
      Serial.println(nivel_reservorio);
      tb0.sendTelemetryFloat("temperature", temperatura);
      tb0.sendTelemetryFloat("nivel reservorio", nivel_reservorio);
	  tb0.sendTelemetryFloat("ec", ec);
      tb0.sendTelemetryFloat("ph", ph);
    }
}
