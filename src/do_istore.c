
#include "../include/ops_task4.h"
#include "../include/interpret_.ijvm.h"

void do_istore(program_code *code, frame *f, stack *s, bool *is_wide)
{
  
  code->program_counter++;

  bool           ok              = false;
  const uint16_t lv_index = read_variable_number(*code, *is_wide, &ok);

  if (*is_wide)
  {
    code->program_counter += sizeof(uint16_t);
  }
  else
  {
    code->program_counter++;
  }

  *is_wide = false;
   const word_t word = stack_pop(s,&ok);

  ok = frame_write_local_variable(f, lv_index, word);

}
