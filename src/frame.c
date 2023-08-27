#include <stdlib.h>
#include <string.h>

#include "frame.h"
#include "ijvm.h"

frame frame_create(int64_t return_address, size_t local_variable_area_size)
{
  word_t *local_variables = calloc(local_variable_area_size, sizeof(word_t));

  if (local_variables == NULL)
  {
    return (frame){
      stack_create(),
      DUMMY_RETURN_ADDRESS,
      NULL,
      0,
      NULL};
  }

  return (frame){
    stack_create(),
    return_address,
    local_variables,
    local_variable_area_size,
     NULL};
}

void frame_destroy(frame f)
{
  free(f.the_stack.words);
  free(f.local_variables);
}


static bool grow(frame *f, uint16_t index)
{
  const size_t words_needed = (size_t)index + (size_t)1;

  if (f->word_count < words_needed)
  {
    word_t *new_local_variables 
    = realloc(f->local_variables, words_needed * sizeof(word_t));

    const size_t new_words = words_needed - f->word_count;
    memset(new_local_variables + f->word_count, 0, new_words * sizeof(word_t));
    f->local_variables = new_local_variables;
    f->word_count      = words_needed;
    return true;
  }
  
  return true;
}

word_t frame_read_local_variable(frame *f, uint16_t index, bool *ok)
{
  const word_t variable = f->local_variables[index];
  return variable;
}

bool frame_write_local_variable(frame *f, uint16_t index, word_t value)
{
  grow(f, index);

  f->local_variables[index] = value;
  return true;
}
