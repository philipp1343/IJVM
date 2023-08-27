#include "../include/ops_task2.h"

void op_ior(stack *s)
{
  const two_elements top2 = stack_pop2(s);
  stack_push(s, top2.first | top2.second);
}