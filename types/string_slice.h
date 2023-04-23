#ifndef _SIMPLE_TYPES_STRING_SLICE_H_
#define _SIMPLE_TYPES_STRING_SLICE_H_

#include <stdlib.h>

/* a marking to a string. */
typedef struct simple_types_string_slice_t {
    const char* begin;
    size_t length;
} simple_types_string_slice_t;

#endif//_SIMPLE_TYPES_STRING_SLICE_H_
