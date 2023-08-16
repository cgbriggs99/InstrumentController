#include "seven-seg.hpp"
#include "drivers.hpp"
#include <stdint.h>

static uint8_t displays;
static uint8_t digits_per_display = 8;
static uint8_t *pattern;
static size_t size;

void setup_7seg(device_info_t info, PubSubClient &client) {
  switch(info.class) {
  case TEST_7S_DISPLAY:
    client.subscribe(test_7s_topic);
    displays = 1;
    break;
  }


  pattern = new uint8_t[displays * digits_per_display];
  size = displays * digits_per_display;


  // Create the device info packet to publish.
  device_info_packet packet = { info.devclass, info.devid };

  // Publish the packet.
  client.publish(dev_info_topic, (uint8_t *) &packet, sizeof(device_info_packet));
}

#define DELAY 1000
uint16_t run_7seg_loop(void) {
  // Write the characters.
  for(int i = 0; i < sizeof(pattern); i++) {
    uint16_t data = position[i] << 8 | pattern[i];
    shift_out(&data, 2);
    delayMicroseconds(DELAY);
  }

  return DELAY * size;
}

void run_7seg_update(uint8_t *bit_patterns, uint8_t display) {
  for(int i = 0; i < digits_per_display; i++) {
    pattern[display * digits_per_display + i] = bit_patterns[i];
  }
}
