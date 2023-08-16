#include "drivers.hpp"
#include "topics.hpp"
#include "packets.hpp"
#include "device_info.hpp"
#include <PubSubClient.h>

#define RETVAL 10000

uint16_t radio_interface_loop(PubSubClient &client) {
  radio_inputs packet;
  shift_in((uint8_t *) &packet, sizeof(radio_inputs));

  client.publish(radio_interface_topic, (const char *) &packet, sizeof(radio_inputs), true);
  return RETVAL;
}

uint16_t engine_starter_loop(PubSubClient &client) {
  uint8_t packet;
  shift_in((uint8_t *) &packet, 1);

  client.publish(engine_starter_topic, (const char *) &packet, 1, true);
  return RETVAL;
}