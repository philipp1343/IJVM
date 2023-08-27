#include "../include/ops_task2.h"
void op_out(stack *s, FILE *out)
{
  bool         ok       = false;
  const word_t top_word = stack_pop(s,&ok);

  const char character = (char)top_word;

  fputc(character, out);
  
}
