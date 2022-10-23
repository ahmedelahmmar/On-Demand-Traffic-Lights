#ifndef STD_TYPES_H_INCLUDED
#define STD_TYPES_H_INCLUDED

#define NULL					'\0'

typedef unsigned char           uint8_t;
typedef signed char             sint8_t;

typedef unsigned short          uint16__t;
typedef signed short            sint16_t;

typedef unsigned long           uint32_t;
typedef signed long             sint32_t;

typedef unsigned long long      uint64_t;
typedef signed long long        sint64_t;

typedef float                   f32;

typedef double                  f64;

typedef long double             f128;

typedef enum
{
    False,
    True

} bool;

#endif // STD_TYPES_H_INCLUDED
