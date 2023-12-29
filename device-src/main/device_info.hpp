  #ifndef __DEVICE_INFO_HPP__
#define __DEVICE_INFO_HPP__

#include <stdint.h>

// Pins for the device id and the device class.
// These four are input-only.
#define DEVID_0 34
#define DEVID_1 35
#define DEVID_2 36
#define DEVID_3 39

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
#define MR_1 18
#define MR_2 2


typedef enum {
  // Test drivers.
  TEST_X27 = 0,
  TEST_28BYJ = 1,
  TEST_7S_DISPLAY = 2,
  
  // Device drivers.
  ALTIMETER = 3,
  SPEDOMETER = 4,
  TACHOMETER = 5,
  CLOCK = 6,
  FUEL_GAUGE = 7,
  OIL_GAUGE = 8,
  RADIO = 9,
  ENGINE_STARTER = 10,
} device_class_t;

// Hold the device info.
typedef struct {
  device_class_t devclass;
  uint8_t devid;
  const char *topic;
  
} device_info_t;


extern device_info_t get_device_info(void);
    


#endif
