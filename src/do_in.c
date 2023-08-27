#include "../include/ops_task2.h"

void do_in(program_code *code, stack *s, FILE *input_stream)
{
  
  code->program_counter++;

  const int user_input = fgetc(input_stream);

  word_t value_to_push = 0;

  if (user_input != EOF)
  {
    
    value_to_push = user_input;
  }

   stack_push(s, value_to_push);
}
