
#ifndef __S32K144_PORT_H__
#define __S32K144_PORT_H__

#include <stdint.h>
#include "common.h"

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t PS : 1;
        RW uint32_t PE : 1;
        RO uint32_t RES0 : 2;
        RW uint32_t PFE : 1;
        RO uint32_t RES1 : 1;
        RW uint32_t DSE : 1;
        RO uint32_t RES2 : 1;
        RW uint32_t MUX : 3;
        RO uint32_t RES3 : 4;
        RW uint32_t LK : 1;
        RW uint32_t IRQC : 4;
        RO uint32_t RES4 : 4;
        RW uint32_t ISF : 1;
        RO uint32_t RES5 : 7;
    } FIELD;
} PORT_PCR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t GPWD : 16;
        RW uint32_t GPWE : 16;
    } FIELD;
} PORT_GPCLR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t GPWD : 16;
        RW uint32_t GPWE : 16;
    } FIELD;
} PORT_GPCHR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t GIWE : 16;
        RW uint32_t GIWD : 16;
    } FIELD;
} PORT_GICLR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t GIWE : 16;
        RW uint32_t GIWD : 16;
    } FIELD;
} PORT_GICHR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t CS : 1;
        RO uint32_t RES0 : 31;
    } FIELD;
} PORT_DFCR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t FILT : 5;
        RO uint32_t RES0 : 27;
    } FIELD;
} PORT_DFWR_t;

typedef struct PORT_Type
{
    IO PORT_PCR_t   PORT_PCR[32];
    IO PORT_GPCLR_t PORT_GPCLR;
    IO PORT_GPCHR_t PORT_GPCHR;
    IO PORT_GICLR_t PORT_GICLR;
    IO PORT_GICHR_t PORT_GICHR;
    DM uint8_t      RES1[16];
    IO uint32_t     PORT_ISFR;
    DM uint8_t      RES2[28];
    IO uint32_t     PORT_DFER;
    IO PORT_DFCR_t  PORT_DFCR;
    IO PORT_DFWR_t  PORT_DFWR;
} PORT_t;

#define PORT_A_BASE         0x40049000
#define PORT_B_BASE         0x4004A000
#define PORT_C_BASE         0x4004B000
#define PORT_D_BASE         0x4004C000
#define PORT_E_BASE         0x4004D000

#define PORT_A              ((PORT_t *) PORT_A_BASE)
#define PORT_B              ((PORT_t *) PORT_B_BASE)
#define PORT_C              ((PORT_t *) PORT_C_BASE)
#define PORT_D              ((PORT_t *) PORT_D_BASE)
#define PORT_E              ((PORT_t *) PORT_E_BASE)

#endif //! #ifndef __S32K144_PORT_H__
