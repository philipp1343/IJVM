
#include "../include/interpret_.ijvm.h"
#include "../include/ops_task4.h"
void do_iinc(program_code *code, frame *f, bool *is_wide)
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
  *is_wide              = false;
  const byte_t constant = code->text[code->program_counter];
  word_t variable = frame_read_local_variable(f, lv_index, &ok);
  variable += (int8_t)constant;
  ok = frame_write_local_variable(f, lv_index, variable);
  code->program_counter++;
}
