import esphome.codegen as cg
from esphome.components import sensor
import esphome.config_validation as cv
from esphome.const import CONF_ID, CONF_SENSOR_DATAPOINT

from .. import CONF_TUYA_ID, TuyaNew, tuyanew_ns

DEPENDENCIES = ["tuyanew"]
CODEOWNERS = ["@jesserockz"]

TuyaNewSensor = tuyanew_ns.class_("TuyaNewSensor", sensor.Sensor, cg.Component)

CONFIG_SCHEMA = (
    sensor.sensor_schema(TuyaNewSensor)
    .extend(
        {
            cv.GenerateID(CONF_TUYA_ID): cv.use_id(TuyaNew),
            cv.Required(CONF_SENSOR_DATAPOINT): cv.uint8_t,
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await sensor.register_sensor(var, config)

    paren = await cg.get_variable(config[CONF_TUYA_ID])
    cg.add(var.set_tuyanew_parent(paren))

    cg.add(var.set_sensor_id(config[CONF_SENSOR_DATAPOINT]))
