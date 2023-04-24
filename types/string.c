#include "string.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "error.h"
#include "macros/error.h"

struct simple_types_string_t {
    size_t ref_count;
    char* data;
    size_t size;
    size_t capacity;
};

simple_types_error_t simple_types_string_create(simple_types_string_t** m_string) {
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(m_string == NULL, SIMPLE_FAIL_INVALID_ARGUMENTS, "Unexpected NULL as the 1st argument.");
    simple_types_string_t* new_string = (simple_types_string_t*)calloc(1, sizeof(simple_types_string_t));
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(new_string == NULL, SIMPLE_FAIL_CANT_ALLOCATE_MEMORY, "Unable to create string.");
    new_string->ref_count = 1;
    *m_string = new_string;
    return SIMPLE_OK;
}

inline simple_types_error_t simple_types_string_retain(simple_types_string_t* m_string) {
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(m_string == NULL, SIMPLE_FAIL_INVALID_ARGUMENTS, "Unexpected NULL as the 1st argument.");
    m_string->ref_count++;
    return SIMPLE_OK;
}

static simple_types_error_t simple_types_string_destroy(simple_types_string_t* m_string) {
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(m_string == NULL, SIMPLE_FAIL_INVALID_ARGUMENTS, "Unexpected NULL as the 1st argument.");
    if(m_string->capacity != 0) free(m_string->data);
    free(m_string);
    return SIMPLE_OK;
}

inline simple_types_error_t simple_types_string_release(simple_types_string_t* m_string) {
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(m_string == NULL, SIMPLE_FAIL_INVALID_ARGUMENTS, "Unexpected NULL as the 1st argument.");
    if(--m_string->ref_count == 0) {
        simple_types_error_t error = simple_types_string_destroy(m_string);
        SIMPLE_MACROS_ERROR_THROW_COND_V(error != SIMPLE_OK, error);
    }
    return SIMPLE_OK;
}

simple_types_error_t simple_types_string_copy(simple_types_string_t* m_dest, const simple_types_string_t* p_source) {
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(
        m_dest == NULL || p_source == NULL, 
        SIMPLE_FAIL_INVALID_ARGUMENTS, 
        "Unexpected NULL as the 1st argument."
    );

    simple_types_error_t error = SIMPLE_OK;
    error = simple_types_string_reserve(m_dest, p_source->capacity);
    SIMPLE_MACROS_ERROR_THROW_COND_V(error != SIMPLE_OK, error);

    memcpy(m_dest->data, p_source->data, p_source->capacity * sizeof(char));
    m_dest->size = p_source->size;
    return SIMPLE_OK;
}

simple_types_error_t simple_types_string_append_char(simple_types_string_t* m_string, char p_character) {
    SIMPLE_MACROS_ERROR_FAIL_COND_V_MSG(
        m_string == NULL, 
        SIMPLE_FAIL_INVALID_ARGUMENTS, 
        "Unexpected NULL as the 1st argument."
    );

    simple_types_error_t error = SIMPLE_OK;
    error = simple_types_string_reserve(m_string, m_string->size + 1);
    SIMPLE_MACROS_ERROR_THROW_COND_V(error != SIMPLE_OK, error);

    m_string->data[m_string->size] = p_character;
    m_string->size += 1;
    
    return SIMPLE_OK;
}
