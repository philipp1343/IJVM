#include"../include/ops_task2.h"


void op_dup(stack *s)
{
  const word_t top_word = s->words[s->word_count - 1];  
  stack_push(s, top_word);
}
