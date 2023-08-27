#ifndef FRAME_H
#define FRAME_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "ijvm.h"
#include "stack.h"


typedef struct frame_tag
{
  stack the_stack; 
  int64_t
    return_address; 
  word_t *local_variables; 
  size_t  word_count;      
  struct frame_tag
    *previous; 
} frame;


#define DUMMY_RETURN_ADDRESS INT64_MIN

frame frame_create(int64_t return_address, size_t local_variable_area_size);

void frame_destroy(frame f);

word_t frame_read_local_variable(frame *f, uint16_t index, bool *ok);

bool frame_write_local_variable(frame *f, uint16_t index, word_t value);
#endif /* FRAME_H */
