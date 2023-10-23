/**
 * Write a program that control the PTD16 (LED_GREEN) by the switch PTC12 (SW2)
 *      - When the SW2 is pressed, toggle LED_GREEN state
 *      - Sub-requrement:
 *          + On rising edge of SW2, PORT C send an interrupt signal to NVIC
 *          + LED_GREEN should be toggled on interrupt handler of PORT C
**/

#include "common.h"
#include "gpio.h"
#include "port.h"
#include "pcc.h"
#include "nvic.h"
#include "port_gpio.h"
#include "main.h"

int main(void)
{
    system_initialize();

    while(1)
    {
    }
}

void pcc_initialize(void)
{
    PCC->PCC_PORTC.FIELD.CGC = BIT_SET;
    PCC->PCC_PORTD.FIELD.CGC = BIT_SET;
}

void gpio_initialize(void)
{
    // config PTC12 (SW2) as input, interrupt on rising edge
    gpio_config_basic_input_with_interrupt(PORTC, GPIO_PIN12);

    // turn off LEDs
    GPIO_D->PSOR.FIELD.P0 = BIT_SET;

    // config PTD0 (LED_BLUE) as output
    gpio_config_basic_output_high_strength(PORTD, GPIO_PIN0);
}

void nvic_initialize(void)
{
    // enable PORTC interrupt in NVIC
    nvic_enable_interrupt(IRQn_PORTC);
}

// app initialize
void system_initialize(void)
{
    pcc_initialize();
    gpio_initialize();
    nvic_initialize();
}

// override interrupt handler for PORTC
void PORTC_IRQHandler(void)
{
    // check if PORTC interrupt was triggered from PTC12
    if (PORT_C->PORT_PCR[12].FIELD.ISF == BIT_SET)
    {
        // clear the interrupt flag by write 1b'1 to PORT_PCR[12].ISF
        PORT_C->PORT_PCR[12].FIELD.ISF = BIT_SET;

        // toggle LED
        GPIO_D->PTOR.FIELD.P0 = BIT_SET;
    }
}

