#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stddef.h>

#include "ijvm.h"

typedef struct
{
  word_t *words;
  size_t  word_count;
} stack;

stack stack_create(void);

bool stack_push(stack *s, word_t word);

word_t stack_pop(stack *s, bool *ok);

word_t stack_top(stack s, bool *ok);

size_t stack_word_count(stack s);

typedef struct
{
  word_t first;
  word_t second;
  bool   ok;
} two_elements;

two_elements stack_pop2(stack *s);
#endif /* STACK_H */
