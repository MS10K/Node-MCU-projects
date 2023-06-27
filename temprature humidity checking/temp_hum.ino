#include "DHT.h"
#define DHTTYPE DHT11
#define dht_dpin D3
DHT dht(dht_dpin, DHTTYPE);
#define SW_VERSION "ThinkSpeak.com"
#include <ESP8266WiFi.h>
WiFiClient client;
const char* MY_SSID = "Sarath";
const char* MY_PWD = "1234";
const char* TS_SERVER = "api.thingspeak.com";
String TS_API_KEY = "0MVY56GXP5TIBR";
void connectWifi() {
  Serial.println("connecting to" + *MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("Wifi Connected");
  Serial.println("");
}
void setup(void) {
  dht.begin();
  Serial.begin(115200);
  delay(10);
  connectWifi();
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Current Humidity +");
  Serial.print(h);
  Serial.print("%   ");
  Serial.print(t);
  Serial.println("C");
  delay(15000);
if(client.connect(TS_SERVER,80))
{
    String postStr = TS_API_KEY;
    postStr += "&field1=";
    postStr += String(h);
    postStr += "&field2=";
    postStr += String(t);
    postStr += "\r \n\r\n";
    client.print("POST,/update HTTP/1.1\n");
    client.print("Host: api.thinkspeak.com \n");
    client.print("Connection: close");
client.print("X-THINGSPEAKAPIKEY: "+ TS_API_KEY+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length:");
client.print("\n\n");
client.print(postStr);
delay(1000);
}
client.stop();
}