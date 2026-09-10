#ifndef STD_H_
#define STD_H_

typedef unsigned char   uint8;   /* 0 .. 255                */
typedef char            int8;    /* -128 .. 127             */
typedef unsigned short  uint16;  /* 0 .. 65535              */
typedef short           int16;   /* -32768 .. 32767         */
typedef unsigned int    uint32;  /* 0 .. 4294967295         */
typedef int             int32;   /* -2^31 .. 2^31-1         */

typedef enum
{
    false = 0,
    true  = 1
} bool;

#endif /* STD_H_ */