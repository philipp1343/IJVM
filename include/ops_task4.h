#ifndef OPS_TASK4
#define OPS_TASK4

#include "constant_pool.h"
#include "program_code.h"
#include "stack.h"
#include "frame.h"

void do_istore(program_code *code, frame *f, stack *s, bool *is_wide);
void do_iload(program_code *code, frame *f, stack *s, bool *is_wide);
void do_iinc(program_code *code, frame *f, bool *is_wide);
void do_ldc_w(program_code *code, stack *s, constant_pool pool);

#endif
