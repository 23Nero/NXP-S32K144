#ifndef __S32K144_LPUART_H__
#define __S32K144_LPUART_H__

#include <stdint.h>
#include <stdbool.h>
#include "common.h"

typedef union
{
    uint32_t REG;
    struct
    {
        RO uint32_t RES0 : 1;
        RW uint32_t RST  : 1;
        RO uint32_t RES1 : 30;
    } FIELD;
} LPUART_GLOBAL_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t TRGSEL : 2;
        RO uint32_t RES0   : 30;
    } FIELD;
} LPUART_PINCFG_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t SBR       : 13;
        RW uint32_t SBNS      : 1;
        RW uint32_t RXEDGIE   : 1;
        RW uint32_t LBKDIE    : 1;
        RW uint32_t RESYNCDIS : 1;
        RW uint32_t BOTHEDGE  : 1;
        RW uint32_t MATCFG    : 2;
        RW uint32_t RIDMAE    : 1;
        RW uint32_t RDMAE     : 1;
        RO uint32_t RES0      : 1;
        RW uint32_t TDMAE     : 1;
        RW uint32_t OSR       : 5;
        RW uint32_t M10       : 1;
        RW uint32_t MAEN2     : 1;
        RW uint32_t MAEN1     : 1;
    } FIELD;
} LPUART_BAUD_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RO uint32_t RES0   : 14;
        RW uint32_t MA2F   : 1;
        RW uint32_t MA1F   : 1;
        RW uint32_t PF     : 1;
        RW uint32_t FE     : 1;
        RW uint32_t NF     : 1;
        RW uint32_t OR     : 1;
        RW uint32_t IDLE   : 1;
        RO uint32_t RDRF   : 1;
        RO uint32_t TC     : 1;
        RO uint32_t TDRE   : 1;
        RO uint32_t RAF    : 1;
        RW uint32_t LBKDE  : 1;
        RW uint32_t BRK13  : 1;
        RW uint32_t RWUID  : 1;
        RW uint32_t RXINV  : 1;
        RW uint32_t MSBF   : 1;
        RW uint32_t RXEDGIF: 1;
        RW uint32_t LBKDIF : 1;
    } FIELD;
} LPUART_STAT_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t PT      : 1;
        RW uint32_t PE      : 1;
        RW uint32_t ILT     : 1;
        RW uint32_t WAKE    : 1;
        RW uint32_t M       : 1;
        RW uint32_t RSRC    : 1;
        RW uint32_t DOZEEN  : 1;
        RW uint32_t LOOPS   : 1;
        RW uint32_t IDLECFG : 3;
        RW uint32_t M7      : 1;
        RO uint32_t RES0    : 2;
        RW uint32_t MA2IE   : 1;
        RW uint32_t MA1IE   : 1;
        RW uint32_t SBK     : 1;
        RW uint32_t RWU     : 1;
        RW uint32_t RE      : 1;
        RW uint32_t TE      : 1;
        RW uint32_t ILIE    : 1;
        RW uint32_t RIE     : 1;
        RW uint32_t TCIE    : 1;
        RW uint32_t TIE     : 1;
        RW uint32_t PEIE    : 1;
        RW uint32_t FEIE    : 1;
        RW uint32_t NEIE    : 1;
        RW uint32_t ORIE    : 1;
        RW uint32_t TXINV   : 1;
        RW uint32_t TXDIR   : 1;
        RW uint32_t R9T8    : 1;
        RW uint32_t R8T9    : 1;
    } FIELD;
} LPUART_CTRL_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t R0T0    : 1;
        RW uint32_t R1T1    : 1;
        RW uint32_t R2T2    : 1;
        RW uint32_t R3T3    : 1;
        RW uint32_t R4T4    : 1;
        RW uint32_t R5T5    : 1;
        RW uint32_t R6T6    : 1;
        RW uint32_t R7T7    : 1;
        RW uint32_t R8T8    : 1;
        RW uint32_t R9T9    : 1;
        RO uint32_t RES0    : 1;
        RO uint32_t IDLINE  : 1;
        RO uint32_t RXEMPT  : 1;
        RW uint32_t FRETSC  : 1;
        RO uint32_t PARITYE : 1;
        RO uint32_t NOISY   : 1;
        RO uint32_t RES1    : 16;
    } FIELD;
} LPUART_DATA_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t MA1     : 10;
        RO uint32_t RES0    : 6;
        RW uint32_t MA2     : 10;
        RO uint32_t RES1    : 6;
    } FIELD;
} LPUART_MATCH_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t TXCTSE   : 1;
        RW uint32_t TXRTSE   : 1;
        RW uint32_t TXRTSPOL : 1;
        RW uint32_t RXRTSE   : 1;
        RW uint32_t TXCTSC   : 1;
        RW uint32_t TXCTSSRC : 1;
        RO uint32_t RES0     : 2;
        RW uint32_t RTSWATER : 2;
        RO uint32_t RES1     : 6;
        RW uint32_t TNP      : 2;
        RW uint32_t IREN     : 1;
        RO uint32_t RES2     : 13;
    } FIELD;
} LPUART_MODIR_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RO uint32_t RXFIFOSIZE : 3;
        RW uint32_t RXFE       : 1;
        RO uint32_t TXFIFOSIZE : 3;
        RW uint32_t TXFE       : 1;
        RW uint32_t RXUFE      : 1;
        RW uint32_t TXOFE      : 1;
        RW uint32_t RXIDEN     : 3;
        RO uint32_t RES0       : 1;
        RW uint32_t RXFLUSH    : 1;
        RW uint32_t TXFLUSH    : 1;
        RW uint32_t RXUF       : 1;
        RW uint32_t TXOF       : 1;
        RO uint32_t RES1       : 4;
        RO uint32_t RXEMPT     : 1;
        RO uint32_t TXEMPT     : 1;
        RO uint32_t RES2       : 8;
    } FIELD;
} LPUART_FIFO_t;

typedef union
{
    uint32_t REG;
    struct
    {
        RW uint32_t TXWATER  : 2;
        RO uint32_t RES0     : 6;
        RO uint32_t TXCOUNT  : 3;
        RO uint32_t RES1     : 5;
        RW uint32_t RXWATER  : 2;
        RO uint32_t RES2     : 6;
        RO uint32_t RXCOUNT  : 3;
        RO uint32_t RES3     : 5;
    } FIELD;
} LPUART_WATER_t;

typedef struct
{
    IO RO   uint32_t            VERID;           /**< Version ID Register, offset: 0x0 */
    IO RO   uint32_t            PARAM;           /**< Parameter Register, offset: 0x4 */
    IO      LPUART_GLOBAL_t     GLOBAL;          /**< LPUART Global Register, offset: 0x8 */
    IO      LPUART_PINCFG_t     PINCFG;          /**< LPUART Pin Configuration Register, offset: 0xC */
    IO      LPUART_BAUD_t       BAUD;            /**< LPUART Baud Rate Register, offset: 0x10 */
    IO      LPUART_STAT_t       STAT;            /**< LPUART Status Register, offset: 0x14 */
    IO      LPUART_CTRL_t       CTRL;            /**< LPUART Control Register, offset: 0x18 */
    IO      LPUART_DATA_t       DATA;            /**< LPUART Data Register, offset: 0x1C */
    IO      LPUART_MATCH_t      MATCH;           /**< LPUART Match Address Register, offset: 0x20 */
    IO      LPUART_MODIR_t      MODIR;           /**< LPUART Modem IrDA Register, offset: 0x24 */
    IO      LPUART_FIFO_t       FIFO;            /**< LPUART FIFO Register, offset: 0x28 */
    IO      LPUART_WATER_t      WATER;           /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_t;

#define LPUART0_BASE                             (0x4006A000u)
#define LPUART1_BASE                             (0x4006B000u)
#define LPUART2_BASE                             (0x4006C000u)

#define LPUART0                                  ((LPUART_t *)LPUART0_BASE)
#define LPUART1                                  ((LPUART_t *)LPUART1_BASE)
#define LPUART2                                  ((LPUART_t *)LPUART2_BASE)

#define LPUART_BAUD_RATE_MODULO_DIVISOR_MASK     0x7FFu
#define LPUART_8BIT_DATA_MASK                    0xFFu

typedef enum
{
    LPUART_CHANNEL_0,
    LPUART_CHANNEL_1,
    LPUART_CHANNEL_2
} LPUART_CHANNEL_t;

typedef enum
{
    LPUART_PARITY_DISABLE,
    LPUART_PARITY_EVEN,
    LPUART_PARITY_ODD
} LPUART_PARITY_t;

typedef enum
{
    LPUART_DATA_7_BIT,
    LPUART_DATA_8_BIT,
    LPUART_DATA_9_BIT
} LPUART_DATA_BIT_t;

typedef enum
{
    LPUART_BAUDRATE_9600 = 9600,
    LPUART_BAUDRATE_19200 = 19200,
    LPUART_BAUDRATE_38400 = 38400,
    LPUART_BAUDRATE_115200 = 115200
} LPUART_BAUDRATE_t;

typedef enum
{
    LPUART_OVERSAMPLING_DEFAULT_16,
    LPUART_OVERSAMPLING_RES0,
    LPUART_OVERSAMPLING_RES1,
    LPUART_OVERSAMPLING_4_BOTH_EDGE,
    LPUART_OVERSAMPLING_5_BOTH_EDGE,
    LPUART_OVERSAMPLING_6_BOTH_EDGE,
    LPUART_OVERSAMPLING_7_BOTH_EDGE,
    LPUART_OVERSAMPLING_8,
    LPUART_OVERSAMPLING_9,
    LPUART_OVERSAMPLING_10,
    LPUART_OVERSAMPLING_11,
    LPUART_OVERSAMPLING_12,
    LPUART_OVERSAMPLING_13,
    LPUART_OVERSAMPLING_14,
    LPUART_OVERSAMPLING_15,
    LPUART_OVERSAMPLING_16,
    LPUART_OVERSAMPLING_17,
    LPUART_OVERSAMPLING_18,
    LPUART_OVERSAMPLING_19,
    LPUART_OVERSAMPLING_20,
    LPUART_OVERSAMPLING_21,
    LPUART_OVERSAMPLING_22,
    LPUART_OVERSAMPLING_23,
    LPUART_OVERSAMPLING_24,
    LPUART_OVERSAMPLING_25,
    LPUART_OVERSAMPLING_26,
    LPUART_OVERSAMPLING_27,
    LPUART_OVERSAMPLING_28,
    LPUART_OVERSAMPLING_29,
    LPUART_OVERSAMPLING_30,
    LPUART_OVERSAMPLING_31,
    LPUART_OVERSAMPLING_32
} LPUART_OVERSAMPLING_t;

void LPUART0_RxTx_IRQHandler(void);
void LPUART1_RxTx_IRQHandler(void);
void LPUART2_RxTx_IRQHandler(void);

void lpuart_parity_config(LPUART_CHANNEL_t channel, LPUART_PARITY_t parity);
void lpuart_baudrate_config
(
    LPUART_CHANNEL_t channel,
    LPUART_OVERSAMPLING_t over_sampling,
    LPUART_BAUDRATE_t baudrate,
    uint32_t baud_clock
);
void lpuart_frame_config
(
    LPUART_CHANNEL_t channel,
    bool enable_two_stop_bit,
    LPUART_DATA_BIT_t data_bit,
    LPUART_PARITY_t parity
);
void lpuart_enable_tx(LPUART_CHANNEL_t channel);
void lpuart_enable_rx(LPUART_CHANNEL_t channel);
void lpuart_disable_tx(LPUART_CHANNEL_t channel);
void lpuart_disable_rx(LPUART_CHANNEL_t channel);
void lpuart_wait_data_no_interrupt(LPUART_CHANNEL_t channel, uint8_t *buffer, uint32_t data_length);
void lpuart_send_data_no_interrupt(LPUART_CHANNEL_t channel, const uint8_t *buffer);
void lpuart_interupt_config
(
    LPUART_CHANNEL_t channel,
    bool enable_tx,
    bool enable_rx
);
void lpuart_get_char(LPUART_CHANNEL_t channel, uint8_t *buffer);

#endif //! #ifndef __S32K144_LPUART_H__
