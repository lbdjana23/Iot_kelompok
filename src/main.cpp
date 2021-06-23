#include <Arduino.h>
#include <WiFi.h>

const char* WIFI_SSID = "Zoker";
const char* WIFI_PASS = "gus ardhi";
const char* HOSTNAME = "Labda";

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  WiFi.setHostname(HOSTNAME);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Hello Labda");
  Serial.println("WiFi connected successfully.");

}

void loop()
{

}