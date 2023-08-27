#include "read_16.h"

uint16_t read_u16(program_code code, bool *ok)
{
  const int64_t begin = code.program_counter + 1;

  const byte_t high_order_byte = code.text[begin];

  const byte_t low_order_byte = code.text[begin + 1];
  *ok                         = true;
  return (((uint16_t)high_order_byte) << 8) | (uint16_t)low_order_byte;
}


