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

typedef enum
{
    /* Auxiliary constants */
    IRQn_NotAvail                = -128,             /**< Not available device specific interrupt */

    /* Core interrupts */
    IRQn_NonMaskableInt          = -14,              /**< Non Maskable Interrupt */
    IRQn_HardFault               = -13,              /**< Cortex-M4 SV Hard Fault Interrupt */
    IRQn_MemoryManagement        = -12,              /**< Cortex-M4 Memory Management Interrupt */
    IRQn_BusFault                = -11,              /**< Cortex-M4 Bus Fault Interrupt */
    IRQn_UsageFault              = -10,              /**< Cortex-M4 Usage Fault Interrupt */
    IRQn_SVCall                  = -5,               /**< Cortex-M4 SV Call Interrupt */
    IRQn_DebugMonitor            = -4,               /**< Cortex-M4 Debug Monitor Interrupt */
    IRQn_PendSV                  = -2,               /**< Cortex-M4 Pend SV Interrupt */
    IRQn_SysTick                 = -1,               /**< Cortex-M4 System Tick Interrupt */

    /* Device specific interrupts */
    IRQn_DMA0                    = 0u,               /**< DMA channel 0 transfer complete */
    IRQn_DMA1                    = 1u,               /**< DMA channel 1 transfer complete */
    IRQn_DMA2                    = 2u,               /**< DMA channel 2 transfer complete */
    IRQn_DMA3                    = 3u,               /**< DMA channel 3 transfer complete */
    IRQn_DMA4                    = 4u,               /**< DMA channel 4 transfer complete */
    IRQn_DMA5                    = 5u,               /**< DMA channel 5 transfer complete */
    IRQn_DMA6                    = 6u,               /**< DMA channel 6 transfer complete */
    IRQn_DMA7                    = 7u,               /**< DMA channel 7 transfer complete */
    IRQn_DMA8                    = 8u,               /**< DMA channel 8 transfer complete */
    IRQn_DMA9                    = 9u,               /**< DMA channel 9 transfer complete */
    IRQn_DMA10                   = 10u,              /**< DMA channel 10 transfer complete */
    IRQn_DMA11                   = 11u,              /**< DMA channel 11 transfer complete */
    IRQn_DMA12                   = 12u,              /**< DMA channel 12 transfer complete */
    IRQn_DMA13                   = 13u,              /**< DMA channel 13 transfer complete */
    IRQn_DMA14                   = 14u,              /**< DMA channel 14 transfer complete */
    IRQn_DMA15                   = 15u,              /**< DMA channel 15 transfer complete */
    IRQn_DMA_Error               = 16u,              /**< DMA error interrupt channels 0-15 */
    IRQn_MCM                     = 17u,              /**< FPU sources */
    IRQn_FTFC                    = 18u,              /**< FTFC Command complete */
    IRQn_Read_Collision          = 19u,              /**< FTFC Read collision */
    IRQn_LVD_LVW                 = 20u,              /**< PMC Low voltage detect interrupt */
    IRQn_FTFC_Fault              = 21u,              /**< FTFC Double bit fault detect */
    IRQn_WDOG_EWM                = 22u,              /**< Single interrupt vector for WDOG and EWM */
    IRQn_RCM                     = 23u,              /**< RCM Asynchronous Interrupt */
    IRQn_LPI2C0_Master           = 24u,              /**< LPI2C0 Master Interrupt */
    IRQn_LPI2C0_Slave            = 25u,              /**< LPI2C0 Slave Interrupt */
    IRQn_LPSPI0                  = 26u,              /**< LPSPI0 Interrupt */
    IRQn_LPSPI1                  = 27u,              /**< LPSPI1 Interrupt */
    IRQn_LPSPI2                  = 28u,              /**< LPSPI2 Interrupt */
    IRQn_LPUART0_RxTx            = 31u,              /**< LPUART0 Transmit / Receive Interrupt */
    IRQn_LPUART1_RxTx            = 33u,              /**< LPUART1 Transmit / Receive  Interrupt */
    IRQn_LPUART2_RxTx            = 35u,              /**< LPUART2 Transmit / Receive  Interrupt */
    IRQn_ADC0                    = 39u,              /**< ADC0 interrupt request. */
    IRQn_ADC1                    = 40u,              /**< ADC1 interrupt request. */
    IRQn_CMP0                    = 41u,              /**< CMP0 interrupt request */
    IRQn_ERM_single_fault        = 44u,              /**< ERM single bit error correction */
    IRQn_ERM_double_fault        = 45u,              /**< ERM double bit error non-correctable */
    IRQn_RTC                     = 46u,              /**< RTC alarm interrupt */
    IRQn_RTC_Seconds             = 47u,              /**< RTC seconds interrupt */
    IRQn_LPIT0_Ch0               = 48u,              /**< LPIT0 channel 0 overflow interrupt */
    IRQn_LPIT0_Ch1               = 49u,              /**< LPIT0 channel 1 overflow interrupt */
    IRQn_LPIT0_Ch2               = 50u,              /**< LPIT0 channel 2 overflow interrupt */
    IRQn_LPIT0_Ch3               = 51u,              /**< LPIT0 channel 3 overflow interrupt */
    IRQn_PDB0                    = 52u,              /**< PDB0 interrupt */
    IRQn_SCG                     = 57u,              /**< SCG bus interrupt request */
    IRQn_LPTMR0                  = 58u,              /**< LPTIMER interrupt request */
    IRQn_PORTA                   = 59u,              /**< Port A pin detect interrupt */
    IRQn_PORTB                   = 60u,              /**< Port B pin detect interrupt */
    IRQn_PORTC                   = 61u,              /**< Port C pin detect interrupt */
    IRQn_PORTD                   = 62u,              /**< Port D pin detect interrupt */
    IRQn_PORTE                   = 63u,              /**< Port E pin detect interrupt */
    IRQn_SWI                     = 64u,              /**< Software interrupt */
    IRQn_PDB1                    = 68u,              /**< PDB1 interrupt */
    IRQn_FLEXIO                  = 69u,              /**< FlexIO Interrupt */
    IRQn_CAN0_ORed               = 78u,              /**< CAN0 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
    IRQn_CAN0_Error              = 79u,              /**< CAN0 Interrupt indicating that errors were detected on the CAN bus */
    IRQn_CAN0_Wake_Up            = 80u,              /**< CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode */
    IRQn_CAN0_ORed_0_15_MB       = 81u,              /**< CAN0 OR'ed Message buffer (0-15) */
    IRQn_CAN0_ORed_16_31_MB      = 82u,              /**< CAN0 OR'ed Message buffer (16-31) */
    IRQn_CAN1_ORed               = 85u,              /**< CAN1 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
    IRQn_CAN1_Error              = 86u,              /**< CAN1 Interrupt indicating that errors were detected on the CAN bus */
    IRQn_CAN1_ORed_0_15_MB       = 88u,              /**< CAN1 OR'ed Interrupt for Message buffer (0-15) */
    IRQn_CAN2_ORed               = 92u,              /**< CAN2 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
    IRQn_CAN2_Error              = 93u,              /**< CAN2 Interrupt indicating that errors were detected on the CAN bus */
    IRQn_CAN2_ORed_0_15_MB       = 95u,              /**< CAN2 OR'ed Message buffer (0-15) */
    IRQn_FTM0_Ch0_Ch1            = 99u,              /**< FTM0 Channel 0 and 1 interrupt */
    IRQn_FTM0_Ch2_Ch3            = 100u,             /**< FTM0 Channel 2 and 3 interrupt */
    IRQn_FTM0_Ch4_Ch5            = 101u,             /**< FTM0 Channel 4 and 5 interrupt */
    IRQn_FTM0_Ch6_Ch7            = 102u,             /**< FTM0 Channel 6 and 7 interrupt */
    IRQn_FTM0_Fault              = 103u,             /**< FTM0 Fault interrupt */
    IRQn_FTM0_Ovf_Reload         = 104u,             /**< FTM0 Counter overflow and Reload interrupt */
    IRQn_FTM1_Ch0_Ch1            = 105u,             /**< FTM1 Channel 0 and 1 interrupt */
    IRQn_FTM1_Ch2_Ch3            = 106u,             /**< FTM1 Channel 2 and 3 interrupt */
    IRQn_FTM1_Ch4_Ch5            = 107u,             /**< FTM1 Channel 4 and 5 interrupt */
    IRQn_FTM1_Ch6_Ch7            = 108u,             /**< FTM1 Channel 6 and 7 interrupt */
    IRQn_FTM1_Fault              = 109u,             /**< FTM1 Fault interrupt */
    IRQn_FTM1_Ovf_Reload         = 110u,             /**< FTM1 Counter overflow and Reload interrupt */
    IRQn_FTM2_Ch0_Ch1            = 111u,             /**< FTM2 Channel 0 and 1 interrupt */
    IRQn_FTM2_Ch2_Ch3            = 112u,             /**< FTM2 Channel 2 and 3 interrupt */
    IRQn_FTM2_Ch4_Ch5            = 113u,             /**< FTM2 Channel 4 and 5 interrupt */
    IRQn_FTM2_Ch6_Ch7            = 114u,             /**< FTM2 Channel 6 and 7 interrupt */
    IRQn_FTM2_Fault              = 115u,             /**< FTM2 Fault interrupt */
    IRQn_FTM2_Ovf_Reload         = 116u,             /**< FTM2 Counter overflow and Reload interrupt */
    IRQn_FTM3_Ch0_Ch1            = 117u,             /**< FTM3 Channel 0 and 1 interrupt */
    IRQn_FTM3_Ch2_Ch3            = 118u,             /**< FTM3 Channel 2 and 3 interrupt */
    IRQn_FTM3_Ch4_Ch5            = 119u,             /**< FTM3 Channel 4 and 5 interrupt */
    IRQn_FTM3_Ch6_Ch7            = 120u,             /**< FTM3 Channel 6 and 7 interrupt */
    IRQn_FTM3_Fault              = 121u,             /**< FTM3 Fault interrupt */
    IRQn_FTM3_Ovf_Reload         = 122u              /**< FTM3 Counter overflow and Reload interrupt */
} IRQn_t;

#define NVIC_PRIO_BITS            (4U)

void nvic_enable_interrupt(IRQn_t irq_id);
void nvic_disable_interrupt(IRQn_t irq_id);
void nvic_set_priority(IRQn_t irq_id, uint8_t priority);
void nvic_clear_pending(IRQn_t irq_id);
void nvic_set_pending(IRQn_t irq_id);

#endif //! #ifndef __CORTEX_M4_NVIC_H__
