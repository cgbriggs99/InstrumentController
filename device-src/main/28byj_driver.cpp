#include "device_info.hpp"
#include "drivers.hpp"
#include <PubSubClient.h>
#include "topics.hpp"
#include "packets.hpp"
#include "shift.hpp"
#include <stdint.h>

// Dictate where the motors should turn. Initialize to somewhere in the middle.
static uint32_t last_goals[] = {0x7fffffff, 0x7ffffff};
static uint32_t curr_goals[] = {0x7fffffff, 0x7ffffff};
// Whether or not the device is calibrated.
static uint8_t is_calibrated = 0;

#define MOTOR_WAIT 1000
#define STEPS_PER_FRAME 8
#define STEPS_PER_ROTATION 256

// Bit patterns for the coils.
static const uint8_t pattern[] = {
  0x7, 0x3, 0xb, 0x9, 0xd, 0xc, 0xe, 0x6
};

// Set up the device specific connection info.
void setup_28byj(device_info_t info, PubSubClient &client) {

  // Subscribe to the appropriate topic.
  switch (info.devclass) {
    case TEST_28BYJ:
      client.subscribe(test_28byj_topic);
      break;
    case ALTIMETER:
      client.subscribe(altimeter_topic);
      break;
  }

  // Create the device info packet to publish.
  device_info_packet packet = { info.devclass, info.devid };

  // Publish the packet.
  client.publish(dev_info_topic, (uint8_t *) &packet, sizeof(device_info_packet));
}

// Update the device.
void run_28byj_update(uint32_t steps, uint8_t motor) {
  // Update the goals so that it starts spinning in the correct direction.
  curr_goals[motor] = steps;
};

uint32_t get_28byj_goal(uint8_t motor) {
  return curr_goals[motor];
};

// Move the motor.
uint32_t run_28byj_loop(void) {
  // If the motors are at their goals, don't move them.
  bool quit = true;

  // This turns the loop into a list of statements rather than a loop.
#pragma unroll
  // Check if the motors are at their goals.
  for (int i = 0; i < 2; i++) {
    if (curr_goals[i] != last_goals[i]) {
      quit = false;
    }
  }

  // If the motors are at their goals, exit.
  if (quit) {
    return 0;
  }

  // The motors need to be moved.
  for (int i = 0; i < STEPS_PER_FRAME; i++) {
    // Update the motors' states.
#pragma unroll
    for (int j = 0; j < 2; j++) {
      // Incement if the current goal is higher, decrement if lower.
      if (last_goals[j] < curr_goals[j]) {
        last_goals[j]++;
      } else if (last_goals[j] > curr_goals[j]) {
        last_goals[j]--;
      }
    }

    // Take the patterns for the current position and package them up.
    uint8_t data = pattern[last_goals[0] % 8] | (pattern[last_goals[1] % 8] << 4);

    // Send the patterns to the shift register.
    shift_out(&data, 1);

    // Wait for the coils to charge and the motor to travel.
    delayMicroseconds(MOTOR_WAIT);
  }

  // Return the number of microseconds spent in the function.
  return STEPS_PER_FRAME * MOTOR_WAIT;
}
