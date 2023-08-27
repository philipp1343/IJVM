#include "read_variable_number.h"
#include "copy_u16_as_le_from.h"

uint16_t read_variable_number(program_code code, bool is_wide, bool *ok)
{
  if (is_wide)
  {
    return copy_u16_as_le_from(
      code.text + code.program_counter,
      code.byte_count - code.program_counter,
      ok);
  }

  *ok = true;
  return (uint16_t)code.text[code.program_counter];
}
