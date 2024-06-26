#ifndef __TOPICS_HPP__
#define __TOPICS_HPP__
 
#include <PubSubClient.h>

// Constant topics.
extern const char *will_topic; // The topic where the wills are sent when the device dies.
extern const char *dev_info_topic; // The topic where the device info is sent so that the host can manage them.
extern const char *test_x27_topic; // Topic for testing x27 devices.
extern const char *test_28byj_topic; // Topic for testing 28byj devices.
extern const char *test_7s_topic; // Topic for testing seven segment displays.
extern const char *altimeter_topic; // Topic that the altimeter will subscribe to.
extern const char *spedometer_topic; // Topic that the spedometer will subscribe to.
extern const char *tachometer_topic; // Topic that the tachometer will subscribe to.
extern const char *clock_topic; // Topic that the clock will subscribe to.
extern const char *fuel_gauge_topic; // Topic that the fuel gauge will subscribe to.
extern const char *oil_gauge_topic; // Topic that the oil gauge will subscribe to.
extern const char *radio_output_topic; // Topic that the radio will subscribe to.
extern const char *radio_input_topic; // Topic that the radio will publish to.
extern const char *engine_starter_topic; // Topic that the engine starter will publish to.
extern const char *debug_topic; // Topic where debug messages will be published.

#ifdef DEBUG
// Publish a string to the debug topic.
inline void debug_pub(char *str, PubSubClient &client) {
  client.publish(debug_topic, str, strlen(str));
}

// Publish from a format string.
template<typename... Args>
int debug_pubf(PubSubClient &client, const char *format, Args... args) {
  // Calculate the size.
  size_t buff_size = snprintf(NULL, format, 0, args...);

  // Allocate the required data.
  char *buff = new char[buff_size + 1];
  buff[buff_size] = '\0';

  // Write the data.
  int ret = snprintf(buff, format, buff_size, args...);

  // Publish.
  client.publish(debug_topic, buff, buff_size + 1);

  // Delete the string.
  delete[] buff;

  // Return.
  return ret;
}
#else
inline void debug_pub(char *str, PubSubClient &client) {
  return;
}

template<typename... Args>
int debug_pubf(PubSubClient &client, const char *format, Args... args) {
  return 0;
}
#endif


#endif
