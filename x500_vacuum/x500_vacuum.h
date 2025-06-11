#pragma once

#include "esphome.h"
#include "button_x500_vacuum.h"
#include "sensor_x500_battery.h"
#include "text_sensor_x500_state.h"

namespace esphome {
namespace x500_vacuum {

class X500Vacuum : public Component, public uart::UARTDevice {
 public:
  void setup() override;
  void loop() override;

  void set_raw_state_sensor(text_sensor::TextSensor *sensor) { raw_state_sensor_ = sensor; }
  void set_vacuum_state_sensor(text_sensor::TextSensor *sensor) { vacuum_state_sensor_ = sensor; }
  void set_error_state_sensor(text_sensor::TextSensor *sensor) { error_state_sensor_ = sensor; }
  void set_battery_sensor(sensor::Sensor *sensor) { battery_sensor_ = sensor; }

  void send_command(const std::vector<uint8_t> &cmd);

 protected:
  text_sensor::TextSensor *raw_state_sensor_{nullptr};
  text_sensor::TextSensor *vacuum_state_sensor_{nullptr};
  text_sensor::TextSensor *error_state_sensor_{nullptr};
  sensor::Sensor *battery_sensor_{nullptr};

  std::vector<uint8_t> rx_buffer_;

  void process_uart_bytes_(const std::vector<uint8_t> &bytes);
};

} // namespace x500_vacuum
} // namespace esphome