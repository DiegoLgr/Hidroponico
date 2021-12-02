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

int ronda =0;
int i = 0;
int nivelv;
float phv, ecv, turbidezv;
rgb_lcd lcd;

Sensor_nivel sensor_nivelBufferAlto(32);
Sensor_nivel sensor_nivelBufferBajo(35);
Sensor_nivel sensor_nivelReservorioAlto(25);
Sensor_nivel sensor_nivelReservorioBajo(26);

Sensor_turbidez sensor_turbidez(34);

Sensor_PH sensor_ph(12);

Sensor_EC sensor_ec(33);

Cubeta cubeta { Bomba{14} };
Buffer bbuffer { Bomba{27}, sensor_nivelBufferBajo, sensor_nivelBufferAlto};
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
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(35, INPUT);
  pinMode(12, INPUT);
  pinMode(35, INPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  
  Serial.begin(115200);
  lcd.begin(16, 2);
      // Initialize serial for debugging
  WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
  InitWiFi();
  }


void loop(){
  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  return;
  }
  ronda = (ronda+1)%3;
  if (ronda ==0){
    phv = sensor_ph.read();
    adcAttachPin(13);
  }
  if (ronda ==1){
    ecv = sensor_ec.read();
    adcAttachPin(34);
  }
  if (ronda ==2){
    turbidezv = sensor_turbidez.read();
    adcAttachPin(12);
  }
  nivelv = sensor_nivelReservorioBajo.read();
  Serial.print("sensor buffer bajo");
  Serial.println(sensor_nivelBufferBajo.read());
  nuevo_sensor.actualizar_thingsboard(turbidezv, ecv, phv, nivelv);
  
  msgScroll = "PH="; 
  msgScroll = msgScroll + String(phv);
  msgScroll = msgScroll + ",EC=" ;
  msgScroll = msgScroll + String(ecv);
  msgScroll = msgScroll + ",T=" ;
  msgScroll = msgScroll + String(turbidezv);
  msgScroll = msgScroll + ",NR=";
  msgScroll = msgScroll + String(nivelv);
        
  lcd.setCursor(0, 0);

      //incluir condiciones de Alarma
  if (true)
    lcd.print("ALARMA");
 // scrollText(1,msgScroll,250,16);
  
    bbuffer.tick(10);
    reservorio.tick(10);
    delay(500);
  }
  
