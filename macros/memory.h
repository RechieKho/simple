#ifndef _SIMPLE_MEMORY_H_
#define _SIMPLE_MEMORY_H_

#include <stdlib.h>
#include <stdbool.h>

#include "types/error.h"

#define SIMPLE_MEMORY_RESERVE(mp_type, mp_output, mp_current_capacity, mp_min_capacity, mp_error) \
    do { \
        (mp_error) = SIMPLE_OK; \
        size_t new_capacity = (mp_current_capacity); \
        while(new_capacity < (mp_min_capacity)) new_capacity *= 2; \
        const size_t bytes = new_capacity * sizeof(mp_type); \
        if(((mp_output) = (mp_type*)realloc((void*)(mp_output), bytes)) == NULL) { \
            (mp_error) = SIMPLE_ALLOCATE_FAIL; \
            SIMPLE_PRINT_CANT_ALLOCATE_MEMORY(bytes); \
        } \
    } while(false);

#endif//_SIMPLE_MEMORY_H_
