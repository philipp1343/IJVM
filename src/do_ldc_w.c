#include "../include/ops_task4.h"

#include "../include/interpret_.ijvm.h"


void do_ldc_w(program_code *code, stack *s, constant_pool pool)
{
  bool ok = false;

  const uint16_t index = read_u16(*code, &ok);
  
  const word_t constant = pool.constants[index];
  stack_push(s, constant);

  code->program_counter++;

  code->program_counter += sizeof(index);

}
