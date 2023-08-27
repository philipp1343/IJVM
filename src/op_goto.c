#include "../include/ops_task3.h"

#include "../include/interpret_.ijvm.h"

void op_goto(program_code *code)
{
  
  bool ok = true;
  const int16_t offset = (int16_t)read_u16(*code, &ok);
  const int64_t new_program_counter = code->program_counter + offset;
  code->program_counter = new_program_counter;
  
}