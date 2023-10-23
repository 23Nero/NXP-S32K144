/*
** ###################################################################
**     Processor:           S32K144
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, Mon Aug 14 13:58:18 2023
**
**     Abstract:
**         Peripheral Access Layer for S32K144
**
** ###################################################################
*/

#ifndef __CORTEX_M4_NVIC_H__
#define __CORTEX_M4_NVIC_H__

#include <stdint.h>
#include "common.h"

/** NVIC - Size of Registers Arrays */
#define NVIC_ISER_COUNT                      8u
#define NVIC_ICER_COUNT                      8u
#define NVIC_ISPR_COUNT                      8u
#define NVIC_ICPR_COUNT                      8u
#define NVIC_IABR_COUNT                      8u
#define NVIC_IP_COUNT                        240u

/** NVIC - Register Layout Typedef */
typedef struct {
    IO uint32_t  ISER[NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
       uint8_t   RESERVED_0[96];
    IO uint32_t  ICER[NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
       uint8_t   RESERVED_1[96];
    IO uint32_t  ISPR[NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
       uint8_t   RESERVED_2[96];
    IO uint32_t  ICPR[NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
       uint8_t   RESERVED_3[96];
    IO uint32_t  IABR[NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
       uint8_t   RESERVED_4[224];
    IO uint8_t   IP[NVIC_IP_COUNT];              /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
       uint8_t   RESERVED_5[2576];
    IO uint32_t  STIR;                           /**< Software Trigger Interrupt Register, offset: 0xE00 */
} NVIC_Type;

#define NVIC_BASE                            (0xE000E100u)
#define NVIC                                 ((NVIC_Type *)NVIC_BASE)

#endif //! #ifndef __CORTEX_M4_NVIC_H__
