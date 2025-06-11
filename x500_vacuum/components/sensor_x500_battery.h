#pragma once

#include "esphome.h"

namespace esphome {
namespace x500_vacuum {

class X500BatterySensor : public sensor::Sensor {
 public:
  void set_battery_level(uint8_t value) { this->publish_state(value); }
};

}  // namespace x500_vacuum
}  // namespace esphome
