#include "../include/ops_task4.h"

#include "../include/interpret_.ijvm.h"


void do_iload(program_code *code, frame *f, stack *s, bool *is_wide)
{
 
  code->program_counter++;

  bool           ok              = false;
  const uint16_t variable_number = read_variable_number(*code, *is_wide, &ok);

  if (*is_wide)
  {
    code->program_counter += sizeof(uint16_t);
  }
  else
  {
    code->program_counter++;
  }

  *is_wide = false;
  const word_t variable = frame_read_local_variable(f, variable_number, &ok);
  ok = stack_push(s, variable);
  
}
