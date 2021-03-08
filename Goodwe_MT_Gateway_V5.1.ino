#include <ModbusRTU.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

uint16_t Mread[20];
uint16_t Mread1[1];
int Call_Stp = 1;
int Slave_ID = 1;

ModbusRTU mb;
WiFiClient Goodwe_MT;
PubSubClient client(Goodwe_MT);
#define MQTT_MAX_PACKET_SIZE 512

#include "Settings.h"
#include "IntToFloat.h"
#include "Data_Structure.h"
#include "MoveData.h"
#include "Modbus_callback.h"
#include "JsonPack.h"
#include "Modbus_Slave_Query.h"
#include "MQTT.h"
#include "WIFISet.h"

SoftwareSerial S(Rx, Tx);

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  S.begin(9600, SWSERIAL_8N1);
  Slave_ID = Start_ID;
  mb.begin(&S);
  mb.master();
  if (MQTT_Enable) {
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    String MQTT_Topic_s = MQTT_Topic;
    MQTT_Topic_s = MQTT_Topic_s + "-%ld"; 
    MQTT_Topic_s.toCharArray(MQTT_Topic,(MQTT_Topic_s.length() + 1));
    Serial.println((MQTT_Topic_s.length() + 1));
  }
}
void loop() {
  if (millis() - LastScan > Interval) {
    MBslaveQuery(Slave_ID);
  }
  if (MQTT_Enable) {
    if (!client.connected()) {
      long now = millis();
      if (now - lastReconnectAttempt > MQTT_Re_Connect_Interval) {
        lastReconnectAttempt = now;
        if (reconnect()) {
          lastReconnectAttempt = 0;
        }
      }
    }
    else client.loop();
  }
  mb.task();
  yield();
}
