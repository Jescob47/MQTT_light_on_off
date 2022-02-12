#ifndef CONNECT_H
#define CONNECT_H

#include <Arduino.h>
#include <constants.h>
#include <WiFi.h>
#include <MQTT.h>



void connect(Stream &uart, WiFiClient &wifi, MQTTClient &client){
  uart.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    uart.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect(MQTT_ID, MQTT_USER, MQTT_PASSWORD)) {
    uart.print(".");
    delay(1000);
  }
  uart.println("\nconnected!");
  client.subscribe(String(TOPIC)+"/#");
}

#endif