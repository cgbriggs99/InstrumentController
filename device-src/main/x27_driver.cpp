#include "device_info.hpp"
#include "drivers.hpp"
#include <PubSubClient.h>
#include "topics.hpp"
#include "packets.hpp"
#include "shift.hpp"

static uint16_t last_goal = 0,
                curr_goal = 0;
static uint8_t is_calibrated = 0;

#define MOTOR_WAIT 1000
#define STEPS_PER_FRAME 8

/*
static const uint8_t pattern[] = {
  9, 1, 4, 6, 2, 8
};
*/

static const uint8_t pattern[] = {
  9, 8, 2, 6, 4, 1
};

void setup_x27(device_info_t info, PubSubClient &client) {
  Serial.printf("Setting up x27 device.\n");
  // Subscribe to the appropriate topic.
  switch (info.devclass) {
    case TEST_X27:
      client.subscribe(test_x27_topic);
      break;
  }

  // Create the device info packet to publish.
  device_info_packet packet = { info.devclass, info.devid };

  // Publish the packet.
  client.publish(dev_info_topic, (uint8_t *)&packet, sizeof(device_info_packet));
}

uint16_t run_x27_loop(void) {
    uint16_t ret = abs(last_goal - curr_goal);
    if(ret > STEPS_PER_FRAME) {
      ret = STEPS_PER_FRAME;
    }
    
    for (int i = 0; i < STEPS_PER_FRAME && last_goal != curr_goal; i++) {
      if (last_goal < curr_goal) {
        last_goal++;
      } else if (last_goal > curr_goal) {
        last_goal--;
      }

      shift_out(pattern + last_goal % 6, 1);

      delayMicroseconds(MOTOR_WAIT);
      digitalWrite(OE_1, HIGH);
    }
    return ret * MOTOR_WAIT;
}

void run_x27_update(uint32_t steps) {
  curr_goal = steps;
}
