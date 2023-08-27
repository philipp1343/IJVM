#ifndef FILE_H
#define FILE_H
#include <stdbool.h>
#include <stddef.h>

#include "ijvm.h"

typedef struct
{
  byte_t *data;       
  size_t  byte_count; 
} file;

file file_create(const char *file_path);

#endif /* FILE_H */
