#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "constant_pool.h"
#include "consume.h"
#include "read_le.h"



constant_pool constant_pool_create(const byte_t *data, size_t byte_count)
{
  consume(&data, &byte_count);
  const uint32_t bytes = read_le(data);
  consume(&data, &byte_count);

  const uint32_t word_count = bytes / sizeof(word_t);
  word_t *       words      = malloc(sizeof(word_t) * word_count);

  for (uint32_t i = 0; i < word_count; ++i)
  {
    words[i] = read_le(data);
    consume(&data, &byte_count);
  }

  return (constant_pool){word_count, words};
}

