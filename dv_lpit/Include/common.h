#ifndef __COMMON_H__
#define __COMMON_H__

#ifndef RO
    #define RO const
    #define RW

    #define IO volatile
    #define DM
#endif //! #ifndef RO

#define BIT_SET             0x1u
#define BIT_CLEAR           0x0u

#endif //! __COMMON_H__
