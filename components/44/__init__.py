import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from .. import realdash_ns

CONF_FRAME_ID1 = 'rd_frame_id'

RealDash44Output = 44_ns.class_("RealDash44Output", output.Output44)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(RealDash44Output),
        cv.Optional(CONF_FRAME_ID, default=0x81c): cv.int_,
                
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    cg.add_define("rd_frame_id", config[CONF_FRAME_ID])
    

