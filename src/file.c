#include <stdio.h>
#include <stdlib.h>

#include "file.h"


file file_create(const char *file_path)
{
  static const char read_binary_mode[] = "rb";
  FILE *            file_handle        = fopen(file_path, read_binary_mode);


  fseek(file_handle, 0, SEEK_END);

  const long byte_count = ftell(file_handle);

   fseek(file_handle, 0, SEEK_SET);

  byte_t *buffer = malloc(byte_count);
 
  fread(buffer, sizeof(byte_t), byte_count, file_handle);


  return (file){buffer, (size_t)byte_count};
}
