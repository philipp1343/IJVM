
#include "../include/interpret_.ijvm.h"
#include "../include/ops_task3.h"
void do_iflt(program_code *code, stack *s)
{
  bool ok = true;
  const word_t value = stack_pop(s, &ok);
  if (value < 0){
    op_goto(code);
  }else{
    code->program_counter += sizeof(byte_t) + sizeof(int16_t);
  }

}
