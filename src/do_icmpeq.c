

#include "../include/ops_task3.h"

void do_icmpeq(program_code *code, stack *s)
{
const two_elements top2 = stack_pop2(s);
  if (top2.first == top2.second){
    op_goto(code);
  }else{
    code->program_counter += sizeof(byte_t) + sizeof(int16_t);
  }
}
