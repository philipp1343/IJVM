#ifndef FRAMES_H
#define FRAMES_H
#include "frame.h"

typedef struct
{
  frame *top;
} frames;



void frames_destroy(frames fs);

bool frames_push(frames *fs, frame f);

bool frames_pop(frames *fs);
#endif /* FRAMES_H */
