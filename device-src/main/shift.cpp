#include "esp32-hal.h"
#include "shift.hpp"
#include "device_info.hpp"
#include <stdint.h>
#include <stdlib.h>
#include <esp32-hal-gpio.h>

// Send data to the shift register.
void shift_out(const uint8_t *data, size_t bytes) {
  // Set multiplexed pin to be output.
  pinMode(DATA_IO, OUTPUT_OPEN_DRAIN);

  // Clear the storage register.
  digitalWrite(__MR_1, HIGH);
  digitalWrite(OE_1, LOW);
  //digitalWrite(STCP_1, HIGH);
  delayMicroseconds(10);
  //digitalWrite(STCP_1, LOW);
  digitalWrite(__MR_1, HIGH);

  int k = 1;
  // Shift data.
  for(size_t i = 0; i < bytes; i++) {
    for(uint8_t j = 0; j < 8; j++) {
      // Load the bit onto the bus.
      digitalWrite(DATA_IO, (data[i] & (1 << (7 - j)))? HIGH: LOW);
      // Wait for logic to happen.
      delayMicroseconds(5);

      // Unlock the register.
      digitalWrite(SHCP_1, HIGH);
      // Wait for the register to read.
      delayMicroseconds(10);
      digitalWrite(SHCP_1, LOW);
      delayMicroseconds(5);

      if (k > 1000) break;
    }
  }
  // Send the data to the output pins.
  delayMicroseconds(1);
  digitalWrite(STCP_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(STCP_1, LOW);
}

// Send a single byte to the shift register with out clearing the contents.
void shift_out_noclear(uint8_t data) {
  // Set multiplexed pin to be output.
  pinMode(DATA_IO, OUTPUT_OPEN_DRAIN);

  for(uint8_t j = 0; j < 8; j++) {
    digitalWrite(DATA_IO, (data & (1 << (7 - j)))? HIGH: LOW);
    digitalWrite(SHCP_1, HIGH);
    digitalWrite(SHCP_1, LOW);
  }
}

// Read data from the shift register.
void shift_in(uint8_t *data, size_t bytes) {
  // Set the multiplexed pin to be input.
  pinMode(DATA_IO, INPUT);

  // Clear shift register.
  digitalWrite(__MR_2, LOW);
  digitalWrite(PL_2, HIGH);

  // Load data onto the shift register.
  // Load onto latches.
  digitalWrite(STCP_2, HIGH);
  digitalWrite(STCP_2, LOW);
  
  // Load into register.
  digitalWrite(__MR_2, HIGH);
  digitalWrite(PL_2, LOW);
  digitalWrite(STCP_2, HIGH);
  digitalWrite(STCP_2, LOW);

  // Read data.
  digitalWrite(PL_2, HIGH);

  for(size_t i = 0; i < bytes; i++) {
    uint8_t read_val = 0;
    for(uint8_t j = 0; j < 8; j++) {
      read_val |= (digitalRead(DATA_IO))? 1: 0;
      read_val <<= 1;  // Shift.
      digitalWrite(SHCP_2, HIGH);
      digitalWrite(SHCP_2, LOW);
    }
    data[i] = read_val;
  }
}

// Read one byte from the shift register without clearing.
uint8_t shift_in_noclear(void) {
  // Set the multiplexed pin to be input.
  pinMode(DATA_IO, INPUT);
  
  // Read data.
  digitalWrite(PL_2, HIGH);

  uint8_t read_val = 0;
  for(uint8_t j = 0; j < 8; j++) {
    read_val |= (digitalRead(DATA_IO))? 1: 0;
    read_val <<= 1;  // Shift.
    digitalWrite(SHCP_2, HIGH);
    digitalWrite(SHCP_2, LOW);
  }
  return read_val;
}
