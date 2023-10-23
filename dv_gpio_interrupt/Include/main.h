#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdint.h>

// https://community.arm.com/support-forums/f/keil-forum/35398/hardcoded-breakpoint-preventing-program-from-running
// handle the optimize -O0 checking for main's argument
__asm(".global __ARM_use_no_argv");


void system_initialize(void);
void pcc_initialize(void);
void gpio_initialize(void);
void nvic_initialize(void);

#endif //! __MAIN_H__
