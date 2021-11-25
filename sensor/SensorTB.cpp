#include <Arduino.h>
#include <WiFi.h>           // WiFi control for ESP32
#include <ThingsBoard.h>    // ThingsBoard SDK
#include "SensorTB.h"
#define THINGSBOARD_SERVER  "demo.thingsboard.io"
#define TOKEN              "lGhZDVbx1y5M0cm8WM8o" // "TOKEN"

//-------------------------------------------------------------------------------
//Sensor constructor
SensorTB::SensorTB(ThingsBoard tb1)
 {
    tb0=tb1;
  }

//Sensor member function

//-------------------------------------------------------------------------------
void SensorTB::actualizar_thingsboard(int turbidez, int ec, int ph, int nivel_reservorio)
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


if (isnan(turbidez) || isnan(ec) || isnan(ph) || isnan(nivel_reservorio)) {
      Serial.println("Failed to read from sensor!");
    } else {
      Serial.print("Turbidez:");
      Serial.print(turbidez);
      Serial.print(" Sales ");
      Serial.println(ec);
	  Serial.print(" pH ");
      Serial.println(ph);
	  Serial.print(" Nivel reservorio ");
      Serial.println(nivel_reservorio);
      tb0.sendTelemetryFloat("turbidez", turbidez);
      tb0.sendTelemetryFloat("nivel reservorio", nivel_reservorio);
	  tb0.sendTelemetryFloat("ec", ec);
      tb0.sendTelemetryFloat("ph", ph);
    }
}
