#pragma once

#include "esphome/core/component.h"
#include "esphome/components/tuyanew/tuyanew.h"
#include "esphome/components/switch/switch.h"

namespace esphome {
namespace tuyanew {

class TuyaNewSwitch : public switch_::Switch, public Component {
 public:
  void setup() override;
  void dump_config() override;
  void set_switch_id(uint8_t switch_id) { this->switch_id_ = switch_id; }

  void set_tuyanew_parent(TuyaNew *parent) { this->parent_ = parent; }

 protected:
  void write_state(bool state) override;

  TuyaNew *parent_;
  uint8_t switch_id_{0};
};

}  // namespace tuyanew
}  // namespace esphome
