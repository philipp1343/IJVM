#include <assert.h>
#include <stdlib.h>

#include "stack.h"

stack stack_create(void)
{
  return (stack){NULL, 0};
}

bool stack_push(stack *s, word_t word)
{
  word_t *new_memory
    = realloc(s->words, (stack_word_count(*s) + 1) * sizeof(word_t));

  new_memory[s->word_count] = word;
  s->words                  = new_memory;
  s->word_count++;
  return true;
}

word_t stack_pop(stack *s, bool *ok)
{
  const word_t return_value = stack_top(*s, ok);

  s->word_count--;
   
  return return_value;
}

word_t stack_top(stack s, bool *ok)
{
 
  const word_t return_value = s.words[stack_word_count(s) - 1];
  *ok                       = true;
  return return_value;
}

size_t stack_word_count(stack s)
{
  return s.word_count;
}

two_elements stack_pop2(stack *s)
{
  bool         ok    = false;
  const word_t first = stack_pop(s, &ok);
  const word_t second = stack_pop(s, &ok);
  return (two_elements){first, second, true};
}
