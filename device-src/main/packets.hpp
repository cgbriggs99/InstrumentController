#ifndef __PACKETS_HPP__
#define __PACKETS_HPP__

#include "device_info.hpp"
#include <stdint.h>

/**
 * @struct device_info_packet
 * 
 * Holds device information to dictate how the device behaves.
 */
typedef struct {
  /**
   * @var devclass
   * 
   * Indicates which kind of devices this board controls.
   */
  device_class_t devclass;

  /**
   * @var devid
   * 
   * Holds the unique device id. This is just the MAC address.
   */
  uint64_t devid;
} device_info_packet;

/**
 * @struct motor_packet
 * 
 * Holds a command to update the motors.
 */
typedef struct {
  /**
   * @var steps
   * 
   * The number of steps to set as the goal.
   */
  int32_t steps;

  /**
   * @var motor
   * 
   * Which motor to update.
   */
  uint32_t motor;
} motor_packet;

/**
 * @struct seven_seg_packet
 * 
 * Holds a command to update the seven segment display.
 */
typedef struct {
  /**
   * @var bit_patterns
   * 
   * The array of bytes representing characters to display.
   */
  uint8_t bit_patterns[8];

  /**
   * @var display
   * 
   * Which display to update.
   */
  uint32_t display;
} seven_seg_packet;

/**
 * @struct radio_inputs
 * 
 * Holds state information from the radio to publish.
 */
typedef struct {
  /**
   * @var buttons
   * 
   * Bits representing the states of the buttons.
   */
  uint16_t buttons;

  /**
   * @var encoder_positions
   * 
   * Holds the positions of the rotary encoders.
   */
  uint8_t encoder_positions[6];
} radio_inputs;


#endif
