#ifndef __S32K144_SCG_H__
#define __S32K144_SCG_H__

#include <stdint.h>
#include "common.h"

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t DIVSLOW : 4;
        RW uint32_t DIVBUS : 4;
        RO uint32_t RES0 : 8;
        RW uint32_t DIVCORE : 4;
        RO uint32_t RES1 : 4;
        RW uint32_t SCS : 4;
        RO uint32_t RES2 : 4;
    } FIELD;
} SCG_xCCR_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RO uint32_t RES0 : 24;
        RW uint32_t DIVCORE : 4;
        RO uint32_t RES1 : 4;
    } FIELD;
} SCG_CLKOUTCNFG_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t SOSCEN : 1;
        RO uint32_t RES0 : 15;
        RW uint32_t SOSCCM : 1;
        RW uint32_t SOSCCMRE : 1;
        RO uint32_t RES1 : 5;
        RW uint32_t LK : 1;
        RW uint32_t SOSCVLD : 1;
        RW uint32_t SOSCSEL : 1;
        RW uint32_t SOSCERR : 1;
        RO uint32_t RES2 : 5;
    } FIELD;
} SCG_SOSCCSR_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t SIRCEN : 1;
        RW uint32_t SIRCSTEN : 1;
        RW uint32_t SIRCLPEN : 1;
        RO uint32_t RES0 : 20;
        RW uint32_t LK : 1;
        RW uint32_t SIRCVLD : 1;
        RW uint32_t SIRCSEL : 1;
        RO uint32_t RES1 : 6;
    } FIELD;
} SCG_SIRCCSR_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t FIRCEN : 1;
        RO uint32_t RES0 : 2;
        RW uint32_t FIRCREGOFF : 1;
        RO uint32_t RES1 : 19;
        RW uint32_t LK : 1;
        RW uint32_t FIRCVLD : 1;
        RW uint32_t FIRCSEL : 1;
        RW uint32_t FIRCERR : 1;
        RO uint32_t RES2 : 5;
    } FIELD;
} SCG_FIRCCSR_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t SPLLEN : 1;
        RO uint32_t RES0 : 15;
        RW uint32_t SPLLCM : 1;
        RO uint32_t SPLLCMRE : 1;
        RO uint32_t RES1 : 5;
        RW uint32_t LK : 1;
        RW uint32_t SPLLVLD : 1;
        RW uint32_t SPLLSEL : 1;
        RW uint32_t SPLLERR : 1;
        RO uint32_t RES2 : 5;
    } FIELD;
} SCG_SPLLCSR_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t DIV1 : 3;
        RO uint32_t RES0 : 5;
        RW uint32_t DIV2 : 3;
        RO uint32_t RES1 : 21;
    } FIELD;
} SCG_xDIV_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RO uint32_t RES0 : 2;
        RW uint32_t EREFS : 1;
        RW uint32_t HGO : 1;
        RW uint32_t RANGE : 2;
        RO uint32_t RES1 : 26;
    } FIELD;
} SCG_SOSCCFG_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t RANGE : 2;
        RO uint32_t RES0 : 30;
    } FIELD;
} SCG_xCFG_t;

typedef union
{
    RW uint32_t REG;
    struct
    {
        RW uint32_t SOURCE : 1;
        RO uint32_t RES0 : 7;
        RW uint32_t PREDIV : 3;
        RO uint32_t RES1 : 5;
        RW uint32_t MULT : 5;
        RO uint32_t RES2 : 11;
    } FIELD;
} SCG_SPLLCFG_t;

typedef struct {
    IO RO uint32_t          VERID;                             /**< Version ID Register, offset: 0x0 */
    IO RO uint32_t          PARAM;                             /**< Parameter Register, offset: 0x4 */
          uint8_t           RESERVED_0[8];
    IO RO SCG_xCCR_t        CSR;                               /**< Clock Status Register, offset: 0x10 */
    IO    SCG_xCCR_t        RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
    IO    SCG_xCCR_t        VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
    IO    SCG_xCCR_t        HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
    IO    SCG_CLKOUTCNFG_t  CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
          uint8_t           RESERVED_1[220];
    IO    SCG_SOSCCSR_t     SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
    IO    SCG_xDIV_t        SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
    IO    SCG_SOSCCFG_t     SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
          uint8_t           RESERVED_2[244];
    IO    SCG_SIRCCSR_t     SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
    IO    SCG_xDIV_t        SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
    IO    SCG_xCFG_t        SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
          uint8_t           RESERVED_3[244];
    IO    SCG_FIRCCSR_t     FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
    IO    SCG_xDIV_t        FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
    IO    SCG_xCFG_t        FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
          uint8_t           RESERVED_4[756];
    IO    SCG_SPLLCSR_t     SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
    IO    SCG_xDIV_t        SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
    IO    SCG_SPLLCFG_t     SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_t;

#define SCG_BASE                                 (0x40064000u)
#define SCG                                      ((SCG_t *)SCG_BASE)

// this declaration is used for DIV register
typedef enum
{
    SCG_xDIV_DISABLE,
    SCG_xDIV_1,
    SCG_xDIV_2,
    SCG_xDIV_4,
    SCG_xDIV_8,
    SCG_xDIV_16,
    SCG_xDIV_32,
    SCG_xDIV_64
} eSCG_xDIV_t;

// this declaration is used for system clock config and SPLL pre_div
typedef enum
{
    SCG_DIV_1,
    SCG_DIV_2,
    SCG_DIV_3,
    SCG_DIV_4,
    SCG_DIV_5,
    SCG_DIV_6,
    SCG_DIV_7,
    SCG_DIV_8,
    SCG_DIV_9,
    SCG_DIV_10,
    SCG_DIV_11,
    SCG_DIV_12,
    SCG_DIV_13,
    SCG_DIV_14,
    SCG_DIV_15,
    SCG_DIV_16
} eSCG_DIV_t;

typedef enum
{
    SCG_SOSC_EXTERNAL_REF,
    SCG_SOSC_INTERNAL_OSC
} eSCG_SOSC_EREFS_t;

typedef enum
{
    SCG_SOSC_LOW_GAIN,
    SCG_SOSC_HIGH_GAIN
} eSCG_SOSC_HGO_t;

typedef enum
{
    SCG_SOSC_RES = 0,
    SCG_SOSC_LOW_FRE = 1,
    SCG_SOSC_MIDIUM_FRE = 2,
    SCG_SOSC_HIGH_FRE = 3,
    SCG_SIRC_2M = 0,
    SCG_SIRC_8M = 1,
    SCG_FIRC_48M = 0,
    SCG_FIRC_RES = 1
} eSCG_xRANGE_t;

typedef enum
{
    SCG_SPLL_SOURCE_SOSC,
    SCG_SPLL_SOURCE_FIRC
} eSCG_SPLL_SOURCE_t;

typedef enum
{
    SCG_SPLL_PREDIV_1,
    SCG_SPLL_PREDIV_2,
    SCG_SPLL_PREDIV_3,
    SCG_SPLL_PREDIV_4,
    SCG_SPLL_PREDIV_5,
    SCG_SPLL_PREDIV_6,
    SCG_SPLL_PREDIV_7,
    SCG_SPLL_PREDIV_8
} eSCG_SPLL_PREDIV_t;

typedef enum
{
    SCG_SPLL_MULT_16,
    SCG_SPLL_MULT_17,
    SCG_SPLL_MULT_18,
    SCG_SPLL_MULT_19,
    SCG_SPLL_MULT_20,
    SCG_SPLL_MULT_21,
    SCG_SPLL_MULT_22,
    SCG_SPLL_MULT_23,
    SCG_SPLL_MULT_24,
    SCG_SPLL_MULT_25,
    SCG_SPLL_MULT_26,
    SCG_SPLL_MULT_27,
    SCG_SPLL_MULT_28,
    SCG_SPLL_MULT_29,
    SCG_SPLL_MULT_30,
    SCG_SPLL_MULT_31,
    SCG_SPLL_MULT_32,
    SCG_SPLL_MULT_33,
    SCG_SPLL_MULT_34,
    SCG_SPLL_MULT_35,
    SCG_SPLL_MULT_36,
    SCG_SPLL_MULT_37,
    SCG_SPLL_MULT_38,
    SCG_SPLL_MULT_39,
    SCG_SPLL_MULT_40,
    SCG_SPLL_MULT_41,
    SCG_SPLL_MULT_42,
    SCG_SPLL_MULT_43,
    SCG_SPLL_MULT_44,
    SCG_SPLL_MULT_45,
    SCG_SPLL_MULT_46,
    SCG_SPLL_MULT_47
} eSCG_SPLL_MULT_t;

typedef enum
{
    SCG_RUN_MODE,
    SCG_VLPR_MODE,
    SCG_HSRUN_MODE
} eSCG_MODE_t;

typedef enum
{
    SCG_RES,
    SCG_SOSCSOURCE,
    SCG_SIRCSOURCE,
    SCG_FIRCSOURCE,
    SCG_SPLLSOURCE = 6
} eSCG_SYSTEM_CLOCK_SOURCE_t;

void scg_sosc_config
(
    eSCG_SOSC_EREFS_t eref,
    eSCG_SOSC_HGO_t hgo,
    eSCG_xRANGE_t range,
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
);

void scg_sirc_config
(
    eSCG_xRANGE_t range,
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
);

void scg_firc_config
(
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
);

void scg_spll_config
(
    eSCG_SPLL_SOURCE_t source,
    eSCG_SPLL_PREDIV_t prediv,
    eSCG_SPLL_MULT_t mult,
    eSCG_xDIV_t div1,
    eSCG_xDIV_t div2
);

void scg_system_clock_config
(
    eSCG_MODE_t mode,
    eSCG_DIV_t div_slow,
    eSCG_DIV_t div_bus,
    eSCG_DIV_t div_core,
    eSCG_SYSTEM_CLOCK_SOURCE_t source
);

#endif //! #ifndef __S32K144_SCG_H__
