#include "drivers.hpp"
#include "topics.hpp"
#include "packets.hpp"
#include "device_info.hpp"
#include <PubSubClient.h>
#include "shift.hpp"

#define RETVAL 10000

// Get the radio input and push it to the server.
uint32_t radio_interface_loop(PubSubClient &client) {
  radio_inputs packet;
  // Read from the radio.
  shift_in((uint8_t *) &packet, sizeof(radio_inputs));

  // Push it to the server.
  client.publish(radio_input_topic, (uint8_t *) &packet, sizeof(radio_inputs), true);
  // Return the number of ticks used.
  return RETVAL;
}

// Get the engine starter state and push it to the server.
uint32_t engine_starter_loop(PubSubClient &client) {
  uint8_t packet;
  // Read the engine starter.
  shift_in((uint8_t *) &packet, 1);

  // Push it to the server.
  client.publish(engine_starter_topic, &packet, 1, true);
  // Return the number of ticks used.
  return RETVAL;
}
