#include "esphome/core/log.h"
#include "tuyanew_binary_sensor.h"

namespace esphome {
namespace tuyanew {

static const char *const TAG = "tuyanew.binary_sensor";

void TuyaNewBinarySensor::setup() {
  this->parent_->register_listener(this->sensor_id_, [this](const TuyaNewDatapoint &datapoint) {
    ESP_LOGV(TAG, "MCU reported binary sensor %u is: %s", datapoint.id, ONOFF(datapoint.value_bool));
    this->publish_state(datapoint.value_bool);
  });
}

void TuyaNewBinarySensor::dump_config() {
  ESP_LOGCONFIG(TAG,
                "TuyaNew Binary Sensor:\n"
                "  Binary Sensor has datapoint ID %u",
                this->sensor_id_);
}

}  // namespace tuyanew
}  // namespace esphome
