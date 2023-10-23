#include <stdint.h>
#include "port.h"
#include "gpio.h"
#include "port_gpio.h"

static PORT_t *ports[] = {PORT_A, PORT_B, PORT_C, PORT_D, PORT_E};
static GPIO_t *gpios[] = {GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E};

void gpio_config
(
    PORT_NAME_t port,
    GPIO_PIN_t pin,
    GPIO_MUX_t mux,
    GPIO_DICRECTION_t direction,
    GPIO_SENSITIVE_t sensitive,
    PORT_PULL_t pull,
    PORT_DRIVE_STRENGTH_t strength,
    PORT_PASSIVE_FILTER_t filter
)
{
    // set pin mux function
    ports[port]->PORT_PCR[pin].FIELD.MUX = mux;

    if (direction == GPIO_INPUT)
    {
        // setting port pull
        if (pull == PORT_PULL_DOWN)
        {
            ports[port]->PORT_PCR[pin].FIELD.PE = BIT_SET;
            ports[port]->PORT_PCR[pin].FIELD.PS = BIT_CLEAR;
        }
        else if (pull == PORT_PULL_UP)
        {
            ports[port]->PORT_PCR[pin].FIELD.PE = BIT_SET;
            ports[port]->PORT_PCR[pin].FIELD.PS = BIT_SET;
        }
        else
        {
            ports[port]->PORT_PCR[pin].FIELD.PE = BIT_CLEAR;
        }

        // set pin direction
        if (mux == GPIO_MUX_GPIO)
        {
            gpios[port]->PDDR.REG &= (~BIT_OFFSET(pin));
        }
    }
    else
    {
        // seting drive strength
        if(strength == PORT_STRENGTH_LOW)
        {
            ports[port]->PORT_PCR[pin].FIELD.DSE = BIT_CLEAR;
        }
        else
        {
            ports[port]->PORT_PCR[pin].FIELD.DSE = BIT_SET;
        }

        // set pin direction
        if (mux == GPIO_MUX_GPIO)
        {
            gpios[port]->PDDR.REG |= BIT_OFFSET(pin);
        }
    }

    // setting interrupt sensitive
    ports[port]->PORT_PCR[pin].FIELD.IRQC = sensitive;

    // setting pin filter
    ports[port]->PORT_PCR[pin].FIELD.PFE = filter;
}

void gpio_config_basic_input(PORT_NAME_t port, GPIO_PIN_t pin)
{
    gpio_config
    (
        port,
        pin,
        GPIO_MUX_GPIO,
        GPIO_INPUT,
        GPIO_SENSITIVE_DISABLE,
        PORT_PULL_DOWN,
        PORT_STRENGTH_LOW,
        PORT_FILTER_ENABLE
    );
}

void gpio_config_basic_input_with_interrupt(PORT_NAME_t port, GPIO_PIN_t pin)
{
    gpio_config
    (
        port,
        pin,
        GPIO_MUX_GPIO,
        GPIO_INPUT,
        GPIO_SENSITIVE_ISF_AND_INTERRUPT_ON_RISING_EDGE,
        PORT_PULL_DOWN,
        PORT_STRENGTH_LOW,
        PORT_FILTER_ENABLE
    );
}

void gpio_config_basic_output_low_strength(PORT_NAME_t port, GPIO_PIN_t pin)
{
    gpio_config
    (
        port,
        pin,
        GPIO_MUX_GPIO,
        GPIO_OUTPUT,
        GPIO_SENSITIVE_DISABLE,
        PORT_PULL_DISABLE,
        PORT_STRENGTH_LOW,
        PORT_FILTER_ENABLE
    );
}

void gpio_config_basic_output_high_strength(PORT_NAME_t port, GPIO_PIN_t pin)
{
    gpio_config
    (
        port,
        pin,
        GPIO_MUX_GPIO,
        GPIO_OUTPUT,
        GPIO_SENSITIVE_DISABLE,
        PORT_PULL_DISABLE,
        PORT_STRENGTH_LOW,
        PORT_FILTER_ENABLE
    );
}
