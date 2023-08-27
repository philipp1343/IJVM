#ifndef READ_16_H
#define READ_16_H
#include <stdbool.h>
#include <stdint.h>

#include "program_code.h"

uint16_t read_u16(program_code code, bool *ok);

#endif /* READ_16_H */
