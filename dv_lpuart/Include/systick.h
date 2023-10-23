#ifndef __CORTEX_M4_SYSTICK_H__
#define __CORTEX_M4_SYSTICK_H__

#include <stdint.h>
#include "common.h"

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t ENABLE : 1;
        RW uint32_t TICKINT : 1;
        RW uint32_t CLKSOURCE : 1;
        RO uint32_t RES0 : 13;
        RW uint32_t COUNTFLAG : 1;
        RO uint32_t RES1 : 15;
    } FIELD;
} SYSTICK_RVR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t TEN : 24;
        RO uint32_t RES0 : 6;
        RW uint32_t SKEW : 1;
        RO uint32_t NOREF : 1;
    } FIELD;
} SYSTICK_CALIB_t;

typedef struct
{
    IO    SYSTICK_RVR_t CSR;                /**< SysTick Control and Status Register, offset: 0x0 */
    IO    uint32_t RVR;                     /**< SysTick Reload Value Register, offset: 0x4 */
    IO    uint32_t CVR;                     /**< SysTick Current Value Register, offset: 0x8 */
    IO RO SYSTICK_CALIB_t CALIB;            /**< SysTick Calibration Value Register, offset: 0xC */
} SYSTICK_t;

#define SYSTICK_BASE                         (0xE000E010u)
#define SYSTICK                              ((SYSTICK_t *)SYSTICK_BASE)

// declare function prototype
void systick_initialize(uint32_t reload_value);
void systick_start(void);
void systick_stop(void);
uint32_t systick_get_ms(void);
void systick_clean(void);

void SysTick_Handler(void);

#endif //! #ifndef __CORTEX_M4_SYSTICK_H__
