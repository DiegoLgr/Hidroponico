#include <iostream>

#include <Wire.h>
#include "rgb_lcd.h"

#include "cubeta.h"
#include "buffer.h"
#include "reservorio.h"
#include "sensor_nivel.h"
#include "bomba.h"
#include "notificador.h"

#include "Sensor_turbidez.h"
#include "Sensor_PH.h"
#include "Sensor_EC.h"

#include <WiFi.h> 
#include <ThingsBoard.h> 
#include "SensorTB.h"

#define ALTO true
#define BAJO false

int i = 0;

rgb_lcd lcd;

Sensor_nivel sensor_nivelBufferAlto(27);
Sensor_nivel sensor_nivelBufferBajo(27);
Sensor_nivel sensor_nivelReservorioAlto(27);
Sensor_nivel sensor_nivelReservorioBajo(27);

Sensor_turbidez sensor_turbidez(11);

Sensor_PH sensor_ph(9);

Sensor_EC sensor_ec(10);

Cubeta cubeta { Bomba{13} };
Buffer bbuffer { Bomba{13}, sensor_nivelBufferBajo, sensor_nivelBufferAlto};
Reservorio reservorio {cubeta, sensor_nivelReservorioBajo, sensor_nivelReservorioAlto, Notificador{}};

String msgScroll = "PH=0,EC=0,T=0C,NR=0";

#define DHTPIN 33     // what digital pin we're connected to


// Helper macro to calculate array size
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// WiFi access point
#define WIFI_AP_NAME       "Carlajijiji"// "WIFI_AP"
// WiFi password
#define WIFI_PASSWORD      "candy115"// "WIFI_PASSWORD"

// See https://thingsboard.io/docs/getting-started-guides/helloworld/
// to understand how to obtain an access token

// ThingsBoard server instance.


// Baud rate for debug serial
#define SERIAL_DEBUG_BAUD    115200

// Initialize ThingsBoard client
WiFiClient espClient;
// Initialize ThingsBoard instance
ThingsBoard tb(espClient);
// the Wifi radio's status
int status = WL_IDLE_STATUS;

// Period of sending a temperature/humidity data.
int send_delay = 2000;



void InitWiFi()
{
  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network

  WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
   }
  Serial.println("Connected to AP");
}

void reconnect() {
  // Loop until we're reconnected
  status = WiFi.status();
  if ( status != WL_CONNECTED) {
    WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("Connected to AP");
  }
}
void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

SensorTB nuevo_sensor(tb);  

void setup(){
  pinMode(27, INPUT);
  Serial.begin(115200);
  lcd.begin(16, 2);
      // Initialize serial for debugging
  Serial.begin(SERIAL_DEBUG_BAUD);
  WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
  InitWiFi();
  }

void loop(){
  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  return;
  }
  

  nuevo_sensor.actualizar_thingsboard(sensor_turbidez.read(), sensor_ec.read(), sensor_ph.read(), sensor_nivelReservorioBajo.read());
  
  msgScroll = "PH="; 
  msgScroll = msgScroll + sensor_ph.read();
  msgScroll = msgScroll + ",EC=" ;
  msgScroll = msgScroll + sensor_ec.read();
  msgScroll = msgScroll + ",T=" ;
  msgScroll = msgScroll + sensor_turbidez.read();
  msgScroll = msgScroll + ",NR=";
  msgScroll = msgScroll + sensor_nivelReservorioBajo.read();
        
  lcd.setCursor(0, 0);

      //incluir condiciones de Alarma
  if (true)
    lcd.print("ALARMA");
  scrollText(1,msgScroll,250,16);
       
  if (i ==20)
    bbuffer.tick(10);
    reservorio.tick(10);
    delay(200);
  }
