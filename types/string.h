#ifndef _SIMPLE_TYPE_STRING_H_
#define _SIMPLE_TYPE_STRING_H_

#include <stdlib.h>

#include "error.h"

/* A reference counted growable string. */
typedef struct simple_types_string_t simple_types_string_t;

simple_types_error_t simple_types_string_create(simple_types_string_t** m_string);
simple_types_error_t simple_types_string_retain(simple_types_string_t* m_string); // Increase reference count.
simple_types_error_t simple_types_string_release(simple_types_string_t* m_string); // Decrease reference count (and destroy if necessary).
simple_types_error_t simple_types_string_copy(simple_types_string_t* m_dest, const simple_types_string_t* p_source);
simple_types_error_t simple_types_string_append_char(simple_types_string_t* m_string, char p_character);
simple_types_error_t simple_types_string_reserve(simple_types_string_t* m_string, size_t p_min_size); // Pre-allocate memory.
size_t simple_types_string_size(const simple_types_string_t* p_string);
const char* simple_types_string_data(const simple_types_string_t* p_string);

#endif//_SIMPLE_TYPE_STRING_H_
