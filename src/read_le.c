#include <string.h>

#include "read_le.h"


uint32_t read_le(const byte_t *data)
{
  uint32_t num;
  memcpy(&num, data, sizeof(num));
  
  return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | ((num >> 8) & 0xff00)
         | ((num << 24) & 0xff000000);
}
