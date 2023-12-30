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
#include <esp32-hal-gpio.h>
#include "soc/rtc_wdt.h"


#define FRAME_TIME 30000

const char *ssid = "briggs";
const char *passwd = "h0p0np0p";
const char *server = "192.168.6.124";
uint16_t port = 1883;

char devid[32];

WiFiClient wifi_client;

PubSubClient mqtt_client(wifi_client);

device_info_t info;
bool received = false;

void handle_message(const char *topic, uint8_t *payload, int size) {
  static const char hex[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
  };
  received = true;
  // Debug.
  Serial.print("Received: ");
  for(int i = 0; i < size; i++) {
    Serial.print(hex[(payload[i] & 0xf0) >> 4]);
    Serial.print(hex[payload[i] & 0x0f]);
  }
  Serial.print('\n');

  motor_packet mpacket;
  seven_seg_packet spacket;

  switch(info.devclass) {
  case TEST_28BYJ:
  case ALTIMETER:
    memcpy(&mpacket, payload, sizeof(motor_packet));

    run_28byj_update(mpacket.steps, mpacket.motor);
    break;
  case TEST_X27:
  case SPEDOMETER:
  case TACHOMETER:
  case FUEL_GAUGE:
  case OIL_GAUGE:
    memcpy(&mpacket, payload, sizeof(motor_packet));

    run_x27_update(mpacket.steps);
    break;
  case TEST_7S_DISPLAY:
  case CLOCK:
  case RADIO:
    memcpy(&spacket, payload, sizeof(seven_seg_packet));

    run_7seg_update(spacket.bit_patterns, spacket.display);
    break;
  }
}

// Set up the WiFi module.
void setup_wifi(void) {
  delay(100);  // Give a bit of room for setup. 

  Serial.printf("Settting up Wifi %s %s\n", ssid, passwd);
  
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

void setup_pins() {
  pinMode(DEVID_0, INPUT);
  pinMode(DEVID_1, INPUT);
  pinMode(DEVID_2, INPUT);
  pinMode(DEVID_3, INPUT);
  pinMode(DEVCL_0, INPUT);
  pinMode(DEVCL_1, INPUT);
  pinMode(DEVCL_2, INPUT);
  pinMode(DEVCL_3, INPUT);
  pinMode(DEVCL_4, INPUT);

  pinMode(DATA_IO, INPUT);
  pinMode(SHCP_1, OUTPUT_OPEN_DRAIN);
  pinMode(SHCP_2, OUTPUT_OPEN_DRAIN);
  pinMode(STCP_1, OUTPUT_OPEN_DRAIN);
  pinMode(STCP_2, OUTPUT_OPEN_DRAIN);
  pinMode(OE_1, OUTPUT_OPEN_DRAIN);
  pinMode(PL_2, OUTPUT_OPEN_DRAIN);
  pinMode(MR_1, OUTPUT_OPEN_DRAIN);
  pinMode(MR_2, OUTPUT_OPEN_DRAIN);
}

uint8_t get_id(void) {
  /*
  uint8_t id = 0;
  id |= digitalRead(DEVID_3);
  id <<= 1;
  id |= digitalRead(DEVID_2);
  id <<= 1;
  id |= digitalRead(DEVID_1);
  id <<= 1;
  id |= digitalRead(DEVID_0);
  */
  return 0;
}

uint8_t get_class(void) {
  /*
  uint8_t devcl = 0;
  devcl |= digitalRead(DEVCL_4);
  devcl <<= 1;
  devcl |= digitalRead(DEVCL_3);
  devcl <<= 1;
  devcl |= digitalRead(DEVCL_2);
  devcl <<= 1;
  devcl |= digitalRead(DEVCL_1);
  devcl <<= 1;
  devcl |= digitalRead(DEVCL_0);
  */
  return TEST_X27;
}

void setup() {

  Serial.begin(9600);

  setup_pins();

  info.devclass = (device_class_t) get_class();
  info.devid = get_id();

  switch(info.devclass) {
  case TEST_X27:
    info.topic = test_x27_topic;
    break;
  case TEST_28BYJ:
    info.topic = test_28byj_topic;
    break;
  case TEST_7S_DISPLAY:
    info.topic = test_7s_topic;
    break;
  case ALTIMETER:
    info.topic = altimeter_topic;
    break;
  case SPEDOMETER:
    info.topic = spedometer_topic;
    break;
  case TACHOMETER:
    info.topic = tachometer_topic;
    break;
  case CLOCK:
    info.topic = clock_topic;
    break;
  case FUEL_GAUGE:
    info.topic = fuel_gauge_topic;
    break;
  case OIL_GAUGE:
    info.topic = oil_gauge_topic;
    break;
  case RADIO:
    info.topic = radio_output_topic;
    break;
  default:
    info.topic = nullptr;
    break;
  }

  sprintf(devid, "dev%d", info.devid);

  setup_wifi();
  setup_mqtt();
  setCpuFrequencyMhz(240);

  switch(info.devclass) {
  case TEST_28BYJ:
  case ALTIMETER:
    setup_28byj(info, mqtt_client);
    break;
  case TEST_X27:
  case SPEDOMETER:
  case TACHOMETER:
  case FUEL_GAUGE:
  case OIL_GAUGE:
    setup_x27(info, mqtt_client);
    break;
  case TEST_7S_DISPLAY:
  case RADIO:
    setup_7seg(info, mqtt_client);
    break;
  default:
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

  // Output classes.
  switch(info.devclass) {
  case TEST_28BYJ:
  case ALTIMETER:
    diff = run_28byj_loop();
    break;
  case TEST_X27:
  case SPEDOMETER:
  case TACHOMETER:
  case FUEL_GAUGE:
  case OIL_GAUGE:
    diff = run_x27_loop();
    break;
  case TEST_7S_DISPLAY:
  case RADIO:
  case CLOCK:
    diff = run_7seg_loop();
    break;
  }

  // Input classes.
  switch(info.devclass) {
  case RADIO:
    diff += radio_interface_loop(mqtt_client);
    break;
  case ENGINE_STARTER:
    diff += engine_starter_loop(mqtt_client);
    break;
  }

  received = false;
  if(diff < FRAME_TIME) {
    delayMicroseconds(FRAME_TIME - diff);
  }
}
