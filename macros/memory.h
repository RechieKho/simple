#ifndef _SIMPLE_MACROS_MEMORY_H_
#define _SIMPLE_MACROS_MEMORY_H_

#include <stdlib.h>
#include <stdbool.h>

#include "types/error.h"

#define SIMPLE_MACROS_MEMORY_RESERVE(l_type, m_output, m_capacity, p_min_capacity, m_error) \
    do { \
        (m_error) = SIMPLE_OK; \
        size_t new_capacity = (m_capacity); \
        while(new_capacity < (p_min_capacity)) new_capacity *= 2; \
        const size_t bytes = new_capacity * sizeof(l_type); \
        if(((m_output) = (l_type*)realloc((vol*)(m_output), bytes)) == NULL) { \
            (m_error) = SIMPLE_ALLOCATE_FAIL; \
            (m_capacity) = 0; \
            SIMPLE_PRINT_CANT_ALLOCATE_MACROS_MEMORY(bytes); \
        } \
    } while(false);

#endif//_SIMPLE_MACROS_MEMORY_H_
