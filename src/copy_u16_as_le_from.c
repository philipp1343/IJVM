#include <string.h>

#include "copy_u16_as_le_from.h"

uint16_t copy_u16_as_le_from(const void *address, size_t byte_count, bool *ok)
{
  uint16_t buffer;
  memcpy(&buffer, address, sizeof(buffer));
  buffer = (buffer >> 8) | (buffer << 8);
  *ok    = true;
  return buffer;
}
