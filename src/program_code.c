#include <stdlib.h>
#include <string.h>

#include "ijvm.h"
#include "program_code.h"
#include "read_le.h"
#include "consume.h"



program_code program_code_create(const byte_t *data, size_t byte_count)
{

  consume(&data, &byte_count);
  const uint32_t bytes = read_le(data);
  consume(&data, &byte_count);

  byte_t *text = malloc(bytes);

  memcpy(text, data, bytes);
  return (program_code){text, bytes, 0};
}


