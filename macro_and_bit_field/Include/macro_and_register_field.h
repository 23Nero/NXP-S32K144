#ifndef __MACRO_AND_REGISTER_FIELD_H__
#define __MACRO_AND_REGISTER_FIELD_H__

#include <stdint.h>

#define set_bit(reg, offset)                        ((reg) |= (1u << (offset)))
#define clear_bit(reg, offset)                      ((reg) &= (~(1u << (offset))))
#define toggle_bit(reg, offset)                     ((reg) ^= (1u << (offset)))

#define get_field(reg, field_width, offset)         (((reg) >> (offset)) &  ((1u << (field_width)) - 1u))
#define set_field(reg, field_width, offset)         ((reg) |= (((1u << (field_width)) - 1) << (offset)))
#define clear_field(reg, field_width, offset)       ((reg) &= (~(((1u << (field_width)) - 1u) << (offset))))
#define set_value(reg, field_width, offset, value)  ((reg) = (((reg) & ~(((1u << (field_width)) - 1u) << (offset))) | ((value) << (offset))))

#endif //!__MACRO_AND_REGISTER_FIELD_H__
