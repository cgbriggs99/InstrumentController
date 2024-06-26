#include "seven-seg.hpp"
#include "drivers.hpp"
#include "topics.hpp"
#include "device_info.hpp"
#include "packets.hpp"
#include "shift.hpp"
#include <stdint.h>

// Holds the number of displays.
static uint8_t displays;
// Holds the number of digits in each display.
static uint8_t digits_per_display = 8;
// Holds the current pattern.
static uint8_t *pattern;
// Holds the length of the pattern.
static size_t size;

// Set up the display.
void setup_7seg(device_info_t info, PubSubClient &client) {
  // Subscribe to the correct topic and set the number of displays.
  switch(info.devclass) {
  case TEST_7S_DISPLAY:
    client.subscribe(test_7s_topic);
    displays = 1;
    break;
  }


  // Allocate the pattern array.
  pattern = new uint8_t[displays * digits_per_display];
  size = displays * digits_per_display;


  // Create the device info packet to publish.
  device_info_packet packet = { info.devclass, info.devid };

  // Publish the packet.
  client.publish(dev_info_topic, (uint8_t *) &packet, sizeof(device_info_packet));
}

#define DELAY 1000
// Update the displays.
uint32_t run_7seg_loop(void) {
  // Write the characters.
  for(int i = 0; i < sizeof(pattern); i++) {
    uint16_t data = position[i] << 8 | pattern[i];
    shift_out((uint8_t *) &data, 2);
    // Wait so that the display is visible and not dim.
    delayMicroseconds(DELAY);
  }

  return DELAY * size;
}

// Update the pattern.
void run_7seg_update(uint8_t *bit_patterns, uint8_t display) {
  for(int i = 0; i < digits_per_display; i++) {
    pattern[display * digits_per_display + i] = bit_patterns[i];
  }
}
