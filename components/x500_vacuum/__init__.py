import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.components import uart

DEPENDENCIES = ["uart"]

CONF_UART_ID = "uart_id"
CONF_RAWSTATE_ID = "rawstate_id"
CONF_VACSTATE_ID = "vacstate_id"
CONF_ERRORSTATE_ID = "errorstate_id"
CONF_BATDATA_ID = "batdata_id"

x500_vacuum_ns = cg.esphome_ns.namespace("x500_vacuum")
X500VacuumComponent = x500_vacuum_ns.class_("X500VacuumComponent", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(X500VacuumComponent),
        cv.Required(CONF_UART_ID): cv.use_id(uart.UARTComponent),
        cv.Optional(CONF_RAWSTATE_ID): cv.string,
        cv.Optional(CONF_VACSTATE_ID): cv.string,
        cv.Optional(CONF_ERRORSTATE_ID): cv.string,
        cv.Optional(CONF_BATDATA_ID): cv.string,
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[cv.GenerateID()])
    await cg.register_component(var, config)
    uart_var = await cg.get_variable(config[CONF_UART_ID])
    cg.add(var.set_uart(uart_var))
    if CONF_RAWSTATE_ID in config:
        cg.add(var.set_rawstate_id(config[CONF_RAWSTATE_ID]))
    if CONF_VACSTATE_ID in config:
        cg.add(var.set_vacstate_id(config[CONF_VACSTATE_ID]))
    if CONF_ERRORSTATE_ID in config:
        cg.add(var.set_errorstate_id(config[CONF_ERRORSTATE_ID]))
    if CONF_BATDATA_ID in config:
        cg.add(var.set_batdata_id(config[CONF_BATDATA_ID]))
