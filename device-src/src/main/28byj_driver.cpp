#include "device_info.hpp"
#include "drivers.hpp"
#include <PubSubClient.h>
#include "topics.hpp"
#include "packets.hpp"

static uint32_t last_goals[] = {0, 0, 0};
static uint32_t curr_goals[] = {0, 0, 0};
static uint8_t is_calibrated = 0;

#define MOTOR_WAIT 10000
#define STEPS_PER_FRAME 10
#define STEPS_PER_ROTATION 256

static const uint8_t pattern[] = {
  0x8, 0xc, 0x4, 0x6, 0x2, 0x3, 0x1, 0x9
};

void setup_28byj(device_info_t info, PubSubClient &client) {

  pinMode(HEADER1_0, OUTPUT);
  pinMode(HEADER1_1, OUTPUT);
  pinMode(HEADER1_2, OUTPUT);
  pinMode(HEADER1_3, OUTPUT);
  pinMode(HEADER2_0, OUTPUT);
  pinMode(HEADER2_1, OUTPUT);
  pinMode(HEADER2_2, OUTPUT);
  pinMode(HEADER2_3, OUTPUT);
  pinMode(HEADER3_0, OUTPUT);
  pinMode(HEADER3_1, OUTPUT);
  pinMode(HEADER3_2, OUTPUT);
  pinMode(HEADER3_3, OUTPUT);

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
  curr_goals[motor] = steps;
};

uint16_t run_28byj_loop(void) {

  for(int i = 0; i < STEPS_PER_FRAME; i++) {
    for(int j = 0; j < 3; j++) {
      if(last_goals[j] < curr_goals[j]) {
	last_goals[j]++;
      } else if(last_goals[j] > curr_goals[j]) {
	last_goals[j]--;
      }
    }
    
    digitalWrite(HEADER1_0,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x8)? HIGH: LOW);
    digitalWrite(HEADER1_1,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x4)? HIGH: LOW);
    digitalWrite(HEADER1_2,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x2)? HIGH: LOW);
    digitalWrite(HEADER1_3,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x1)? HIGH: LOW);
    digitalWrite(HEADER2_0,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x8)? HIGH: LOW);
    digitalWrite(HEADER2_1,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x4)? HIGH: LOW);
    digitalWrite(HEADER2_2,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x2)? HIGH: LOW);
    digitalWrite(HEADER2_3,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x1)? HIGH: LOW);
    digitalWrite(HEADER3_0,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x8)? HIGH: LOW);
    digitalWrite(HEADER3_1,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x4)? HIGH: LOW);
    digitalWrite(HEADER3_2,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x2)? HIGH: LOW);
    digitalWrite(HEADER3_3,
		 (pattern[last_goals[0] % sizeof(pattern)] & 0x1)? HIGH: LOW);
    
    delayMicroseconds(MOTOR_WAIT);
  }
  
  return STEPS_PER_FRAME * MOTOR_WAIT;
}
