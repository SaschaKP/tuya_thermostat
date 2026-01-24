#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "tuyanew.h"

#include <vector>

namespace esphome {
namespace tuyanew {

class TuyaNewDatapointUpdateTrigger : public Trigger<TuyaNewDatapoint> {
 public:
  explicit TuyaNewDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id) {
    parent->register_listener(sensor_id, [this](const TuyaNewDatapoint &dp) { this->trigger(dp); });
  }
};

class TuyaNewRawDatapointUpdateTrigger : public Trigger<std::vector<uint8_t>> {
 public:
  explicit TuyaNewRawDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id);
};

class TuyaNewBoolDatapointUpdateTrigger : public Trigger<bool> {
 public:
  explicit TuyaNewBoolDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id);
};

class TuyaNewIntDatapointUpdateTrigger : public Trigger<int> {
 public:
  explicit TuyaNewIntDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id);
};

class TuyaNewUIntDatapointUpdateTrigger : public Trigger<uint32_t> {
 public:
  explicit TuyaNewUIntDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id);
};

class TuyaNewStringDatapointUpdateTrigger : public Trigger<std::string> {
 public:
  explicit TuyaNewStringDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id);
};

class TuyaNewEnumDatapointUpdateTrigger : public Trigger<uint8_t> {
 public:
  explicit TuyaNewEnumDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id);
};

class TuyaNewBitmaskDatapointUpdateTrigger : public Trigger<uint32_t> {
 public:
  explicit TuyaNewBitmaskDatapointUpdateTrigger(TuyaNew *parent, uint8_t sensor_id);
};

}  // namespace tuyanew
}  // namespace esphome
