#include "esphome/core/log.h"
#include "tuyanew_sensor.h"
#include <cinttypes>

namespace esphome {
namespace tuyanew {

static const char *const TAG = "tuyanew.sensor";

void TuyaNewSensor::setup() {
  this->parent_->register_listener(this->sensor_id_, [this](const TuyaNewDatapoint &datapoint) {
    if (datapoint.type == TuyaNewDatapointType::BOOLEAN) {
      ESP_LOGV(TAG, "MCU reported sensor %u is: %s", datapoint.id, ONOFF(datapoint.value_bool));
      this->publish_state(datapoint.value_bool);
    } else if (datapoint.type == TuyaNewDatapointType::INTEGER) {
      ESP_LOGV(TAG, "MCU reported sensor %u is: %d", datapoint.id, datapoint.value_int);
      this->publish_state(datapoint.value_int);
    } else if (datapoint.type == TuyaNewDatapointType::ENUM) {
      ESP_LOGV(TAG, "MCU reported sensor %u is: %u", datapoint.id, datapoint.value_enum);
      this->publish_state(datapoint.value_enum);
    } else if (datapoint.type == TuyaNewDatapointType::BITMASK) {
      ESP_LOGV(TAG, "MCU reported sensor %u is: %" PRIx32, datapoint.id, datapoint.value_bitmask);
      this->publish_state(datapoint.value_bitmask);
    }
  });
}

void TuyaNewSensor::dump_config() {
  LOG_SENSOR("", "TuyaNew Sensor", this);
  ESP_LOGCONFIG(TAG, "  Sensor has datapoint ID %u", this->sensor_id_);
}

}  // namespace tuyanew
}  // namespace esphome
