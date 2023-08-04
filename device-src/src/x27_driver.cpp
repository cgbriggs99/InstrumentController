#include "device_info.hpp"
#include "drivers.hpp"
#include <PubSubClient.h>
#include "topics.hpp"

static uint16_t last_goals[3] = {0, 0, 0},
  uint16_t curr_goals[3] = {0, 0, 0};
static uint8_t is_calibrated = 0;

#define MOTOR_WAIT 10000
#define STEPS_PER_FRAME 10


void setup_x27(device_info_t info, PubSubClient &client) {
  // Subscribe to the appropriate topic.
  switch(info.devclass) {
  case TEST_X27:
    client.subscribe(test_x27_topic);
    break;
  }

  // Create the device info packet to publish.
  device_info_packet packet = { info.devclass, info.devid };

  // Publish the packet.
  client.publish(dev_info_topic, (uint8_t *) &packet, sizeof(device_info_packet));
}


  

  

