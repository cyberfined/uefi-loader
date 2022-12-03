#pragma once

typedef unsigned long long size_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long int64_t;
typedef unsigned long uint64_t;
typedef uint16_t char16_t;

typedef unsigned char bool;
#define false 0
#define true 1

typedef struct {} *EfiHandle;

#define NULL (void*)0

typedef struct {
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
    uint8_t  pad1;
    uint32_t nanosecond;
    int16_t timezone;
    uint8_t daylight;
    uint8_t pad2;
} Time;

#define va_start(v,l)     __builtin_va_start(v,l)
#define va_end(v)         __builtin_va_end(v)
#define va_arg(v,l)       __builtin_va_arg(v,l)
#define va_copy(d,s)      __builtin_va_copy(d,s)
typedef __builtin_va_list va_list;
