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

#ifndef __S32K144_PCC_H__
#define __S32K144_PCC_H__

#include <stdint.h>
#include "common.h"

typedef union
{
    uint32_t REG;
    struct
    {
        RO uint32_t RES0 : 30;
        RW uint32_t CGC : 1;
        RO uint32_t PR : 1;
    } FIELD;
}PCC_THREE_FIELDS_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RO uint32_t RES0 : 24;
        RW uint32_t PCS : 3;
        RO uint32_t RES1 : 3;
        RW uint32_t CGC : 1;
        RO uint32_t PR : 1;
    } FIELD;
}PCC_FIVE_FIELDS_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t PCD : 3;
        RW uint32_t FRAC : 1;
        RO uint32_t RES0 : 20;
        RW uint32_t PCS : 3;
        RO uint32_t RES1 : 3;
        RW uint32_t CGC : 1;
        RO uint32_t PR : 1;
    } FIELD;
}PCC_SEVEN_FIELDS_t;

typedef struct PCC_Type
{
    DM uint8_t RES0[128];
    IO PCC_THREE_FIELDS_t PCC_FTFC;
    IO PCC_THREE_FIELDS_t PCC_DMAMUX;
    DM uint8_t RES1[8];
    IO PCC_THREE_FIELDS_t PCC_FlexCAN0;
    IO PCC_THREE_FIELDS_t PCC_FlexCAN1;
    IO PCC_FIVE_FIELDS_t PCC_FTM3;
    IO PCC_FIVE_FIELDS_t PCC_ADC1;
    DM uint8_t RES2[12];
    IO PCC_THREE_FIELDS_t PCC_FlexCAN2;
    IO PCC_FIVE_FIELDS_t PCC_LPSPI0;
    IO PCC_FIVE_FIELDS_t PCC_LPSPI1;
    IO PCC_FIVE_FIELDS_t PCC_LPSPI2;
    DM uint8_t RES3[8];
    IO PCC_THREE_FIELDS_t PCC_PDB1;
    IO PCC_THREE_FIELDS_t PCC_CRC;
    DM uint8_t RES4[12];
    IO PCC_THREE_FIELDS_t PCC_PDB0;
    IO PCC_FIVE_FIELDS_t PCC_LPIT;
    IO PCC_FIVE_FIELDS_t PCC_FTM0;
    IO PCC_FIVE_FIELDS_t PCC_FTM1;
    IO PCC_FIVE_FIELDS_t PCC_FTM2;
    IO PCC_FIVE_FIELDS_t PCC_ADC0;
    DM uint8_t RES5[4];
    IO PCC_THREE_FIELDS_t PCC_RTC;
    DM uint8_t RES6[8];
    IO PCC_SEVEN_FIELDS_t PCC_LPTMR0;
    DM uint8_t RES7[32];
    IO PCC_THREE_FIELDS_t PCC_PORTA;
    IO PCC_THREE_FIELDS_t PCC_PORTB;
    IO PCC_THREE_FIELDS_t PCC_PORTC;
    IO PCC_THREE_FIELDS_t PCC_PORTD;
    IO PCC_THREE_FIELDS_t PCC_PORTE;
    DM uint8_t RES8[24];
    IO PCC_THREE_FIELDS_t PCC_SAI0;
    IO PCC_THREE_FIELDS_t PCC_SAI1;
    DM uint8_t RES9[16];
    IO PCC_FIVE_FIELDS_t PCC_FlexIO;
    DM uint8_t RES10[24];
    IO PCC_THREE_FIELDS_t PCC_EWM;
    DM uint8_t RES11[16];
    IO PCC_FIVE_FIELDS_t PCC_LPI2C0;
    IO PCC_FIVE_FIELDS_t PCC_LPI2C1;
    DM uint8_t RES12[8];
    IO PCC_FIVE_FIELDS_t PCC_LPUART0;
    IO PCC_FIVE_FIELDS_t PCC_LPUART1;
    IO PCC_FIVE_FIELDS_t PCC_LPUART2;
    DM uint8_t RES13[4];
    IO PCC_FIVE_FIELDS_t PCC_FTM4;
    IO PCC_FIVE_FIELDS_t PCC_FTM5;
    IO PCC_FIVE_FIELDS_t PCC_FTM6;
    IO PCC_FIVE_FIELDS_t PCC_FTM7;
    DM uint8_t RES14[4];
    IO PCC_THREE_FIELDS_t PCC_CMP0;
    DM uint8_t RES15[8];
    IO PCC_THREE_FIELDS_t PCC_QSPI;
    DM uint8_t RES16[8];
    IO PCC_SEVEN_FIELDS_t PCC_ENET;
} PCC_t;

#define PCC_BASE_ADDRS      (0x40065000)
#define PCC                 ((PCC_t *) PCC_BASE_ADDRS)

#endif //! #ifndef __S32K144_PCC_H__
