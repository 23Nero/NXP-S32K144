#include <stdint.h>
#include <stdbool.h>
#include "lpuart.h"

static LPUART_t* lpuarts[] = {LPUART0, LPUART1, LPUART2};

void lpuart_parity_config(LPUART_CHANNEL_t channel, LPUART_PARITY_t parity)
{
    if (parity == LPUART_PARITY_DISABLE)
    {
        lpuarts[channel]->CTRL.FIELD.PE = BIT_CLEAR;
    }
    else
    {
        lpuarts[channel]->CTRL.FIELD.PE = BIT_SET;
        if (parity == LPUART_PARITY_EVEN)
        {
            lpuarts[channel]->CTRL.FIELD.PT = BIT_CLEAR;
        }
        else
        {
            lpuarts[channel]->CTRL.FIELD.PT = BIT_CLEAR;
        }
    }
}

void lpuart_baudrate_config
(
    LPUART_CHANNEL_t channel,
    LPUART_OVERSAMPLING_t over_sampling,
    LPUART_BAUDRATE_t baudrate,
    uint32_t baud_clock
)
{
    uint32_t SBR;
    // disable Rx/Tx for further configuration
    lpuarts[channel]->CTRL.FIELD.TE = BIT_CLEAR;
    lpuarts[channel]->CTRL.FIELD.RE = BIT_CLEAR;

    if ((over_sampling > LPUART_OVERSAMPLING_RES1) && (over_sampling < LPUART_OVERSAMPLING_8))
    {
        lpuarts[channel]->BAUD.FIELD.BOTHEDGE = BIT_SET;
    }
    lpuarts[channel]->BAUD.FIELD.OSR = over_sampling;

    SBR = (baud_clock/((over_sampling + 1)*baudrate));
    lpuarts[channel]->BAUD.FIELD.SBR = (LPUART_BAUD_RATE_MODULO_DIVISOR_MASK & SBR);
}

void lpuart_frame_config
(
    LPUART_CHANNEL_t channel,
    bool enable_two_stop_bit,
    LPUART_DATA_BIT_t data_bit,
    LPUART_PARITY_t parity
)
{
    lpuarts[channel]->BAUD.FIELD.SBNS = enable_two_stop_bit;
    if (data_bit == LPUART_DATA_7_BIT)
    {
        lpuarts[channel]->CTRL.FIELD.M7 = BIT_SET;
    }
    else
    {
        lpuarts[channel]->CTRL.FIELD.M7 = BIT_CLEAR;
        if (data_bit == LPUART_DATA_8_BIT)
        {
            lpuarts[channel]->CTRL.FIELD.M = BIT_CLEAR;
        }
        else
        {
            lpuarts[channel]->CTRL.FIELD.M = BIT_SET;
        }
    }

    lpuart_parity_config(channel, parity);
}

void lpuart_enable_tx(LPUART_CHANNEL_t channel)
{
    lpuarts[channel]->CTRL.FIELD.TE = BIT_SET;
}

void lpuart_enable_rx(LPUART_CHANNEL_t channel)
{
    lpuarts[channel]->CTRL.FIELD.RE = BIT_SET;
}

void lpuart_disable_tx(LPUART_CHANNEL_t channel)
{
    lpuarts[channel]->CTRL.FIELD.TE = BIT_CLEAR;
}

void lpuart_disable_rx(LPUART_CHANNEL_t channel)
{
    lpuarts[channel]->CTRL.FIELD.RE = BIT_CLEAR;
}

void lpuart_interupt_config
(
    LPUART_CHANNEL_t channel,
    bool enable_tx,
    bool enable_rx
)
{
    if (enable_rx)
    {
        lpuarts[channel]->CTRL.FIELD.RIE = BIT_SET;
    }
    if (enable_tx)
    {
        lpuarts[channel]->CTRL.FIELD.TIE = BIT_SET;
    }
}

void lpuart_get_char(LPUART_CHANNEL_t channel, uint8_t *buffer)
{
    // wait for the data, this is optional since this function is called from LPUART IRQ handler and Tx FIFO is not used
    // while (lpuarts[channel]->STAT.FIELD.RDRF == BIT_CLEAR){}
    *buffer = (lpuarts[channel]->DATA.REG & LPUART_8BIT_DATA_MASK);
}

void lpuart_wait_data_no_interrupt(LPUART_CHANNEL_t channel, uint8_t *buffer, uint32_t data_length)
{
    uint32_t i = 0;
    lpuart_enable_rx(channel);
    for (i = 0; i < data_length; i++)
    {
        // waiting untill the rx data register is full
        while (lpuarts[channel]->STAT.FIELD.RDRF == BIT_CLEAR){}

        // read the data till read the end of line or reach the data length
        buffer[i] = (lpuarts[channel]->DATA.REG & LPUART_8BIT_DATA_MASK);
        if (buffer[i] == '\n' || buffer[i] == '\r')
        {
            break;
        }
    }
    lpuart_disable_rx(channel);
}

void lpuart_send_data_no_interrupt(LPUART_CHANNEL_t channel, const uint8_t *buffer)
{
    uint32_t index = 0;
    lpuart_enable_tx(channel);
    while (1)
    {
        // waiting untill the tx data register is empty, mean previous data is sent
        while (lpuarts[channel]->STAT.FIELD.TDRE == BIT_CLEAR){}

        // send data
        lpuarts[channel]->DATA.REG = buffer[index++] & LPUART_8BIT_DATA_MASK;

        // check if data is completely sent, here is the handle for end of string only
        // in practice, the handle may vary depend on the design
        if (buffer[index] == 0)
        {
            break;
        }
    }
    lpuart_disable_tx(channel);
}
