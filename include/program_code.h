#ifndef PROGRAM_CODE_H
#define PROGRAM_CODE_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "ijvm.h"


typedef struct
{
  byte_t *text;            
  size_t  byte_count;      
  int64_t program_counter; 
} program_code;

program_code program_code_create(const byte_t *data, size_t byte_count);


#endif /* PROGRAM_CODE_H */
