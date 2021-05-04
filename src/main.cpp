#include <Arduino.h>
#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char* WIFI_SSID = "Pipit dewi";
const char* WIFI_PASS = "Omas5758";
const char* HOSTNAME = "labda";

OneWire oneWire(4);
DallasTemperature sensors(&oneWire);

float getAmbientTemperature()
{
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");

  float tempC = sensors.getTempCByIndex(0);

  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
    return tempC;
  } 
  else
  {
    Serial.println("Error: Could not read temperature data");
    return -127;
  }
}


void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  WiFi.setHostname(HOSTNAME);
  
  Serial.print("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("WiFi connected successfully.");

  sensors.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float suhu = getAmbientTemperature();
  delay(3000);
}