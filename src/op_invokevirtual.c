#include "../include/ops_task5.h"
#include "copy_u16_as_le_from.h"
#include "frame.h"
#include "ijvm.h"
#include "stack.h"
#include "read_16.h"

static bool
copy_arguments(stack *source, uint16_t argument_count, frame *destination)
{
  bool ok = false;

 
  for (uint16_t i = 0; i < argument_count; ++i)
  {
    const word_t argument = stack_pop(source, &ok);

   
    const size_t index = ((size_t)argument_count - (size_t)1) - (size_t)i;
    destination->local_variables[index] = argument;
  }

  return true;
}

void op_invokevirtual(
  constant_pool pool,
  program_code *code,
  frames *      fs)
{

 bool          ok                     = false;
  const uint16_t disp = read_u16(*code, &ok);

  const word_t  method_address         = pool.constants[disp];
  const byte_t *argument_count_address = code->text + method_address;
 
  const uint16_t argument_count = copy_u16_as_le_from(
    argument_count_address, code->byte_count - method_address, &ok);

  const byte_t *local_variable_area_size_address
    = argument_count_address + sizeof(argument_count);
  
  uint16_t local_variable_area_size = copy_u16_as_le_from(
    local_variable_area_size_address,
    code->byte_count - (method_address + sizeof(argument_count)),
    &ok);

 
  local_variable_area_size += argument_count;

  
  const int64_t return_address
    = code->program_counter + sizeof(byte_t) + sizeof(disp);

  frame method_frame = frame_create(return_address, local_variable_area_size);
  ok                 = true;

  ok = copy_arguments(&fs->top->the_stack, argument_count, &method_frame);


  ok = frames_push(fs, method_frame);

  code->program_counter
    = method_address
      + (sizeof(argument_count) + sizeof(local_variable_area_size));

}
