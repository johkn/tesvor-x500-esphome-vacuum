#include "esphome/core/component.h"
#include "esphome/core/defines.h"

namespace esphome {
namespace x500_vacuum {

static const char *const TAG = "x500_vacuum";

// Hier das YAML-Schema:
static const auto CONFIG_SCHEMA = cv::Schema({
  cv::Required("uart_id"): cv::string,
  cv::Optional("rawstate_id"): cv::string,
  cv::Optional("vacstate_id"): cv::string,
  cv::Optional("errorstate_id"): cv::string,
  cv::Optional("batdata_id"): cv::string,
});
...
}
}
