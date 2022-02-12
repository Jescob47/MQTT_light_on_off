#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <constants.h>
#include <connect.h>
#include <servom.h>

WiFiClient net;
MQTTClient client;

#define servopin 21

bool led_status = false;
long reportTimer = millis();
bool estado;

servom servomotor =servom(servopin);


void inputHandler(String &topic, String &payload)
{
  Serial.println(payload);
  servomotor.mov();
}

void setup()
{
  //put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(SSID, SSID_PASSWORD);
  client.begin(BROKER, net);
  client.onMessage(inputHandler);
  connect(Serial, net, client);
}

void loop()
{
  client.loop();

  delay(10);

  if (!client.connected())
  {
    connect(Serial, net, client);
  }
  
}
