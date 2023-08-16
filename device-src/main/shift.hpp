#ifndef __SHIFT_HPP__
#define __SHIFT_HPP__

#include <stdint.h>

extern void shift_out(uint8_t *data, size_t bytes);

extern void shift_out_noclear(uint8_t data);

extern void shift_in(uint8_t *data, size_t bytes);

extern uint8_t shift_in_noclear(void);


#endif
