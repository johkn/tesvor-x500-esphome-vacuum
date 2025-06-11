#include "x500_vacuum.h"

namespace esphome {
namespace x500_vacuum {

void X500Vacuum::setup() {
  // nothing to do here
}

void X500Vacuum::loop() {
  while (available()) {
    uint8_t c = read();
    rx_buffer_.push_back(c);

    // look for end of frame (\r\n)
    if (rx_buffer_.size() >= 2 &&
        rx_buffer_[rx_buffer_.size() - 2] == '\r' &&
        rx_buffer_[rx_buffer_.size() - 1] == '\n') {
      process_uart_bytes_(rx_buffer_);
      rx_buffer_.clear();
    }
  }
}

void X500Vacuum::send_command(const std::vector<uint8_t> &cmd) {
  this->write_array(cmd);
}

void X500Vacuum::process_uart_bytes_(const std::vector<uint8_t> &bytes) {
  // Only handle 31-byte status packets
  if (bytes.size() == 31) {
    uint8_t state = bytes[6];

    if (raw_state_sensor_ && vacuum_state_sensor_) {
      switch (state) {
        case 0x09:
          raw_state_sensor_->publish_state("error");
          vacuum_state_sensor_->publish_state("error");
          break;
        case 0x08:
          raw_state_sensor_->publish_state("docked");
          vacuum_state_sensor_->publish_state("docked");
          break;
        case 0x06:
          raw_state_sensor_->publish_state("charging");
          vacuum_state_sensor_->publish_state("docked");
          break;
        case 0x05:
          raw_state_sensor_->publish_state("hibernated");
          vacuum_state_sensor_->publish_state("idle");
          break;
        case 0x04:
          raw_state_sensor_->publish_state("idle");
          vacuum_state_sensor_->publish_state("idle");
          break;
        case 0x03:
          raw_state_sensor_->publish_state("returning");
          vacuum_state_sensor_->publish_state("returning");
          break;
        case 0x02:
          raw_state_sensor_->publish_state("cleaning");
          vacuum_state_sensor_->publish_state("cleaning");
          break;
      }
    }

    if (battery_sensor_ &&
        (state == 0x06 || state == 0x05 || state == 0x04 || state == 0x02)) {
      battery_sensor_->publish_state(bytes[29]);
    }

    if (error_state_sensor_) {
      if (state != 0x09)
        error_state_sensor_->publish_state("no error");
      else {
        switch (bytes[28]) {
          case 0x02:
            error_state_sensor_->publish_state("rolling brush blocked");
            break;
          case 0x04:
            error_state_sensor_->publish_state("wheels blocked");
            break;
          case 0x07:
            error_state_sensor_->publish_state("side brush blocked");
            break;
          case 0x09:
            error_state_sensor_->publish_state("front guard jammed");
            break;
          default:
            error_state_sensor_->publish_state("error");
        }
      }
    }
  }
}

} // namespace x500_vacuum
} // namespace esphome
