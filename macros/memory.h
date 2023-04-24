#ifndef _SIMPLE_MACROS_MEMORY_H_
#define _SIMPLE_MACROS_MEMORY_H_

#include <stdlib.h>
#include <stdbool.h>

#include "types/error.h"
#include "error.h"

#define SIMPLE_MACROS_MEMORY_INIT_CAPACITY 10

#define SIMPLE_MACROS_MEMORY_RESERVE(l_type, m_output, p_capacity, p_min_capacity, m_error) \
    do { \
        (m_error) = SIMPLE_OK; \
        size_t new_capacity = (p_capacity == 0)? SIMPLE_MACROS_MEMORY_INIT_CAPACITY : p_capacity; \
        while(new_capacity < (p_min_capacity)) new_capacity *= 2; \
        const size_t bytes = new_capacity * sizeof(l_type); \
        if(((m_output) = (l_type*)realloc((void*)(m_output), bytes)) == NULL) { \
            (m_error) = SIMPLE_FAIL_CANT_ALLOCATE_MEMORY; \
            SIMPLE_MACROS_ERROR_PRINTF("Unable to reserve '%zu' bytes of memory.", bytes); \
        } \
    } while(false);

#endif//_SIMPLE_MACROS_MEMORY_H_
