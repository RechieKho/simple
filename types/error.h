#ifndef _SIMPLE_TYPES_ERROR_H_
#define _SIMPLE_TYPES_ERROR_H_

#include <stdio.h>

typedef enum simple_types_error_t {
    SIMPLE_OK = 0,
    SIMPLE_FAIL_CANT_ALLOCATE_MEMORY,
} simple_types_error_t;

#define SIMPLE_TYPES_ERROR_HEADING_CSTRING "ERROR: "
#define SIMPLE_TYPES_ERROR_INFO_CSTRING " [line %u, in file '%s']"
#define SIMPLE_TYPES_ERROR_CSTRING(mp_message) SIMPLE_TYPES_ERROR_HEADING_CSTRING (mp_message) SIMPLE_TYPES_ERROR_INFO_CSTRING

#define SIMPLE_PRINT_CANT_ALLOCATE_MEMORY(mp_bytes) \
    printf(SIMPLE_TYPES_ERROR_CSTRING("Unable to allocate %zu bytes of memory."), (mp_bytes), __LINE__, __FILE__)

#endif//_SIMPLE_TYPES_ERROR_H_
