#ifndef _SIMPLE_STRING_H_
#define _SIMPLE_STRING_H_

#include <stdlib.h>

#include "error.h"

/* A reference counted growable string. */
typedef struct simple_string_t simple_string_t;

simple_error_t simple_string_create(simple_string_t** m_string);
void simple_string_retain(simple_string_t* m_string); // Increase reference count.
void simple_string_release(simple_string_t* m_string); // Decrease reference count (and destroy if necessary).
void simple_string_copy(simple_string_t** m_dest, const simple_string_t* p_source);
simple_error_t simple_string_append(char p_character);
simple_error_t simple_string_reserve(simple_string_t* m_string, size_t p_min_size); // Pre-allocate memory.
size_t simple_string_size(const simple_string_t* p_string);
const char* simple_string_data(const simple_string_t* p_string);

#endif//_SIMPLE_STRING_H_
