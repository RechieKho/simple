#ifndef _SIMPLE_MACROS_ERROR_H_
#define _SIMPLE_MACROS_ERROR_H_

#include "types/error.h"

#define SIMPLE_MACROS_ERROR_HEADING_CSTRING "ERROR: "
#define SIMPLE_MACROS_ERROR_INFO_CSTRING " [line %u, in file '%s']"
#define SIMPLE_MACROS_ERROR_CSTRING(p_message) \
    (SIMPLE_MACROS_ERROR_HEADING_CSTRING p_message SIMPLE_MACROS_ERROR_INFO_CSTRING)

#define SIMPLE_MACROS_ERROR_PRINTF(p_message, ...) \
    fprintf(stderr, SIMPLE_MACROS_ERROR_CSTRING(p_message), __VA_ARGS__, __LINE__, __FILE__)

#define SIMPLE_MACROS_ERROR_PRINT(p_message) \
    fprintf(stderr, SIMPLE_MACROS_ERROR_CSTRING(p_message), __LINE__, __FILE__)

#define SIMPLE_MACROS_ERROR_FAIL_COND_V_STEPS(p_condition, p_return_value, l_steps) \
    if (p_condition){ \
        do { \
            p_steps \
        } while(false); \
        return (p_return_value); \
    }

#define SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(p_condition, p_return_value, p_message) \
    if (p_condition){ \
        SIMPLE_MACROS_ERROR_PRINT(p_message); \
        return (p_return_value); \
    }

#define SIMPLE_MACROS_ERROR_FAIL_COND_V_MSGF(p_condition, p_return_value, p_message, ...) \
    if (p_condition){ \
        SIMPLE_MACROS_ERROR_PRINTF(p_message, __VA_ARGS__); \
        return (p_return_value); \
    }

#define SIMPLE_MACROS_ERROR_FAIL_COND_MSG(p_condition, p_message) \
    if (p_condition){ \
        SIMPLE_MACROS_ERROR_PRINT(p_message); \
        return; \
    }

#define SIMPLE_MACROS_ERROR_FAIL_COND_MSGF(p_condition, p_message, ...) \
    if (p_condition){ \
        SIMPLE_MACROS_ERROR_PRINTF(p_message, __VA_ARGS__); \
        return; \
    }

#define SIMPLE_MACROS_ERROR_THROW_COND_V(p_condition, p_return_value) \
    if (p_condition){ \
        SIMPLE_MACROS_ERROR_PRINTF("in function '%s'", __func__); \
        return (p_return_value); \
    }

#define SIMPLE_MACROS_ERROR_THROW_COND(p_condition) \
    if (p_condition){ \
        SIMPLE_MACROS_ERROR_PRINTF("in function '%s'", __func__); \
        return; \
    }

#endif//_SIMPLE_MACROS_ERROR_H_
