#include "../include/ops_task2.h"
void op_iadd(stack *s)
{
  const two_elements top_two = stack_pop2(s);
  const word_t sum = top_two.first + top_two.second;
  stack_push(s, sum);
}
