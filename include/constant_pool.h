#ifndef CONSTANT_POOL_H
#define CONSTANT_POOL_H
#include <stddef.h>
#include <stdint.h>

#include "ijvm.h"


typedef struct
{
  uint32_t word_count;
  word_t *constants; 
} constant_pool;


constant_pool constant_pool_create(const byte_t *data, size_t byte_count);

#endif /* CONSTANT_POOL_H */
