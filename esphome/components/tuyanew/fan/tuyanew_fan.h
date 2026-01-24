#pragma once

#include "esphome/core/component.h"
#include "esphome/components/tuyanew/tuyanew.h"
#include "esphome/components/fan/fan.h"

namespace esphome {
namespace tuyanew {

class TuyaNewFan : public Component, public fan::Fan {
 public:
  TuyaNewFan(TuyaNew *parent, int speed_count) : parent_(parent), speed_count_(speed_count) {}
  void setup() override;
  void dump_config() override;
  void set_speed_id(uint8_t speed_id) { this->speed_id_ = speed_id; }
  void set_switch_id(uint8_t switch_id) { this->switch_id_ = switch_id; }
  void set_oscillation_id(uint8_t oscillation_id) { this->oscillation_id_ = oscillation_id; }
  void set_direction_id(uint8_t direction_id) { this->direction_id_ = direction_id; }

  fan::FanTraits get_traits() override;

 protected:
  void control(const fan::FanCall &call) override;

  TuyaNew *parent_;
  optional<uint8_t> speed_id_{};
  optional<uint8_t> switch_id_{};
  optional<uint8_t> oscillation_id_{};
  optional<uint8_t> direction_id_{};
  int speed_count_{};
  TuyaNewDatapointType speed_type_{};
  TuyaNewDatapointType oscillation_type_{};
};

}  // namespace tuyanew
}  // namespace esphome
