#ifndef _SIMPLE_MACROS_ERROR_H_
#define _SIMPLE_MACROS_ERROR_H_

#include "types/error.h"

#define SIMPLE_MACROS_ERROR_HEADING_CSTRING "ERROR: "
#define SIMPLE_MACROS_ERROR_INFO_CSTRING " [line %u, in file '%s']"
#define SIMPLE_MACROS_ERROR_CSTRING(mp_message) SIMPLE_MACROS_ERROR_HEADING_CSTRING (mp_message) SIMPLE_MACROS_ERROR_INFO_CSTRING

#define SIMPLE_MACROS_ERROR_PRINT_CANT_ALLOCATE_MEMORY(mp_bytes) \
    fprintf(stderr, SIMPLE_MACROS_ERROR_CSTRING("Unable to allocate %zu bytes of memory."), (mp_bytes), __LINE__, __FILE__)

#define SIMPLE_MACROS_ERROR_FAIL_COND_V_STEPS(p_condition, p_return_value, l_steps) \
    if (p_condition){ \
        do { \
            p_steps \
        } while(false); \
        return (p_return_value); \
    }

#define SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(p_condition, p_return_value, p_message) \
    if (p_condition){ \
        fputs(stderr, SIMPLE_MACROS_ERROR_CSTRING(p_message)); \
        return (p_return_value); \
    }


#endif//_SIMPLE_MACROS_ERROR_H_
