#include "consume.h"

void consume(const byte_t **data, size_t *byte_count)
{
  *data += sizeof(uint32_t);
  *byte_count -= sizeof(uint32_t);
}
