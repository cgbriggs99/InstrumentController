#ifndef __DEVICE_INFO_HPP__
#define __DEVICE_INFO_HPP__

#include <stdint.h>

// Pins for the device class.
#define DEVCL_0 25
#define DEVCL_1 26
#define DEVCL_2 27
#define DEVCL_3 32
#define DEVCL_4 33

// Pins for the headers
#define DATA_IO 23
#define SHCP_1 22
#define SHCP_2 17
#define STCP_1 21
#define STCP_2 16
#define OE_1 19
#define PL_2 4
#define __MR_1 18
#define __MR_2 2


typedef enum {
  // Test drivers.
  TEST_X27 = 0,
  TEST_28BYJ = 1,
  TEST_7S_DISPLAY = 2,
  
  // Device drivers.
  // Output devices.
  ALTIMETER = 3,
  SPEDOMETER = 4,
  TACHOMETER = 5,
  CLOCK = 6,
  FUEL_GAUGE = 7,
  OIL_GAUGE = 8,

  // Input devices
  RADIO = 9,
  ENGINE_STARTER = 10,
} device_class_t;

/**
 * @struct device_info_t
 * Holds the device info.
 */
typedef struct {
  /**
   * @var devclass
   * 
   * Holds the device class.
   */
  device_class_t devclass;

  /**
   * @var devid
   * 
   * Holds the device id. This is simply the MAC address of the adapter.
   */
  uint64_t devid;
} device_info_t;

/**
 * Get the device info. 
 */
extern device_info_t get_device_info(void);
    


#endif
