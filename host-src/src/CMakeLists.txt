project(InstrumentController)

configure_file(mosquitto.template.cs mosquitto.cs)

target_sources(pilotwave PUBLIC  mosquitto.cs pilotwave.cs)
