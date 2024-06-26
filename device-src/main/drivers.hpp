#ifndef __DRIVERS_HPP__
#define __DRIVERS_HPP__

#include "device_info.hpp"
#include <stdint.h>
#include <PubSubClient.h>

/**
 * Set up the device to host an x27 motor.
 * 
 * @param info The device info.
 * @param client The mqtt client to subscribe to.
 */
extern void setup_x27(device_info_t info, PubSubClient &client);

/**
 * Update the x27 device.
 * 
 * @return The number of ticks used up.
 */
extern uint32_t run_x27_loop(void);

/**
 * Update the target positions of the x27 motor.
 * 
 * @param steps The new number of steps to approach.
 */
extern void run_x27_update(uint32_t steps);

/**
 * Set up the device to host a 28byj motor.
 * 
 * @param info The device info.
 * @param client The mqtt client to subscribe to.
 */
extern void setup_28byj(device_info_t info, PubSubClient &client);

/**
 * Update the 28byj device.
 * 
 * @return The number of ticks used up.
 */
extern uint32_t run_28byj_loop(void);

/**
 * Update the target positions of the 28byj motor.
 * 
 * @param steps The new number of steps to approach.
 * @param motor Which motor to update.
 */
extern void run_28byj_update(uint32_t steps, uint8_t motor);

/**
 * Set up the device to host a seven segment display.
 * 
 * @param info The device info.
 * @param client The mqtt client to subscribe to.
 */
extern void setup_7seg(device_info_t info, PubSubClient &client);

/**
 * Refresh the seven segment display.
 * 
 * @return The number of ticks used up.
 */
extern uint32_t run_7seg_loop(void);

/**
 * Update the info to display on the seven segment display. The number of bytes needs
 * to match the number of characters in the display.
 * 
 * @param bit_patterns A string of bytes indicating which segments to light up.
 * @param display Which display to send the patterns to.
 */
extern void run_7seg_update(uint8_t *bit_patterns, uint8_t display);

/**
 * Read input from the radio and publish it.
 */
extern uint32_t radio_interface_loop(PubSubClient &client);

/**
 * Read input from the engine starter.
 */
extern uint32_t engine_starter_loop(PubSubClient &client);


#endif
