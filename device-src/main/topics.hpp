#ifndef __TOPICS_HPP__
#define __TOPICS_HPP__
 
#include <PubSubClient.h>

// Constant topics.
extern const char *will_topic;
extern const char *dev_info_topic;
extern const char *test_x27_topic;
extern const char *test_28byj_topic;
extern const char *test_7s_topic;
extern const char *altimeter_topic;
extern const char *spedometer_topic;
extern const char *tachometer_topic;
extern const char *clock_topic;
extern const char *fuel_gauge_topic;
extern const char *oil_gauge_topic;
extern const char *radio_output_topic;
extern const char *radio_input_topic;
extern const char *engine_starter_topic;
extern const char *debug_topic;

#ifdef DEBUG
inline void debug_pub(char *str, PubSubClient &client) {
  client.publish(debug_topic, str, strlen(str));
}
#else
inline void debug_pub(char *str, PubSubClient &client) {
  return;
}
#endif


#endif
