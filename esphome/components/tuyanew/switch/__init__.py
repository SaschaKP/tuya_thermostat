import esphome.codegen as cg
from esphome.components import switch
import esphome.config_validation as cv
from esphome.const import CONF_SWITCH_DATAPOINT

from .. import CONF_TUYA_ID, TuyaNew, tuyanew_ns

DEPENDENCIES = ["tuyanew"]
CODEOWNERS = ["@jesserockz"]

TuyaNewSwitch = tuyanew_ns.class_("TuyaNewSwitch", switch.Switch, cg.Component)

CONFIG_SCHEMA = (
    switch.switch_schema(TuyaNewSwitch)
    .extend(
        {
            cv.GenerateID(CONF_TUYA_ID): cv.use_id(TuyaNew),
            cv.Required(CONF_SWITCH_DATAPOINT): cv.uint8_t,
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    var = await switch.new_switch(config)
    await cg.register_component(var, config)

    paren = await cg.get_variable(config[CONF_TUYA_ID])
    cg.add(var.set_tuyanew_parent(paren))

    cg.add(var.set_switch_id(config[CONF_SWITCH_DATAPOINT]))
