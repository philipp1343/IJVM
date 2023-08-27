#ifndef INTERPRET_IJVM
#define INTERPRET_IJVM
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "program_code.h"
#include "ijvm.h"


uint16_t read_u16(program_code code, bool *ok);
uint16_t read_variable_number(program_code code, bool is_wide, bool *ok);
#endif
