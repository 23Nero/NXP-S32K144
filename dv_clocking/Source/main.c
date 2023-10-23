/**
 * Write a program that control the three LEDs: PTD0 (LED_BLUE), PTD15 (LED_RED), and PTD16 (LED_GREEN) by the two switch PTC12 (SW2) and PTC13 (SW3)
 *      - Blink mode, the activating led blink with period of 1 second
 *      - Normal mode, the activating led keep its state
 *      - Use SW2 to switch the activating LED
 *          + At the beginning of the program, LED_RED is activated
 *          + If the LED_BLUE is activating, change the activating LED to LED_RED
 *          + If the LED_RED is activating, change the activating LED to LED_GREEN
 *          + If the LED_GREEN is activating, change the activating LED to LED_BLUE
 *      - Use SW3 to change the mode of the activating LED
 *          + At the beginning of the program, the LEDs are in Normal mode (turned off state)
 *          + If the activating LED is in Blink mode, change the mode of the activating LED to Normal mode and vice versa\
 *      - Sub-requrement:
 *          + User external clock (8Mhz) as the input of the SPLL, SYS_CLK is 80Mhz, BUS_CLK is 40Mhz
 *          + Use the system tick timer for delay_systick 1s
 *
 *      Note:
 *          + When the activating LED is switched, the other inactivate LED retain their mode
**/

#include "common.h"
#include "gpio.h"
#include "port.h"
#include "pcc.h"
#include "nvic.h"
#include "systick.h"
#include "scg.h"
#include "port_gpio.h"
#include "main.h"

// global variables use in Interrupt handler and main, should be volatile
static volatile led_mode_t running_mode[3] = {LED_MODE_OFF};
static volatile led_state_t led_state[3] = {LED_OFF};
static volatile led_active_t led_active = LED_ACTIVE_BLUE;
static volatile uint32_t led_mask[3] = {LED_MASK(0), LED_MASK(15), LED_MASK(16)};

int main(void)
{
    system_initialize();

    while(1)
    {
        process_led();
        delay_systick(1000);
    }
}

void process_led(void)
{
    for (uint8_t led = 0; led < 3; led ++)
    {
        if(running_mode[led] == LED_MODE_OFF)
        {
            GPIO_D->PSOR.REG |= led_mask[led];
            led_state[led] = LED_OFF;
        }
        else if(running_mode[led] == LED_MODE_ON)
        {
            GPIO_D->PCOR.REG |= led_mask[led];
            led_state[led] = LED_ON;
        }
        else
        {
            GPIO_D->PTOR.REG |= led_mask[led];
            if (led_state[led] == LED_ON)
            {
                led_state[led] = LED_OFF;
            }
            else
            {
                led_state[led] = LED_ON;
            }
        }
    }
}

void scg_initialize(void)
{
    // use external cystal 8Mhz
    // config SYSCLK and CORECLK as 80Mhz
    // BUSCLK 40Mhz
    scg_sosc_config(SCG_SOSC_INTERNAL_OSC, SCG_SOSC_HIGH_GAIN, SCG_SOSC_HIGH_FRE, SCG_xDIV_DISABLE, SCG_xDIV_DISABLE);
    scg_spll_config(SCG_SPLL_SOURCE_SOSC, SCG_SPLL_PREDIV_1, SCG_SPLL_MULT_20, SCG_xDIV_DISABLE, SCG_xDIV_DISABLE);
    scg_system_clock_config(SCG_RUN_MODE, SCG_DIV_3, SCG_DIV_2, SCG_DIV_1, SCG_SPLLSOURCE);
}

void pcc_initialize(void)
{
    PCC->PCC_PORTC.FIELD.CGC = BIT_SET;
    PCC->PCC_PORTD.FIELD.CGC = BIT_SET;
}

void gpio_initialize(void)
{
    // config PTC12 (SW2) and PTC13 (SW3) as input, interrupt on rising edge
    gpio_config_basic_input_with_interrupt(PORTC, GPIO_PIN12);
    gpio_config_basic_input_with_interrupt(PORTC, GPIO_PIN13);

    // turn off LEDs, preventing the LED to be turned on immediately after set as output
    GPIO_D->PSOR.FIELD.P0 = BIT_SET;
    GPIO_D->PSOR.FIELD.P15 = BIT_SET;
    GPIO_D->PSOR.FIELD.P16 = BIT_SET;

    // config PTD0 (LED_BLUE), PTD15 (LED_RED), and PTD16 (LED_GREEN) as output
    gpio_config_basic_output_high_strength(PORTD, GPIO_PIN0);
    gpio_config_basic_output_high_strength(PORTD, GPIO_PIN15);
    gpio_config_basic_output_high_strength(PORTD, GPIO_PIN16);
}

void nvic_initialize(void)
{
    // enable PORTC interrupt in NVIC
    nvic_enable_interrupt(IRQn_PORTC);
}

// app initialize
void system_initialize(void)
{
    scg_initialize();
    pcc_initialize();
    gpio_initialize();
    nvic_initialize();

    // system clock is reconfigured by 80 Mhz
    systick_initialize((SYS_CLOCK_FRE/1000)-1);
}

// override interrupt handler for PORTC
void PORTC_IRQHandler(void)
{
    // check if PORTC interrupt was triggered from PTC12
    // change led mode
    if (PORT_C->PORT_PCR[12].FIELD.ISF == BIT_SET)
    {
        // clear the interrupt flag by write 1b'1 to PORT_PCR[12].ISF
        PORT_C->PORT_PCR[12].FIELD.ISF = BIT_SET;

        // change mode
        if (running_mode[led_active] == LED_MODE_BLINK)
        {
            // current mode is blink, change to not blink
            // keep the current state of the led
            if (led_state[led_active] == LED_OFF)
            {
                running_mode[led_active] = LED_MODE_OFF;
            }
            else
            {
                running_mode[led_active] = LED_MODE_ON;
            }
        }
        else
        {
            running_mode[led_active] = LED_MODE_BLINK;
        }
    }

    // check if PORTC interrupt was triggered from PTC13
    // change active led
    else if (PORT_C->PORT_PCR[13].FIELD.ISF == BIT_SET)
    {
        // clear the interrupt flag by write 1b'1 to PORT_PCR[12].ISF
        PORT_C->PORT_PCR[13].FIELD.ISF = BIT_SET;

        if (led_active == LED_ACTIVE_RED)
        {
            led_active = LED_ACTIVE_GREEN;
        }
        else if (led_active == LED_ACTIVE_GREEN)
        {
            led_active = LED_ACTIVE_BLUE;
        }
        else
        {
            led_active = LED_ACTIVE_RED;
        }
    }
    else
    {
        // do nothing
    }
}

void delay_systick(uint32_t ms)
{
    systick_start();
    while (systick_get_ms() < ms) {}
    systick_stop();
    systick_clean();
}
