#include <stdint.h>
#include <stdbool.h>
#include "lpit.h"

void lpit_general_config
(
    bool enable_module_clock,
    bool enable_software_reset,
    bool enable_doze,
    bool enable_run_on_debug
)
{
    LPIT->MCR.FIELD.M_CEN = enable_module_clock;
    LPIT->MCR.FIELD.SW_RST = enable_software_reset;
    LPIT->MCR.FIELD.DOZE_EN = enable_doze;
    LPIT->MCR.FIELD.DBG_EN = enable_run_on_debug;
}

void lpit_channel_config
(
    LPIT_CHANNEL_t channel,
    bool enable_chain,
    LPIT_CHANNEL_RUNNING_MODE_t mode,
    bool enable_stop_on_interrupt
)
{
    // LPIT->MCR.FIELD.M_CEN = BIT_CLEAR;
    LPIT->TMR[channel].TCTRL.FIELD.CHAIN = enable_chain;
    LPIT->TMR[channel].TCTRL.FIELD.MODE = mode;
    LPIT->TMR[channel].TCTRL.FIELD.TSOI = enable_stop_on_interrupt;
    // LPIT->MCR.FIELD.M_CEN = BIT_SET;
}

void lpit_enable_interrupt
(
    LPIT_CHANNEL_t channel
)
{
    LPIT->MIER.REG |= (uint32_t)(0x1u << channel);
}

void lpit_disable_interrupt
(
    LPIT_CHANNEL_t channel
)
{
    LPIT->MIER.REG &= (uint32_t)(~(0x1u << channel));
}

void lpit_enable_single_channel
(
    LPIT_CHANNEL_t channel
)
{
    LPIT->TMR[channel].TCTRL.FIELD.T_EN = BIT_SET;
}

void lpit_disable_single_channel
(
    LPIT_CHANNEL_t channel
)
{
    LPIT->TMR[channel].TCTRL.FIELD.T_EN = BIT_CLEAR;
}

void lpit_set_reload_value
(
    LPIT_CHANNEL_t channel,
    uint32_t reload_value
)
{
    LPIT->TMR[channel].TVAL = reload_value;
}

uint32_t lpit_get_reload_value
(
    LPIT_CHANNEL_t channel
)
{
    return LPIT->TMR[channel].TVAL;
}
