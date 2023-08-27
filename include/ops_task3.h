#ifndef OPS_TASK3
#define OPS_TASK3
#include <stdbool.h>
#include <stdint.h>
#include "stack.h"
#include "program_code.h"

void op_goto(program_code *code);
void do_ifeq(program_code *code, stack *s);
void do_icmpeq(program_code *code, stack *s);
void do_iflt(program_code *code, stack *s);

#endif
