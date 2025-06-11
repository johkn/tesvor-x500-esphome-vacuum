#include "esphome/core/component.h"
#include "esphome/core/defines.h"

namespace esphome {
namespace x500_vacuum {

class X500VacuumComponent : public Component {
 public:
  void setup() override {}
  void loop() override {}
  // ...
};

}  // namespace x500_vacuum
}  // namespace esphome

// Hier das YAML-Schema (meist in register_component() oder über esphome::register_component):
ESPHOME_NAMESPACE_BEGIN
ESPHOME_COMPONENT_SCHEMA(x500_vacuum::X500VacuumComponent)
  .add_required("uart_id", esphome::cv::string)
  .add_optional("rawstate_id", esphome::cv::string)
  .add_optional("vacstate_id", esphome::cv::string)
  .add_optional("errorstate_id", esphome::cv::string)
  .add_optional("batdata_id", esphome::cv::string);
ESPHOME_NAMESPACE_END
