#include "type.h"
#include "lib.h"
#include "main.h"

int main (void)
{
    u1 u1a_Verf;
    u1a_Verf = 1u;

    __asm volatile (
        " mov r1, #9 \n\t"
        " mov r0, r1 \n\t"
    );

    f_App_Sum(3u, 5u, &u1a_Verf);

    if (U1G_TEMP_MAX == u1a_Verf)
    {
        while(1u){}
    }

    return 0u;
}