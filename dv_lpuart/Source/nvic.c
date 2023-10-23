#include <stdint.h>
#include "nvic.h"

void nvic_enable_interrupt(IRQn_t irq_id)
{
    NVIC->ISER[(uint32_t)(irq_id) >> 5u] = (uint32_t)(1UL << ((uint32_t)(irq_id) & (uint32_t)0x1FU));
}

void nvic_disable_interrupt(IRQn_t irq_id)
{
    NVIC->ICER[(uint32_t)(irq_id) >> 5u] = (uint32_t)(1UL << ((uint32_t)(irq_id) & (uint32_t)0x1FU));
}

void nvic_set_priority(IRQn_t irq_id, uint8_t priority)
{
    uint8_t shift = (uint8_t) (8U - NVIC_PRIO_BITS);
    NVIC->IP[(uint32_t)(irq_id)] = (uint8_t)(((((uint32_t)priority) << shift)) & 0xFFUL);
}

void nvic_clear_pending(IRQn_t irq_id)
{
    NVIC->ICPR[(uint32_t)(irq_id) >> 5U] = (uint32_t)(1UL << ((uint32_t)(irq_id) & (uint32_t)0x1FU));
}

void nvic_set_pending(IRQn_t irq_id)
{
    NVIC->ISPR[(uint32_t)(irq_id) >> 5U] = (uint32_t)(1UL << ((uint32_t)(irq_id) & (uint32_t)0x1FU));
}
