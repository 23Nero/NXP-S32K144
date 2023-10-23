#include <stdint.h>
#include "systick.h"

static volatile uint32_t ms_count = 0;

void systick_initialize(uint32_t reload_value)
{
    // set the reload value
    SYSTICK->RVR = reload_value;

    // select core clock source
    SYSTICK->CSR.FIELD.CLKSOURCE = 0x1;

    // enable interrupt
    SYSTICK->CSR.FIELD.TICKINT = 0x1;
}

void systick_start(void)
{
    // reset count value
    SYSTICK->CVR = 0;

    // start systick
    SYSTICK->CSR.FIELD.ENABLE = 0x1;
}

void systick_stop(void)
{
    // stop systick
    SYSTICK->CSR.FIELD.ENABLE = 0x0;
}

void SysTick_Handler(void)
{
    ms_count += 1;
}

uint32_t systick_get_ms(void)
{
    return ms_count;
}

void systick_clean(void)
{
    ms_count = 0;
}
