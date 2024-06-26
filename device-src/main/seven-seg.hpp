#ifndef __SEVEN_SEG_HPP__
#define __SEVEN_SEG_HPP__

#include <stdint.h>

// Holds the bit patterns representing digits.
uint8_t digits[] = {
  0b00000010, // 0
  0b10011110, // 1
  0b00100100, // 2
  0b00001100, // 3
  0b10011000, // 4
  0b01001000, // 5
  0b01000000, // 6
  0b00011110, // 7
  0b00000000, // 8
  0b00001000, // 9
  0b00010000, // A
  0b11000000, // b
  0b01100010, // C
  0b10000100, // d
  0b01100000, // E
  0b01110000  // F
};

// Holds the flags for each position in the display.
uint8_t position[] = {
  0x08, // MSD
  0x04,
  0x02,
  0x01,
  0x80,
  0x40,
  0x20,
  0x10  // LSD
};


#endif
