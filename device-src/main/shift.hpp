#ifndef __SHIFT_HPP__
#define __SHIFT_HPP__

#include <stdint.h>
#include <stdlib.h>

/**
 * Send data on the output bus to the shift register.
 *
 * @param data A pointer to the data array to send.
 * @param bytes The number of bytes to send.
 */
extern void shift_out(const uint8_t *data, size_t bytes);

/**
 * Send a single byte on the output bus to the shift register.
 *
 * @param data The byte to send.
 */
extern void shift_out_noclear(uint8_t data);

/**
 * Receive data on the input bus from the shift register.
 *
 * @param data The buffer to place the data.
 * @param bytes The number of bytes to read.
 */
extern void shift_in(uint8_t *data, size_t bytes);

/**
 * Receive a single byte from the shift register.
 *
 * @return The byte from the shift register.
 */
extern uint8_t shift_in_noclear(void);


#endif
