#ifndef __DRIVERS_HPP__
#define __DRIVERS_HPP__

#include "device_info.hpp"
#include <stdint.h>
#include <PubSubClient.h>

extern void setup_x27(device_info_t info, PubSubClient &client);
extern uint16_t run_x27_loop(void);
extern void run_x27_update(uint32_t steps);

extern void setup_28byj(device_info_t info, PubSubClient &client);
extern uint16_t run_28byj_loop(void);
extern void run_28byj_update(uint32_t steps, uint8_t motor);

extern void setup_7seg(device_info_t info, PubSubClient &client);
extern uint16_t run_7seg_loop(void);
extern void run_7seg_update(uint8_t *bit_patterns);

extern uint16_t radio_interface_loop(PubSubClient &client);
extern uint16_t engine_starter_loop(PubSubClient &client);


#endif
