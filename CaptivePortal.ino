#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <FS.h>
#include <ArduinoJson.h>
#include <string.h>
#include "index.h"
#include "wifi.h"
#include "mqtt.h"
#include "miseajour.h"
#include "ipconf.h"
// DNS server
const byte DNS_PORT = 53;
const char * _hote = "", *_port = "", * _user = "", *_passwordm = "", *_topic = "";
      char * my_hote ;
      char * my_port ;
      char * my_user ;
      char * my_passwordm ;
      String my_topic ;
      String my_topiccmd ;
const char * _ip = "", *_masque = "", * _passrelle = "", *_dns = "";
      String my_ip ;
      String my_masque ;
      String my_passrelle ;
      String my_dns ;
      IPAddress fmy_ip;
      IPAddress fmy_masque;
      IPAddress fmy_passrelle;
      IPAddress fmy_dns;
String mac = WiFi.macAddress();
DNSServer dnsServer;
int buttonState1 ;
int buttonState2 ;
int buttonState3 ;

// Web server
ESP8266WebServer server(80);
const char *myHostname = "esp8266";
IPAddress apIP(192, 168, 4, 1);

//uint8_t pin_led = 2;
uint8_t led = 2;
uint8_t pin_led1 = 0;
uint8_t pin_led2 = 15;
uint8_t pin_led3 = 14;


#define sensor 12
#define port1 3
#define port2 13
#define sensorgaz 4


#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define DHTTYPE    DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE);
float t = 0.0;
float h = 0.0;
int sensorState1 = 0;
int val1 = 0; 
int vallast1 = 0; 
int sensorState2 = 0;
int val2 = 0; 
int vallast2 = 0; 
int sensorState3 = 0;
int val3 = 0; 
int vallast3 = 0; 
int sensorState4 = 0;
int val4 = 0; 
int vallast4 = 0; 
unsigned long previousMillis = 0;    // will store last time DHT was updated
const long interval = 2000;  
// Replaces placeholder with DHT values
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return String(t);
  }
  else if(var == "HUMIDITY"){
    return String(h);
  }
  return String();
}



// Stores the previous state of the LED when blinking during long-press
byte led_pin_previous = HIGH;

// Initializes the MQTT reconnect timer.
unsigned long previous_mqtt_reconnect_millis = 0;
WiFiClient espClient;
PubSubClient mqttClient(espClient);

const int RSSI_MAX =-50;// define maximum strength of signal in dBm
const int RSSI_MIN =-100;// define minimum strength of signal in dBm

char* ssid = "YOUR_SSID"; //not used
char* password = "99887766";
char* mySsid = "SMART DEVICE sansor fan";
String st;
String content;
String infoweb;















void setup() {

  Serial.begin(115200);
  delay(11);
  dht.begin();
  SPIFFS.begin();
  pinMode(led, OUTPUT);
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);

  pinMode(sensorgaz, INPUT_PULLUP);
  pinMode(sensor, INPUT_PULLUP);
  pinMode(port1, INPUT_PULLUP);
  pinMode(port2, INPUT_PULLUP);
  digitalWrite(pin_led1,LOW);
  digitalWrite(pin_led2,LOW);
  digitalWrite(pin_led3,LOW);
  
  
  ipp();
  wifiConnect();
  ConfigMqtt();
  StartMdns();
  




   server.on("/update", HTTP_POST, []() {
      server.sendHeader("Connection", "close");
      server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
      ESP.restart();
    }, []() {
      HTTPUpload& upload = server.upload();
      if (upload.status == UPLOAD_FILE_START) {
        Serial.setDebugOutput(true);
        WiFiUDP::stopAll();
        Serial.printf("Update: %s\n", upload.filename.c_str());
        uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
        if (!Update.begin(maxSketchSpace)) { //start with max available size
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_WRITE) {
        if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_END) {
        if (Update.end(true)) { //true to set the size to the current progress
          server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "Update Success Rebooting...");
          Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
        } else {
          Update.printError(Serial);
        }
        Serial.setDebugOutput(false);
      }
      yield();
    });


  server.on("/info", infor);
  server.on("/wifiscan", wifiscan);
  server.on("/bb", switchLedOn);
  server.on("/reinit",reinit);   
  server.on("/redemarrer",redemarrer);  
  server.on("/ipconf",[](){server.send_P(200,"text/html", ipconf);}); 
  server.on("/miseajour",[](){server.send_P(200,"text/html", miseajour);});  
  server.on("/mqtt",[](){server.send_P(200,"text/html", mqtt);});
  server.on("/wifi",[](){server.send_P(200,"text/html", wifi);});
  server.on("/",[](){server.send_P(200,"text/html", webpage);});
  server.on("/toggle1",toggleLED1);
  server.on("/toggle2",toggleLED2);
  server.on("/toggle3",toggleLED3);

  server.on("/settings", HTTP_POST, handleSettingsUpdate);
  server.on("/settings2", HTTP_POST, handleSettingsUpdate2);
  server.on("/settings3", HTTP_POST, handleSettingsUpdate3);
  server.onNotFound(handleNotFound);
  server.begin();

}

void loop() {
  mqttClient.loop();
 MDNS.update();
  dnsServer.processNextRequest();
  server.handleClient();

   if (WiFi.status() != WL_CONNECTED) 
        {
         
        }else{
   if (!mqttClient.connected()) {
    unsigned long current_mqtt_reconnect_millis = millis();

    if (current_mqtt_reconnect_millis - previous_mqtt_reconnect_millis >= 15000) {
      previous_mqtt_reconnect_millis = current_mqtt_reconnect_millis;
      reconnect();
    }
    }
  }







 val1 = digitalRead(sensor);   // read sensor value  
   if (val1 != vallast1) {
    if (val1 == LOW) {
  mqttClient.publish(String(my_topic + "/mvt/status").c_str(), String("off").c_str(), true);   
  Serial.println("Motion no!"); 
    } else {
  mqttClient.publish(String(my_topic + "/mvt/status").c_str(), String("on").c_str(), true);
         Serial.println("Motion detected!"); 
    }
  vallast1 = val1;
  }

 val2 = digitalRead(port1);   // read sensor value  
   if (val2 != vallast2) {
    if (val2 == LOW) {
  mqttClient.publish(String(my_topic + "/door1/status").c_str(), String("off").c_str(), true);   
  Serial.println("port1 open"); 
    } else {
  mqttClient.publish(String(my_topic + "/door1/status").c_str(), String("on").c_str(), true);
         Serial.println("port1 close"); 
    }
  vallast2 = val2;
  }

 val3 = digitalRead(port2);   // read sensor value  
   if (val3 != vallast3) {
    if (val3 == LOW) {
  mqttClient.publish(String(my_topic + "/door2/status").c_str(), String("off").c_str(), true);   
  Serial.println("port2 open"); 
    } else {
  mqttClient.publish(String(my_topic + "/door2/status").c_str(), String("on").c_str(), true);
         Serial.println("port2 close"); 
    }
  vallast3 = val3;
  }

   val4 = digitalRead(sensorgaz);   // read sensor value  
   if (val4 != vallast4) {
    if (val4 == LOW) {
   mqttClient.publish(String(my_topic + "/gaz/status").c_str(), String("off").c_str(), true);   
  Serial.println("gaz open"); 
    } else {
   mqttClient.publish(String(my_topic + "/gaz/status").c_str(), String("on").c_str(), true);
         Serial.println("gaz close"); 
    }
  vallast4 = val4;
  }










  

  delay(60);



  
 unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you updated the DHT values
    previousMillis = currentMillis;
    // Read temperature as Celsius (the default)
    float newT = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    //float newT = dht.readTemperature(true);
    // if temperature read failed, don't change t value
    if (isnan(newT)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
     // Serial.println("Failed to read from DHT sensor!");
      t = newT;
      Serial.print("temp:");
      Serial.println(t);
      mqttClient.publish(String(my_topic + "/temp/status").c_str(), String(t).c_str(), true);
    }
    // Read Humidity
    float newH = dht.readHumidity();
    // if humidity read failed, don't change h value 
    if (isnan(newH)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      h = newH;
      Serial.print("humidity:");
      Serial.println(h);
      mqttClient.publish(String(my_topic + "/hum/status").c_str(), String(h).c_str(), true);


    }
   
  } 
 
}
