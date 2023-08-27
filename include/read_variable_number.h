#ifndef READ_VARIABLE_NUMBER_H
#define READ_VARIABLE_NUMBER_H
#include <stdbool.h>
#include <stdint.h>

#include "program_code.h"

uint16_t read_variable_number(program_code code, bool is_wide, bool *ok);
#endif /* READ_VARIABLE_NUMBER_H */
