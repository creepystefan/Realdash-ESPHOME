import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

realdash_ns = cg.esphome_ns.namespace("realdash")
REALDASH = realdash_ns.class_("REALDASH", cg.Component)
CONF_RD_BAUDRATE = 'rd_baudrate'

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(REALDASH),
        cv.Optional(CONF_RD_BAUDRATE, default=115200): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cg.add(var.set_rd_baudrate(config[CONF_RD_BAUDRATE]))


    