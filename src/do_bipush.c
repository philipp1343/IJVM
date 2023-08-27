#include "../include/ops_task2.h"

void do_bipush(program_code *code, stack *s)
{
  code->program_counter++;
  const byte_t byte = code->text[code->program_counter];
  stack_push(s, (word_t)(int8_t)byte);
  code->program_counter++;
  
}
