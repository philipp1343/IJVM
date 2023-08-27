#include "../include/ops_task2.h"

void op_isub(stack *s)
{
  const two_elements top_two = stack_pop2(s);
  const word_t answer = top_two.second - top_two.first;
  stack_push(s, answer);
}
