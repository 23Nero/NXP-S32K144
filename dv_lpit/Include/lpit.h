#ifndef __S32K144_LPIT_H__
#define __S32K144_LPIT_H__

#include <stdint.h>
#include <stdbool.h>
#include "common.h"

#define LPIT_TMR_COUNT                           4u

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t M_CEN   : 1;
        RW uint32_t SW_RST  : 1;
        RW uint32_t DOZE_EN : 1;
        RW uint32_t DBG_EN  : 1;
        RO uint32_t RES0    : 28;
    } FIELD;
} LPIT_MCR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t TIF0 : 1;
        RW uint32_t TIF1 : 1;
        RW uint32_t TIF2 : 1;
        RW uint32_t TIF3 : 1;
        RO uint32_t RES0 : 28;
    } FIELD;
} LPIT_MSR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t TIE0 : 1;
        RW uint32_t TIE1 : 1;
        RW uint32_t TIE2 : 1;
        RW uint32_t TIE3 : 1;
        RO uint32_t RES0 : 28;
    } FIELD;
} LPIT_MIER_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t SET_T_EN_0 : 1;
        RW uint32_t SET_T_EN_1 : 1;
        RW uint32_t SET_T_EN_2 : 1;
        RW uint32_t SET_T_EN_3 : 1;
        RO uint32_t RES0 : 28;
    } FIELD;
} LPIT_SETTEN_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t CLR_T_EN_0 : 1;
        RW uint32_t CLR_T_EN_1 : 1;
        RW uint32_t CLR_T_EN_2 : 1;
        RW uint32_t CLR_T_EN_3 : 1;
        RO uint32_t RES0 : 28;
    } FIELD;
} LPIT_CLRTEN_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t T_EN    : 1;
        RW uint32_t CHAIN   : 1;
        RW uint32_t MODE    : 2;
        RO uint32_t RES0    : 12;
        RW uint32_t TSOT    : 1;
        RW uint32_t TSOI    : 1;
        RW uint32_t TROT    : 1;
        RO uint32_t RES1    : 4;
        RW uint32_t TRG_SRC : 1;
        RW uint32_t TRG_SEL : 4;
        RO uint32_t RES2    : 4;
    } FIELD;
} LPIT_TCTRL_t;

typedef struct
{
    IO RO uint32_t      VERID;                          /**< Version ID Register, offset: 0x0 */
    IO RO uint32_t      PARAM;                          /**< Parameter Register, offset: 0x4 */
    IO    LPIT_MCR_t    MCR;                            /**< Module Control Register, offset: 0x8 */
    IO    LPIT_MSR_t    MSR;                            /**< Module Status Register, offset: 0xC */
    IO    LPIT_MIER_t   MIER;                           /**< Module Interrupt Enable Register, offset: 0x10 */
    IO    LPIT_SETTEN_t SETTEN;                         /**< Set Timer Enable Register, offset: 0x14 */
    IO    LPIT_CLRTEN_t CLRTEN;                         /**< Clear Timer Enable Register, offset: 0x18 */
          uint8_t       RES0[4];
    struct
    {                                                   /* offset: 0x20, array step: 0x10 */
        IO    uint32_t     TVAL;                        /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
        IO RO uint32_t     CVAL;                        /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
        IO    LPIT_TCTRL_t TCTRL;                       /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
              uint8_t      RES0[4];
    } TMR[LPIT_TMR_COUNT];
} LPIT_t;

#define LPIT_BASE                               (0x40037000u)
#define LPIT                                    ((LPIT_t *)LPIT_BASE)

typedef enum
{
    LPIT_CHANNEL_0,
    LPIT_CHANNEL_1,
    LPIT_CHANNEL_2,
    LPIT_CHANNEL_3
} LPIT_CHANNEL_t;

typedef enum
{
    LPIT_CHANNEL_PRIODIC_COUNTER,
    LPIT_CHANNEL_DUAL_16BIT,
    LPIT_CHANNEL_TRIGGER_ACCUMULATOR,
    LPIT_CHANNEL_INPUT_CAPTURE
} LPIT_CHANNEL_RUNNING_MODE_t;

void LPIT0_Ch0_IRQHandler(void);
void LPIT0_Ch1_IRQHandler(void);
void LPIT0_Ch2_IRQHandler(void);
void LPIT0_Ch3_IRQHandler(void);

void lpit_general_config
(
    bool enable_module_clock,
    bool enable_software_reset,
    bool enable_doze,
    bool enable_run_on_debug
);

void lpit_channel_config
(
    LPIT_CHANNEL_t channel,
    bool enable_chain,
    LPIT_CHANNEL_RUNNING_MODE_t mode,
    bool enable_stop_on_interrupt
);

void lpit_enable_interrupt(LPIT_CHANNEL_t channel);
void lpit_disable_interrupt(LPIT_CHANNEL_t channel);
void lpit_enable_single_channel(LPIT_CHANNEL_t channel);
void lpit_disable_single_channel(LPIT_CHANNEL_t channel);

uint32_t lpit_get_reload_value(LPIT_CHANNEL_t channel);
void lpit_set_reload_value
(
    LPIT_CHANNEL_t channel,
    uint32_t reload_value
);

#endif //! #ifndef __S32K144_LPIT_H__
