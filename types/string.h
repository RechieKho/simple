#ifndef _SIMPLE_TYPE_STRING_H_
#define _SIMPLE_TYPE_STRING_H_

#include <stdlib.h>

#include "macros/memory.h"
#include "error.h"

/* A reference counted growable string. */
typedef struct simple_types_string_t simple_types_string_t;

/* a marking to a string or a section of a string. */
typedef struct simple_types_string_slice_t {
    const char* begin;
    size_t length;
} simple_types_string_slice_t;

#define SIMPLE_TYPES_STRING_SLICE_MAKE_FROM_CSTRING(p_cstring) \
    (simple_types_string_slice_t){ \
        .begin = (p_cstring), \
        .length = SIMPLE_MACROS_MEMORY_GET_ARRAY_SIZE(p_cstring) \
    }

simple_types_error_t simple_types_string_create(simple_types_string_t** m_string);
simple_types_error_t simple_types_string_retain(simple_types_string_t* m_string); // Increase reference count.
simple_types_error_t simple_types_string_release(simple_types_string_t* m_string); // Decrease reference count (and destroy if necessary).
simple_types_error_t simple_types_string_copy(simple_types_string_t* m_dest, const simple_types_string_t* p_source);
simple_types_error_t simple_types_string_append_char(simple_types_string_t* m_string, char p_character);
simple_types_error_t simple_types_string_reserve(simple_types_string_t* m_string, size_t p_min_capacity); // Pre-allocate memory.
simple_types_error_t simple_types_string_size(const simple_types_string_t* p_string, size_t* m_size);
simple_types_error_t simple_types_string_data(const simple_types_string_t* p_string, const char** m_data);
simple_types_error_t simple_types_string_slice(const simple_types_string_t* p_string, size_t p_start, size_t p_end, simple_types_string_slice_t* m_slice);
simple_types_error_t simple_types_string_append_slice(simple_types_string_t* m_string, simple_types_string_slice_t p_slice);

#endif//_SIMPLE_TYPE_STRING_H_
