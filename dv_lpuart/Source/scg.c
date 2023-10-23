#include <stdint.h>
#include "scg.h"

void scg_sosc_config
(
    eSCG_SOSC_EREFS_t eref,
    eSCG_SOSC_HGO_t hgo,
    eSCG_xRANGE_t range,
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
)
{
    // disable SOSC for further configuration
    SCG->SOSCCSR.FIELD.SOSCEN = BIT_CLEAR;

    // setting div
    SCG->SOSCDIV.FIELD.DIV1 = div1;
    SCG->SOSCDIV.FIELD.DIV2 = div2;

    // setting range, gain and external reference clock
    SCG->SOSCCFG.FIELD.EREFS = eref;
    SCG->SOSCCFG.FIELD.HGO = hgo;
    SCG->SOSCCFG.FIELD.RANGE = range;

    // enable SOSC and waiting till it is stable
    SCG->SOSCCSR.FIELD.SOSCEN = BIT_SET;
    while(SCG->SOSCCSR.FIELD.SOSCVLD == BIT_CLEAR){}
}

void scg_sirc_config
(
    eSCG_xRANGE_t range,
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
)
{
    // disable SOSC for further configurFIRCCSRation
    SCG->SIRCCSR.FIELD.SIRCEN = BIT_CLEAR;

    // setting div
    SCG->SIRCDIV.FIELD.DIV1 = div1;
    SCG->SIRCDIV.FIELD.DIV2 = div2;

    // setting range
    SCG->SIRCCFG.FIELD.RANGE = range;

    // enable SOSC and waiting till it is stable
    SCG->SIRCCSR.FIELD.SIRCEN = BIT_SET;
    while(SCG->SIRCCSR.FIELD.SIRCVLD == BIT_CLEAR){}
}

void scg_firc_config
(
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
)
{
    // disable SOSC for further configuration
    SCG->FIRCCSR.FIELD.FIRCEN = BIT_CLEAR;

    // setting div
    SCG->FIRCDIV.FIELD.DIV1 = div1;
    SCG->FIRCDIV.FIELD.DIV2 = div2;

    // setting range
    SCG->FIRCCFG.FIELD.RANGE = SCG_FIRC_48M;

    // enable SOSC and waiting till it is stable
    SCG->FIRCCSR.FIELD.FIRCEN = BIT_SET;
    while(SCG->FIRCCSR.FIELD.FIRCVLD == BIT_CLEAR){}
}

void scg_spll_config
(
    eSCG_SPLL_SOURCE_t source,
    eSCG_SPLL_PREDIV_t prediv,
    eSCG_SPLL_MULT_t mult,
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
)
{
    // disable SPLL for further configuration
    SCG->SPLLCSR.FIELD.SPLLEN = BIT_CLEAR;

    // setting div
    SCG->SPLLDIV.FIELD.DIV1 = div1;
    SCG->SPLLDIV.FIELD.DIV2 = div2;

    // setting range, gain and external reference clock
    SCG->SPLLCFG.FIELD.SOURCE = source;
    SCG->SPLLCFG.FIELD.PREDIV = prediv;
    SCG->SPLLCFG.FIELD.MULT = mult;

    // enable SPLL and waiting till it is stable
    SCG->SPLLCSR.FIELD.SPLLEN = BIT_SET;
    while(SCG->SPLLCSR.FIELD.SPLLVLD == BIT_CLEAR){}
}

void scg_system_clock_config
(
    eSCG_MODE_t mode,
    eSCG_DIV_t div_slow,
    eSCG_DIV_t div_bus,
    eSCG_DIV_t div_core,
    eSCG_SYSTEM_CLOCK_SOURCE_t source
)
{
    if (mode == SCG_HSRUN_MODE)
    {
        SCG->HCCR.FIELD.DIVSLOW = div_slow;
        SCG->HCCR.FIELD.DIVBUS = div_bus;
        SCG->HCCR.FIELD.DIVCORE = div_core;
        // in HSRUN mode, the system clock can only be the FIRC or SPLL
        SCG->HCCR.FIELD.SCS = source;
    }
    else if (mode == SCG_VLPR_MODE)
    {
        SCG->VCCR.FIELD.DIVSLOW = div_slow;
        SCG->VCCR.FIELD.DIVBUS = div_bus;
        SCG->VCCR.FIELD.DIVCORE = div_core;
        // in VLPR mode, the system clock source is fix to SIRC
        SCG->VCCR.FIELD.SCS = SCG_SIRCSOURCE;
    }
    else
    {
        SCG->RCCR.FIELD.DIVSLOW = div_slow;
        SCG->RCCR.FIELD.DIVBUS = div_bus;
        SCG->RCCR.FIELD.DIVCORE = div_core;
        SCG->RCCR.FIELD.SCS = source;
    }
}
