#include "device_info.hpp"
#include "drivers.hpp"
#include <PubSubClient.h>
#include "topics.hpp"
#include "packets.hpp"
#include "shift.hpp"
#include <stdint.h>

static uint32_t last_goals[] = {0, 0};
static uint32_t curr_goals[] = {0, 0};
static uint8_t is_calibrated = 0;

#define MOTOR_WAIT 1000
#define STEPS_PER_FRAME 10
#define STEPS_PER_ROTATION 256

static const uint8_t pattern[] = {
  0x7, 0x3, 0xb, 0x9, 0xd, 0xc, 0xe, 0x6
};

void setup_28byj(device_info_t info, PubSubClient &client) {

// Subscribe to the appropriate topic.
  switch(info.devclass) {
  case TEST_28BYJ:
    client.subscribe(test_28byj_topic);
    break;
  }

  // Create the device info packet to publish.
  device_info_packet packet = { info.devclass, info.devid };

  // Publish the packet.
  client.publish(dev_info_topic, (uint8_t *) &packet, sizeof(device_info_packet));
}

void run_28byj_update(uint32_t steps, uint8_t motor) {
  curr_goals[0] = steps;
};

uint16_t run_28byj_loop(void) {
  bool quit = true;
  for(int i = 0; i < 2; i++) {
    if(curr_goals[i] != last_goals[i]) {
      quit = false;
    }
  }
  if(quit) {
    return 0;
  }

  for(int i = 0; i < STEPS_PER_FRAME; i++) {
    for(int j = 0; j < 2; j++) {
      if(last_goals[j] < curr_goals[j]) {
	      last_goals[j]++;
      } else if(last_goals[j] > curr_goals[j]) {
	      last_goals[j]--;
      }
    }

    uint8_t data = pattern[last_goals[0] % 8] | (pattern[last_goals[1] % 8] << 4);

    shift_out(&data, 1);
    
    delayMicroseconds(MOTOR_WAIT);
  }
  
  return STEPS_PER_FRAME * MOTOR_WAIT;
}
