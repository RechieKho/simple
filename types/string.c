#include "string.h"

#include <stdlib.h>
#include <stdbool.h>

#include "error.h"
#include "macros/error.h"

struct simple_types_string_t {
    size_t ref_count;
    char* data;
    size_t size;
    size_t capacity;
};

simple_types_error_t simple_types_string_create(simple_types_string_t** m_string) {
    simple_types_string_t* new_string = (simple_types_string_t*)calloc(1, sizeof(simple_types_string_t));
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(new_string == NULL, SIMPLE_FAIL_CANT_ALLOCATE_MEMORY, "Unable to create string.");
    new_string->ref_count = 1;
    *m_string = new_string;
    return SIMPLE_OK;
}
