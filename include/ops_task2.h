#ifndef OPS_TASK2
#define OPS_TASK2
#include <stdio.h>
#include "stack.h"
#include "program_code.h"
#include <stdbool.h>
void op_dup(stack *s);
void do_bipush(program_code *code, stack *s);
void op_iadd(stack *s);
void op_iand(stack *s);
void op_ior(stack *s);
void op_isub(stack *s);
void op_swap(stack *s);
void op_out(stack *s, FILE *out);
void do_in(program_code *code, stack *s, FILE *input_stream);
#endif
