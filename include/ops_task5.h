#ifndef OPS_TASK5
#define OPS_TASK5

#include <stdbool.h>
#include <stdint.h>
#include "constant_pool.h"
#include "frames.h"
#include "program_code.h"

void op_ireturn(program_code *code, frames *fs);
void op_invokevirtual(constant_pool pool, program_code *code, frames *fs);

#endif
