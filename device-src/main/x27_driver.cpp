#include "device_info.hpp"
#include "drivers.hpp"
#include <PubSubClient.h>
#include "topics.hpp"
#include "packets.hpp"
#include "shift.hpp"

// Where the motor is and needs to be.
static uint16_t last_goal = 0,
                curr_goal = 0;
// Whether or not the device is calibrated.
static uint8_t is_calibrated = 0;

#define MOTOR_WAIT 1000
#define STEPS_PER_FRAME 8

/*
  static const uint8_t pattern[] = {
  9, 1, 4, 6, 2, 8
  };
*/

// The bit patterns for the motor poles.
static const uint8_t pattern[] = {
  9, 8, 2, 6, 4, 1
};

// Set up the device.
void setup_x27(device_info_t info, PubSubClient &client) {
  Serial.printf("Setting up x27 device.\n");
  // Subscribe to the appropriate topic.
  switch (info.devclass) {
    case TEST_X27:
      client.subscribe(test_x27_topic);
      break;
    case SPEDOMETER:
      client.subscribe(spedometer_topic);
      break;
    case TACHOMETER:
      client.subscribe(tachometer_topic);
      break;
    case FUEL_GAUGE:
      client.subscribe(fuel_gauge_topic);
      break;
    case OIL_GAUGE:
      client.subscribe(oil_gauge_topic);
      break;
  }

  // Create the device info packet to publish.
  device_info_packet packet = { info.devclass, info.devid };

  // Publish the packet.
  client.publish(dev_info_topic, (uint8_t *)&packet, sizeof(device_info_packet));
}

// Move the motor.
uint32_t run_x27_loop(void) {
  // Calculate the number of ticks needed.
  uint16_t ret = abs(last_goal - curr_goal);
  if (ret > STEPS_PER_FRAME) {
    ret = STEPS_PER_FRAME;
  }

  // Do this loop until the end of the frame or until the motor is at its goal.
  for (int i = 0; i < STEPS_PER_FRAME && last_goal != curr_goal; i++) {
    // Increment or decrement the motor.
    if (last_goal < curr_goal) {
      last_goal++;
    } else if (last_goal > curr_goal) {
      last_goal--;
    }

    // Send the new position to the shift register.
    shift_out(pattern + last_goal % 6, 1);

    // Wait for the motor to rotate.
    delayMicroseconds(MOTOR_WAIT);
    // Activate.
    digitalWrite(OE_1, HIGH);
  }
  // Return the number of ticks.
  return ret * MOTOR_WAIT;
}

// Update the motor's goal.
void run_x27_update(uint32_t steps) {
  curr_goal = steps;
}

uint32_t get_x27_goal(void) {
  return curr_goal;
}
