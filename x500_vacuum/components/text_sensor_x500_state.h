#pragma once

#include "esphome.h"

namespace esphome {
namespace x500_vacuum {

class X500StateTextSensor : public text_sensor::TextSensor {
 public:
  void set_state(const std::string &state) { this->publish_state(state); }
};

}  // namespace x500_vacuum
}  // namespace esphome
