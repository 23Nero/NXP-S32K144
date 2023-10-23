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

// https://community.arm.com/support-forums/f/keil-forum/35398/hardcoded-breakpoint-preventing-program-from-running
// handle the optimize -O0 checking for main argument
__asm(".global __ARM_use_no_argv");

void system_initialize(void);
void pcc_initialize(void);
void gpio_initialize(void);
void nvic_initialize(void);

void PORTC_IRQHandler(void);

int main(void)
{
    system_initialize();

    // turn off LED by set bit 16th of GPIOD
    GPIO_D->PSOR.FIELD.P16 = BIT_SET;

    while(1)
    {
        // main flow
        // do nothing since the GPIOC interrupt-handler handle toggle LED already
    }
}

void pcc_initialize(void)
{
    // enable clock gate for port C and D
    PCC->PCC_PORTC.FIELD.CGC = BIT_SET;
    PCC->PCC_PORTD.FIELD.CGC = BIT_SET;
}

void gpio_initialize(void)
{
    // configure gpio mode for PTC12
    PORT_C->PORT_PCR[12].FIELD.MUX = 0x1;

    // configure input direction for PTC12
    GPIO_C->PDDR.FIELD.P12 = 0x0;

    // configure rising edge for interrupt sensitive
    PORT_C->PORT_PCR[12].FIELD.IRQC = 0x9;

    // configure gpio mode for PTD16
    PORT_D->PORT_PCR[16].FIELD.MUX = 0x1;

    // configure output direction for PTD16
    GPIO_D->PDDR.FIELD.P16 = 0x1;
}

void nvic_initialize(void)
{
    // enable PORTC interrupt in NVIC
    // Interrupt ID of PORTC: 61 -> n = 1, bit 29th
    // Skip setting priority for PORTC interrupt since we only use one
    NVIC->ISER[1] |= (1U<<29);
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
    if (PORT_C->PORT_PCR[12].FIELD.ISF == 0x1)
    {
        // clear the interrupt flag by write 1b'1 to PORT_PCR[12].ISF
        PORT_C->PORT_PCR[12].FIELD.ISF = 0x1;

        // toggle LED
        GPIO_D->PTOR.FIELD.P16 = 0x1;
    }
}
