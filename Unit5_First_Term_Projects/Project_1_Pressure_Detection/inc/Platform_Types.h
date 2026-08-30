/*
 *Name:         Platform_Types.h
 *Author:       Adel Shata
 */


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
/*
#define CPU_TYPE            CPU_TYPE_32
#define CPU_BIT_ORDER       MSB_FIRST
#define CPU_BYTE_ORDER      HIGH_BYTE_FIRST
*/

/*
===================================================
====================INCLUDES=======================
===================================================
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/*
===================================================
====================Defines========================
===================================================
*/

#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FALSE (_Bool)false
#endif

#ifndef TRUE
#define TRUE (_Bool)true
#endif

/*
===================================================
=====================Types=========================
===================================================
*/

typedef _Bool                           boolean;
typedef int8_t                          sint8;
typedef uint8_t                         uint8;
typedef char                            char_t;

typedef int16_t                         sint16;
typedef uint16_t                        uint16;
typedef int32_t                         sint32;
typedef uint32_t                        uint32;
typedef int64_t                         sint64;
typedef uint64_t                        uint64;

typedef float                           float32;
typedef double                          double64;

typedef volatile int8_t                 vint8;
typedef volatile uint8_t                vuint8;
typedef volatile uint16_t               vuint16;
typedef volatile int32_t                vint32;
typedef volatile uint32_t               vuint32;
typedef volatile int64_t                vint64;
typedef volatile uint64_t               vuint64;

typedef volatile float                  vfloat32;
typedef volatile double                 vdouble64;






#endif
