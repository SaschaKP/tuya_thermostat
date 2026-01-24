#include "esphome/core/log.h"

#include "automation.h"

static const char *const TAG = "tuyanew.automation";

namespace esphome {
namespace tuyanew {

void check_expected_datapoint(const TuyaNewDatapoint &dp, TuyaNewDatapointType expected) {
  if (dp.type != expected) {
    ESP_LOGW(TAG, "TuyaNew sensor %u expected datapoint type %#02hhX but got %#02hhX", dp.id,
             static_cast<uint8_t>(expected), static_cast<uint8_t>(dp.type));
  }
}

TuyaNewRawDatapointUpdateTrigger::TuyaNewRawDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
  parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) {
    check_expected_datapoint(dp, TuyaNewDatapointType::RAW);
    this->trigger(dp.value_raw);
  });
}

TuyaNewBoolDatapointUpdateTrigger::TuyaNewBoolDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
  parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) {
    check_expected_datapoint(dp, TuyaNewDatapointType::BOOLEAN);
    this->trigger(dp.value_bool);
  });
}

TuyaNewIntDatapointUpdateTrigger::TuyaNewIntDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
  parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) {
    check_expected_datapoint(dp, TuyaNewDatapointType::INTEGER);
    this->trigger(dp.value_int);
  });
}

TuyaNewUIntDatapointUpdateTrigger::TuyaNewUIntDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
  parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) {
    check_expected_datapoint(dp, TuyaNewDatapointType::INTEGER);
    this->trigger(dp.value_uint);
  });
}

TuyaNewStringDatapointUpdateTrigger::TuyaNewStringDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
  parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) {
    check_expected_datapoint(dp, TuyaNewDatapointType::STRING);
    this->trigger(dp.value_string);
  });
}

TuyaNewEnumDatapointUpdateTrigger::TuyaNewEnumDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
  parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) {
    check_expected_datapoint(dp, TuyaNewDatapointType::ENUM);
    this->trigger(dp.value_enum);
  });
}

TuyaNewBitmaskDatapointUpdateTrigger::TuyaNewBitmaskDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
  parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) {
    check_expected_datapoint(dp, TuyaNewDatapointType::BITMASK);
    this->trigger(dp.value_bitmask);
  });
}

}  // namespace tuyanew
}  // namespace esphome
