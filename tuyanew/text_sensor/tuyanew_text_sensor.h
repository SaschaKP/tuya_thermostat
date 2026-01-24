#pragma once

#include "esphome/core/component.h"
#include "esphome/components/tuyanew/tuyanew.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace tuyanew {

class TuyaNewTextSensor : public text_sensor::TextSensor, public Component {
 public:
  void setup() override;
  void dump_config() override;
  void set_sensor_id(uint8_t sensor_id) { this->sensor_id_ = sensor_id; }

  void set_tuyanew_parent(TuyaNew *parent) { this->parent_ = parent; }

 protected:
  TuyaNew *parent_;
  uint8_t sensor_id_{0};
};

}  // namespace tuyanew
}  // namespace esphome
