#include <stdint.h>

#include "macro_and_register_field.h"

int main(void)
{
    uint32_t field;
    uint32_t reg = 0x11223344;

    set_bit(reg, (uint32_t)31);
    clear_bit(reg, 24);
    toggle_bit(reg, 31);

    field = get_field(reg, 8, 16);

    clear_field(reg, 8, 16);
    set_field(reg, 3, 29);
    set_value(reg, 8, 16, 0x55);
}
