/*
 * main.ino
 * 
 * This is the main file for the PilotWave project.
 */

#include <PubSubClient.h>
#include <WiFi.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "drivers.hpp"
#include "device_info.hpp"
#include "packets.hpp"
#include "topics.hpp"

const char *ssid = "briggs";
const char *passwd = "h0p0np0p";
const char *server = "Little-Pink.local";
uint16_t port = 1883;

char devid[32];

WiFiClient wifi_client;

PubSubClient mqtt_client(wifi_client);

device_info_t info;
bool received = false;

void handle_message(const char *topic, uint8_t *payload, int size) {
  received = true;
  Serial.print("Received: ");
  Serial.println((char *) payload);
  switch(info.devclass) {
  case TEST_28BYJ:
    motor_packet packet;
    memcpy(&packet, payload, sizeof(motor_packet));

    run_28byj_update(packet.steps, packet.motor);
    break;
  }
}

// Set up the WiFi module.
void setup_wifi(void) {
  delay(10);  // Give a bit of room for setup.
  Serial.println("Setting up WiFi.");
  wl_status_t stat = WiFi.begin(ssid, passwd);

  switch(stat) {
  case WL_NO_SHIELD:
    Serial.println("No shield.");
    break;
  case WL_IDLE_STATUS:
    Serial.println("Idle");
    break;
  case WL_NO_SSID_AVAIL:
    Serial.println("No SSID available.");
    break;
  case WL_SCAN_COMPLETED:
    Serial.println("Scan complete.");
    break;
  case WL_CONNECTED:
    Serial.println("Connected.");
    break;
  case WL_CONNECT_FAILED:
    Serial.println("Failed to connect.");
    break;
  case WL_CONNECTION_LOST:
    Serial.println("Connection lost.");
    break;
  case WL_DISCONNECTED:
    Serial.println("Disconnected.");
    break;
  default:
    Serial.println("Unknown status code.");
  }
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500); // Wait between retries.
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void connect_mqtt(void) {
  // Set the device ID.
  //sprintf(message_buffer, "Device %d", dev_id);
  //uint32_t payload = ERROR | ((uint32_t) dev_id << 8) | ((uint32_t) dev_class << 16);
  Serial.println("Connecting to MQTT server.");
  while(!mqtt_client.connected()) {
    mqtt_client.connect(devid, NULL, NULL, will_topic, 0, true, "I'm dead.");
    
    int state = mqtt_client.state();

    switch(state) {
    case -4:
      Serial.println("Timeout.");
      break;
    case -3:
      Serial.println("Connection lost.");
      break;
    case -2:
      Serial.println("Connection failed.");
      break;
    case -1:
      Serial.println("Clean disconnect.");
      break;
    case 0:
      Serial.println("Connected");
      break;
    case 1:
      Serial.println("Protocol not supported.");
      break;
    case 2:
      Serial.println("Bad client id.");
      break;
    case 3:
      Serial.println("Server could not accept connection.");
      break;
    case 4:
      Serial.println("Incorrect username or password.");
      break;
    case 5:
      Serial.println("Unauthorized to connect.");
      break;
    default:
      Serial.println("Unknown status code.");
      break;
    }
    delay(500);
  }

  mqtt_client.setCallback(handle_message);
}

// Set up the MQTT client.
void setup_mqtt(void) {
  mqtt_client.setServer(server, port);
  mqtt_client.setCallback(handle_message);
  mqtt_client.setKeepAlive(15);
  
  connect_mqtt();
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  info.devclass = TEST_28BYJ;
  info.devid = 0;
  info.topic = test_28byj_topic;

  sprintf(devid, "dev%d", info.devid);

  setup_wifi();
  setup_mqtt();
  setCpuFrequencyMhz(240);

  switch(info.devclass) {
  case TEST_28BYJ:
    setup_28byj(info, mqtt_client);
    break;

  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  mqtt_client.subscribe(info.topic);

  while(!WiFi.isConnected()) {
    Serial.println("WiFi disconnected.");
    delay(10);
    setup_wifi();
  }

  if(!mqtt_client.connected()) {
    Serial.println("MQTT disconnected.");
    connect_mqtt();
  }
  mqtt_client.loop();

  int diff = 0;

  switch(info.devclass) {
  case TEST_28BYJ:
    diff = run_28byj_loop();
    break;
  }

  if(received) {
    Serial.println("Received!");
  } else {
    Serial.println("Not received.");
  }
  received = false;
  delayMicroseconds(30000 - diff);
}
