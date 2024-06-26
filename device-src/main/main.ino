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
#include <ctype.h>
#include "drivers.hpp"
#include "device_info.hpp"
#include "packets.hpp"
#include "topics.hpp"
#include <esp32-hal-gpio.h>

#define FRAME_TIME 10000

// Wifi information
const char *ssid = "GirlsOnly";
const char *passwd = "CoffeeMakesMePoop";
const char *server = "192.168.1.153";
uint16_t port = 1883;

// Holds the human-readable device id.
char devid[32];

// Keeps the wifi connection alive.
WiFiClient wifi_client;

// Communicates with the mqtt server.
PubSubClient mqtt_client(wifi_client);

// Holds the info dictating device operation.
device_info_t info;

// Indicates whether a packet was received in the current frame.
bool received = false;

// Handle that keeps the mqtt connection alive.
TaskHandle_t mqtt_task_handle;

/**
 * Convert a text packet into a motor packet.
 * 
 * The command should start with "turn". After that,
 * you may specify "motor" followed by a motor number.
 * If no motor number is specified, motor 0 is used.
 * Then, specify the number of steps or degrees. You may
 * specify whether the number is steps or degrees. If no
 * units are specified, degrees are assumed.
 * 
 * @param out The motor packet output.
 * @param input The input buffer containing the text.
 * @param size The length of the packet.
 * @return 0 on success, -1 on failure.
 */
int convert_text(motor_packet *out, const uint8_t *input, int size) {
  if(strncasecmp("turn", (const char *) input, 5) != 0) {
    return -1;
  }
  int i = 5;
  // Skip spaces
  while(isblank(input[i])) {
    i++;
  }

  if(strncasecmp("motor", (const char *) input + i, (size - i < 5)? size - i: 5) == 0) {
    i += 5;
    // Skip spaces
    while(isblank(input[i])) {
      i++;
    }
    uint8_t motor;
    sscanf((const char *) input + i, "%hhu", &motor);
    out->motor = motor;
    while(!isblank(input[i])) {
      i++;
    }
  } else {
    out->motor = 0;
  }

  int32_t turns;
  sscanf((const char *) input + i, "%d", &turns);

  while(i < size && !isblank(input[i])) {
    i++;
  }

  if(strncasecmp("step", (const char *) input + i, (size - i < 4)? size - i: 4) == 0) {
    while(i < size && !isblank(input[i])) {
      i++;
    }
    out->steps = *(uint32_t *) &turns;
  } else {
    int32_t temp;
    switch(info.devclass) {
    case TEST_28BYJ:
    case ALTIMETER:
      temp = (int32_t) ((float) turns * 2048.0f / 360.0f);
      out->steps = *(uint32_t *) &temp;
      break;
    case TEST_X27:
    case SPEDOMETER:
    case TACHOMETER:
    case FUEL_GAUGE:
    case OIL_GAUGE:
      temp = (int32_t) ((float) turns * 600.0f / 315.0f);
      out->steps = *(uint32_t *) &temp;
      break;
    default:
      // Don't know how to handle this device class, so assume steps.
      out->steps = *(uint32_t *) &turns;
    }
  }
  return 0;
}

/**
 * When a message is received, dispatch to the appropriate handlers.
 * 
 * @param topic The topic that provided the message.
 * @param payload The message received from the server.
 * @param size The number of bytes in the message.
 */
void handle_message(const char *topic, uint8_t *payload, int size) {
  received = true; // Tell the device that a message was received in this frame.
#ifdef DEBUG
  static const char hex[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
  };
  // Convert payload to hexadecimal.
  Serial.print("Received: ");
  for (int i = 0; i < size; i++) {
    Serial.print(hex[(payload[i] & 0xf0) >> 4]);
    Serial.print(hex[payload[i] & 0x0f]);
  }
  Serial.print('\n');
#endif

  // Packets for passing data to subhandlers.
  motor_packet mpacket;
  seven_seg_packet spacket;

  // Dispatch.
  switch (info.devclass) {
    case TEST_28BYJ:
    case ALTIMETER:
      // Really bad code right here.
      if(size > sizeof(motor_packet) && !convert_text(&mpacket, payload, size)) {
        ;
      } else {
        memcpy(&mpacket, payload, sizeof(motor_packet));
      }

      run_28byj_update(mpacket.steps, mpacket.motor);
      break;
    case TEST_X27:
    case SPEDOMETER:
    case TACHOMETER:
    case FUEL_GAUGE:
    case OIL_GAUGE:
      // Really bad code right here.
      if(size > sizeof(motor_packet) && !convert_text(&mpacket, payload, size)) {
        ;
      } else {
        memcpy(&mpacket, payload, sizeof(motor_packet));
      }

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

  // Start the wifi connection.
  wl_status_t stat = WiFi.begin(ssid, passwd);

  // Handle the wifi status.
  switch (stat) {
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

  // If the connection failed, wait 500 ms and try again.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);  // Wait between retries.
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// Set up the mqtt connection.
void connect_mqtt(void) {
  Serial.println("Connecting to MQTT server.");
  // Repeat until connected.
  while (!mqtt_client.connected()) {
    // Try to connect.
    mqtt_client.connect(devid, NULL, NULL, will_topic, 0, true, "I'm dead.");

    // Get the connection status.
    int state = mqtt_client.state();

    // Handle the connection status.
    switch (state) {
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
    // Wait 500 ms to try again or stabilize.
    delay(500);
  }

  // Set the callback for handling messages.
  mqtt_client.setCallback(handle_message);
}

// Set up the MQTT client.
void setup_mqtt(void) {
  // Set the server information.
  mqtt_client.setServer(server, port);
  // Set the callback for handling messages.
  mqtt_client.setCallback(handle_message);
  // Set how often the connection checks the connection. 15 s.
  mqtt_client.setKeepAlive(15);

  // Set up the connection.
  connect_mqtt();
}

// Set the pin modes.
void setup_pins() {
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
  pinMode(__MR_1, OUTPUT_OPEN_DRAIN);
  pinMode(__MR_2, OUTPUT_OPEN_DRAIN);
}

/**
 * Find the device class. Can be overridden by passing an argument.
 * 
 * @param set_class The class to set. If it is -1, then the device figures out the class based on its pins.
 * @return The device class.
 */
uint8_t get_class(int set_class = -1) {
  if(set_class == -1) {
    uint8_t devcl = 0; // Initialize
    // Read a bit and shift.
    devcl |= digitalRead(DEVCL_4);
    devcl <<= 1;
    devcl |= digitalRead(DEVCL_3);
    devcl <<= 1;
    devcl |= digitalRead(DEVCL_2);
    devcl <<= 1;
    devcl |= digitalRead(DEVCL_1);
    devcl <<= 1;
    devcl |= digitalRead(DEVCL_0);
    return devcl;
  } else {
    return (uint8_t) set_class;
  }
}

// Maintains wifi and mqtt connections.
void mqtt_task(void *ignored) {
  while (true) { // Repeat ad nauseum.
    //mqtt_client.subscribe(info.topic);

    // Try to connect to wifi, if connection is lost.
    while (!WiFi.isConnected()) {
      Serial.println("WiFi disconnected."); // debug.
      delay(10); // Wait between retries.
      setup_wifi(); // Try to connect again.
    }

    // Try to connect to the mqtt server, if connection is lost.
    if (!mqtt_client.connected()) {
      Serial.println("MQTT disconnected."); // debug.
      connect_mqtt(); // Try to connect again.
    }
    // Handle mqtt upkeep and messages.
    mqtt_client.loop();

    // Wait for 10 ms.
    delay(10);
  }
}

// Setup the watchdog timer.
void setup_wdt() {
  // Turn off the real-time clock and calendar watchdog timer. The one that controls the CPU.
  uint32_t *rtc_wdt_config0 = (uint32_t *) 0x3FF4808C;
  *rtc_wdt_config0 &= 0x7fffffff;

  // Turn off the first user-mode watchdog timer. The one that controls the code.
  uint32_t *tmr1_wdt_config0 = (uint32_t *) 0x3FF5F048;
  *tmr1_wdt_config0 &= 0x7fffffff;

  // Turn off the second user-mode watchdog timer. Controls nothing by default.
  uint32_t *tmr2_wdt_config0 = (uint32_t *) 0x3FF60048;
  *tmr2_wdt_config0 &= 0x7fffffff;
}

// Main setup function.
void setup() {

  Serial.begin(9600); // Set up the usb output.

  Serial.println(WiFi.macAddress()); // Print the mac address.

  setup_pins(); // Setup the IO pins to their defaults.

  info.devclass = (device_class_t)get_class(); // Get the device class, or what devices this controls.
  WiFi.macAddress((uint8_t *) &(info.devid)); // Set the device id. Use the mac address, since it is unique.

  sprintf(devid, "dev%ld", info.devid); // Set the device name.

  setup_wifi(); // Setup the wifi connection.
  setup_mqtt(); // Setup the mqtt connection.
  setCpuFrequencyMhz(240); // Set the cpu frequency for wifi compatibility.

  // Setup the connected devices.
  switch (info.devclass) {
    case TEST_28BYJ:
    case ALTIMETER:
      setup_28byj(info, mqtt_client); // Setup the 28byj devices.
      break;
    case TEST_X27:
    case SPEDOMETER:
    case TACHOMETER:
    case FUEL_GAUGE:
    case OIL_GAUGE:
      setup_x27(info, mqtt_client); // Setup the x27 devices.
      break;
    case TEST_7S_DISPLAY:
    case RADIO:
      setup_7seg(info, mqtt_client); // Setup the 7-segment display devices.
      break;
    default:
      break;
  }

  xTaskCreate(mqtt_task, "mqtt_task", 10000, NULL, 0, &mqtt_task_handle); // Create a repeating task to make sure connection is maintained.
}

// Main loop.
void loop() {
  // Time remaining in the frame.
  uint32_t diff = 0;

  // Do this if there is an output device attached.
  switch (info.devclass) {
    case TEST_28BYJ:
    case ALTIMETER:
      diff = run_28byj_loop(); // do this if the output relies on a 28byj motor.
      break;
    case TEST_X27:
    case SPEDOMETER:
    case TACHOMETER:
    case FUEL_GAUGE:
    case OIL_GAUGE:
      diff = run_x27_loop(); // do this if the output relies on an x27 motor.
      break;
    case TEST_7S_DISPLAY:
    case RADIO:
    case CLOCK:
      diff = run_7seg_loop(); // Do this if the output is a 7-segment led display.
      break;
  }

  // Do this if there is an input device attached.
  switch(info.devclass) {
    case RADIO: // do this if there is a radio attached.
      diff += radio_interface_loop(mqtt_client);
      break;
    case ENGINE_STARTER: // do this if there is an engine starter attached.
      diff += engine_starter_loop(mqtt_client);
      break;
  }

  received = false; // Reset the received variable.
  if (diff < FRAME_TIME) { // If there is time left in the frame, wait it out.
    delayMicroseconds(FRAME_TIME - diff); // Pad out the frame by waiting for the rest of the frame.
  }
}
