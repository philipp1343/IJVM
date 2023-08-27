#include <assert.h>

#include "ijvm.h"
#include "../include/ops_task5.h"
#include "stack.h"

void op_ireturn(program_code *code, frames *fs)
{

  bool ok = false;

  const word_t return_value = stack_pop(&fs->top->the_stack,&ok);

  const int64_t return_address = fs->top->return_address;
  
  ok = frames_pop(fs);

  ok = stack_push(&fs->top->the_stack, return_value);

  code->program_counter = return_address;
}
