
#ifndef __PORT_GPIO_H__
#define __PORT_GPIO_H__

#include "common.h"
#include "port.h"
#include "gpio.h"

#define ACCESS_BIT(field, bit)      ((field).P##bit)
#define BIT_OFFSET(offset)					(uint32_t)(1<<offset)

// define gpio - port data
typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE
} PORT_NAME_t;

typedef enum
{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15,
    GPIO_PIN16,
    GPIO_PIN17
} GPIO_PIN_t;

typedef enum
{
    GPIO_MUX_ANALOG,
    GPIO_MUX_GPIO,
    GPIO_MUX_ALTER_2,
    GPIO_MUX_ALTER_3,
    GPIO_MUX_ALTER_4,
    GPIO_MUX_ALTER_5,
    GPIO_MUX_ALTER_6,
    GPIO_MUX_ALTER_7
} GPIO_MUX_t;

typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT
} GPIO_DICRECTION_t;

typedef enum
{
    GPIO_SENSITIVE_DISABLE                             = 0,
    GPIO_SENSITIVE_ISF_AND_DMA_ON_RISING_EDGE          = 1,
    GPIO_SENSITIVE_ISF_AND_DMA_ON_FALLING_EDGE         = 2,
    GPIO_SENSITIVE_ISF_AND_DMA_ON_BOTH_EDGE            = 3,
    GPIO_SENSITIVE_ISF_AND_INTERRUPT_ON_LOGIC_LEVEL_0  = 8,
    GPIO_SENSITIVE_ISF_AND_INTERRUPT_ON_RISING_EDGE    = 9,
    GPIO_SENSITIVE_ISF_AND_INTERRUPT_ON_FALLING_EDGE   = 10,
    GPIO_SENSITIVE_ISF_AND_INTERRUPT_ON_BOTH_EDGE      = 11,
    GPIO_SENSITIVE_ISF_AND_INTERRUPT_ON_LOGIC_LEVEL_1  = 12
} GPIO_SENSITIVE_t;

typedef enum
{
    PORT_PULL_DISABLE,
    PORT_PULL_UP,
    PORT_PULL_DOWN
} PORT_PULL_t;

typedef enum
{
    PORT_STRENGTH_LOW,
    PORT_STRENGTH_HIGH
} PORT_DRIVE_STRENGTH_t;

typedef enum
{
    PORT_FILTER_DISABLE,
    PORT_FILTER_ENABLE
} PORT_PASSIVE_FILTER_t;

// declare function prototype
void PORTA_IRQHandler(void);
void PORTB_IRQHandler(void);
void PORTC_IRQHandler(void);
void PORTD_IRQHandler(void);
void PORTE_IRQHandler(void);

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
);

void gpio_config_basic_input(PORT_NAME_t port, GPIO_PIN_t pin);
void gpio_config_basic_input_with_interrupt(PORT_NAME_t port, GPIO_PIN_t pin);
void gpio_config_basic_output_low_strength(PORT_NAME_t port, GPIO_PIN_t pin);
void gpio_config_basic_output_high_strength(PORT_NAME_t port, GPIO_PIN_t pin);

#endif //! __PORT_GPIO_H__
