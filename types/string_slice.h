#ifndef _SIMPLE_STRING_SLICE_H_
#define _SIMPLE_STRING_SLICE_H_

#include <stdlib.h>

/* a marking to a string. */
typedef struct simple_string_slice_t {
    const char* begin;
    size_t length;
} simple_string_slice_t;

#endif//_SIMPLE_STRING_SLICE_H_
