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
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
 
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

boolean ALARMA = false;
int botonPOWER = 19;
int botonDISP = 4;
int botonACC = 23;

String msgScroll = "PH=0,EC=0,T=0C,NR=0";

#define DHTPIN 33     // what digital pin we're connected to


// Helper macro to calculate array size
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// WiFi access point
#define WIFI_AP_NAME       "MOVISTAR_1D20"// "WIFI_AP"
// WiFi password
#define WIFI_PASSWORD      "bKo5BVRDeTfGLtgqCiRz"// "WIFI_PASSWORD"

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

WebServer server(80);

/*
 * Login page
 */
const char* host = "esp32";

const char* loginIndex =
 "<form name='loginForm'>"
    "<table width='20%' bgcolor='A09F9F' align='center'>"
        "<tr>"
            "<td colspan=2>"
                "<center><font size=4><b>ESP32 Login Page</b></font></center>"
                "<br>"
            "</td>"
            "<br>"
            "<br>"
        "</tr>"
        "<tr>"
             "<td>Username:</td>"
             "<td><input type='text' size=25 name='userid'><br></td>"
        "</tr>"
        "<br>"
        "<br>"
        "<tr>"
            "<td>Password:</td>"
            "<td><input type='Password' size=25 name='pwd'><br></td>"
            "<br>"
            "<br>"
        "</tr>"
        "<tr>"
            "<td><input type='submit' onclick='check(this.form)' value='Login'></td>"
        "</tr>"
    "</table>"
"</form>"
"<script>"
    "function check(form)"
    "{"
    "if(form.userid.value=='admin' && form.pwd.value=='admin')"
    "{"
    "window.open('/serverIndex')"
    "}"
    "else"
    "{"
    " alert('Error Password or Username')/*displays error message*/"
    "}"
    "}"
"</script>";

/*
 * Server Index Page
 */

const char* serverIndex =
"<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>"
"<form method='POST' action='#' enctype='multipart/form-data' id='upload_form'>"
   "<input type='file' name='update'>"
        "<input type='submit' value='Update'>"
    "</form>"
 "<div id='prg'>progress: 0%</div>"
 "<script>"
  "$('form').submit(function(e){"
  "e.preventDefault();"
  "var form = $('#upload_form')[0];"
  "var data = new FormData(form);"
  " $.ajax({"
  "url: '/update',"
  "type: 'POST',"
  "data: data,"
  "contentType: false,"
  "processData:false,"
  "xhr: function() {"
  "var xhr = new window.XMLHttpRequest();"
  "xhr.upload.addEventListener('progress', function(evt) {"
  "if (evt.lengthComputable) {"
  "var per = evt.loaded / evt.total;"
  "$('#prg').html('progress: ' + Math.round(per*100) + '%');"
  "}"
  "}, false);"
  "return xhr;"
  "},"
  "success:function(d, s) {"
  "console.log('success!')"
 "},"
 "error: function (a, b, c) {"
 "}"
 "});"
 "});"
 "</script>";


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
  pinMode(19, INPUT);
  pinMode(4, INPUT);
  pinMode(23, INPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  Serial.begin(115200);
      // Initialize serial for debugging
  delay(500);
  WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
  delay(500);
  InitWiFi();
  delay(500);

  lcd.begin(16, 2);

  if (!MDNS.begin(host)) { //http://esp32.local
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");
  /*return index page which is stored in serverIndex */
  server.on("/", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", loginIndex);
  });
  server.on("/serverIndex", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", serverIndex);
  });
  /*handling uploading firmware file */
  server.on("/update", HTTP_POST, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
    ESP.restart();
  }, []() {
    HTTPUpload& upload = server.upload();
    if (upload.status == UPLOAD_FILE_START) {
      Serial.printf("Update: %s\n", upload.filename.c_str());
      if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { //start with max available size
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_WRITE) {
      /* flashing firmware to ESP*/
      if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_END) {
      if (Update.end(true)) { //true to set the size to the current progress
        Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
      } else {
        Update.printError(Serial);
      }
    }
  });
  server.begin();
  }


void loop(){
  server.handleClient();
  if (WiFi.status() != WL_CONNECTED) {
    reconnect();
  return;
  }
  ronda = (ronda+1)%3;
  if (ronda ==0){
    phv = sensor_ph.read()*15/4098;
    adcAttachPin(13);
  }
  if (ronda ==1){
    ecv = sensor_ec.read()*5/4098;
    adcAttachPin(34);
  }
  if (ronda ==2){
    turbidezv = sensor_turbidez.read()*20/4098;
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

  if (turbidezv<18){ //esto funciona sólo si hay una alarma en el momento
    lcd.print("ALARMA TURBIDEZ"); //cuando hay más de una alarma, hay problemas, porque solo imprime una
    ALARMA=true;                  //deberiamos ordenar las alarmas por prioridades
  }else if ((phv<5.5) or (phv>7.5)){ //comprobar valores
            lcd.print("ALARMA PH");
            ALARMA=true;
            }else if ((ecv<0) or (ecv>2)){
                      lcd.print("ALARMA TURBIDEZ");
                      ALARMA=true;
                    }else if (nivelv==0){
                                lcd.print("ALARMA N_RESERVORIO");
                                ALARMA=true;
                              }else ALARMA=false;
  
      //incluir condiciones de Alarma
  if (ALARMA){
    lcd.print("ALARMA");
    scrollText(1,msgScroll,100,16);
  }
  else{
    lcd.setCursor(0, 0);
    msgScroll = "PH="; 
    msgScroll = msgScroll + String(phv);
    msgScroll = msgScroll + ",EC=" ;
    msgScroll = msgScroll + String(ecv);
    lcd.print(msgScroll);

    lcd.setCursor(1, 0);
    msgScroll = ",T=" ;
    msgScroll = msgScroll + String(turbidezv);
    msgScroll = msgScroll + ",NR=";
    msgScroll = msgScroll + String(nivelv);
    lcd.print(msgScroll);
  }
    bbuffer.tick(10);
    reservorio.tick(10);
    delay(200);
  }