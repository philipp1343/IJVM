#include <stdlib.h>

#include "frames.h"



void frames_destroy(frames fs)
{
  while (frames_pop(&fs))
  {
  }
}

bool frames_push(frames *fs, frame f)
{
  frame *new_frame = malloc(sizeof(frame));

  *new_frame          = f;
  new_frame->previous = fs->top;
  fs->top             = new_frame;

  return true;
}

bool frames_pop(frames *fs)
{
  while (fs->top != NULL)
  {
    frame *new_top = fs->top->previous;
    frame_destroy(*(fs->top));
    free(fs->top);
    fs->top = new_top;
    return true;
  }

  return false;
}
