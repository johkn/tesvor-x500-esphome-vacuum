#pragma once

#include "esphome.h"
#include "x500_vacuum.h"

namespace esphome {
namespace x500_vacuum {

class X500VacuumButton : public button::Button {
 public:
  X500VacuumButton(X500Vacuum *vacuum, const std::vector<uint8_t> &cmd)
      : vacuum_(vacuum), cmd_(cmd) {}

 protected:
  void press_action() override {
    if (vacuum_) vacuum_->send_command(cmd_);
  }

  X500Vacuum *vacuum_;
  std::vector<uint8_t> cmd_;
};

}  // namespace x500_vacuum
}  // namespace esphome