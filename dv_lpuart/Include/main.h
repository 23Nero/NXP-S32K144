#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdint.h>

// https://community.arm.com/support-forums/f/keil-forum/35398/hardcoded-breakpoint-preventing-program-from-running
// handle the optimize -O0 checking for main argument
__asm(".global __ARM_use_no_argv");

typedef enum
{
    LED_MODE_OFF,
    LED_MODE_ON,
    LED_MODE_BLINK,
} led_mode_t;

typedef enum
{
    LED_ACTIVE_BLUE,
    LED_ACTIVE_RED,
    LED_ACTIVE_GREEN
} led_active_t;

typedef enum
{
    LED_ON,
    LED_OFF
}
led_state_t;

#define DEFAULT_SYS_CLOCK_FRE   48000000u
#define SYS_CLOCK_FRE           80000000u
#define SPLL_DIV2_CLOCK_FRE     20000000u
#define LPUART_BUFFER_SIZE      512u

#define LED_MASK(offset)        (uint32_t)(0x1u << (offset))

void system_initialize(void);
void scg_initialize(void);
void lpit_initialize(void);
void pcc_initialize(void);
void gpio_initialize(void);
void lpuart_initialize(void);
void nvic_initialize(void);
void process_led(void);
void process_uart_message(void);
void delay_lpit(uint32_t s);

#endif //! __MAIN_H__
