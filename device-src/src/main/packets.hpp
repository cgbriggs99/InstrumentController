#ifndef __PACKETS_HPP__
#define __PACKETS_HPP__

#include "device_info.hpp"

typedef struct {
  device_class_t devclass;
  uint8_t devid;
} device_info_packet;

typedef struct {
  uint32_t steps;
  uint8_t motor;
} motor_packet;

typedef struct {
  uint8_t bit_patterns[8];
  uint8_t display;
} seven_seg_packet;



#endif
