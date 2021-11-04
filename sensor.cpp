#include "sensor.h"
#include <WiFi.h>           // WiFi control for ESP32
#include <ThingsBoard.h>    // ThingsBoard SDK

#define DHTPIN 33     // what digital pin we're connected to


// Helper macro to calculate array size
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// WiFi access point
#define WIFI_AP_NAME       "Carlajijiji"// "WIFI_AP"
// WiFi password
#define WIFI_PASSWORD      "candy115"// "WIFI_PASSWORD"

// See https://thingsboard.io/docs/getting-started-guides/helloworld/
// to understand how to obtain an access token
#define TOKEN              "lGhZDVbx1y5M0cm8WM8o" // "TOKEN"
// ThingsBoard server instance.
#define THINGSBOARD_SERVER  "demo.thingsboard.io"

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
unsigned long millis_counter;


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

// Setup an application
void setup() {
  // Initialize serial for debugging
  Serial.begin(SERIAL_DEBUG_BAUD);
  WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
  InitWiFi();
}



//-------------------------------------------------------------------------------
//Sensor constructor
sensor::sensor(int temperatura, int ec, int ph, int nivel_reservorio)
{
	m_temperatura = temperatura;
	m_ec = ec;
	m_ph = ph;
	m_nivel_reservorio = nivel_reservorio;
}

//Sensor member function
void set_temperatura(int temp){temperatura = temp;}

void set_EC(int ecc){ec = ecc;}

void set_nivel_reservorio(int nivel_reser){nivel_reservorio = nivel_reser;}

void set_PH(int phh){ph = phh;}
//-------------------------------------------------------------------------------


void actualizar_thingsboard(int temperatura, int ec, int ph, int nivel_reservorio)
{
  // Reconnect to WiFi, if needed
  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
    return;
  }


  // Reconnect to ThingsBoard, if needed
  if (!tb.connected()) {
    // Connect to the ThingsBoard
    Serial.print("Connecting to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
    }
  }

  // Check if it is a time to send DHT11 temperature and humidity
  if(millis()-millis_counter > send_delay) {
    Serial.println("Sending data...");
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

      tb.sendTelemetryFloat("temperature", temperatura);
      tb.sendTelemetryFloat("nivel reservorio", nivel_reservorio);
	  tb.sendTelemetryFloat("ec", ec);
      tb.sendTelemetryFloat("ph", ph);
    }

  millis_counter = millis(); //reset millis counter
}
