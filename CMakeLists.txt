cmake_minimum_required(VERSION 3.13)

project(InstrumentController)

option(MOSQUITTO_CMD "Command line for running the Mosquitto server." "/usr/sbin/mosquitto")
option(LIBMOSQUITTO "Qualified path to the Mosquitto library." "/usr/lib/x86_64-linux-gnu/libmosquitto.so")
option(MOSQUITTO_HEAD "Qualified path to the Mosquitto header file." "/usr/include/mosquitto.h")

option(ESP32_CPP "Command to use to compile the ESP32 objects.")
option(ESP32_LD "Command to use to link the ESP32 objects.")
option(ESP32_LIBS "Directory where the ESP32 headers and sources can be found.")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add the main executable.
#add_library(pilotwave SHARED)

# Add binaries for the controllers.
add_executable(device_client)

# Install the components.
#install(TARGETS pilotwave LIBRARY)
install(TARGETS device_client RUNTIME)

#add_subdirectory(host-src)
add_subdirectory(device-src)
