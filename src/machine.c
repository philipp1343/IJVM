#include <stdio.h>  // for getc, printf
#include <stdlib.h> // malloc, free
#include "ijvm.h"
#include "util.h" // read this file for debug prints, endianness helper functions
#include "constant_pool.h"
#include "file.h"
#include "frames.h"
#include "program_code.h"
#include "../include/ops_task2.h"
#include "../include/ops_task3.h"
#include "../include/ops_task4.h"
#include "../include/ops_task5.h"
#include "../include/interpret_.ijvm.h"
#include "read_le.h"

// see ijvm.h for descriptions of the below functions
static frames        the_frames;
static constant_pool pool;
static program_code  code;
FILE *in;   // use fgetc(in) to get a character from in.
            // This will return EOF if no char is available.
FILE *out;  // use for example fprintf(out, "%c", value); to print value to out

void set_input(FILE *fp) 
{ 
  in = fp; 
}

void set_output(FILE *fp) 
{ 
  out = fp; 
}

#define SUCCESS 0
#define FAILURE -1

static frame *top_frame(void)
{
  
  return the_frames.top;
}

static stack *top_stack(void)
{
  return &top_frame()->the_stack;
}

word_t *get_stack(void)
{
  return top_stack()->words;
}

int stack_size(void)
{
  return stack_word_count(*top_stack());
}

int init_ijvm(char *binary_path) 
{
  file the_file = file_create(binary_path);

  const uint32_t magicNumber = read_le(the_file.data);

  if(!(magicNumber == MAGIC_NUMBER)){
  return FAILURE;
  }

  byte_t *data       = the_file.data;
  size_t  byte_count = the_file.byte_count;

  // Skip over magic number
  data += sizeof(uint32_t);
  byte_count -= sizeof(uint32_t);
  pool = constant_pool_create(data, byte_count);

  
  // Skip over constant pool
  data += 2 * sizeof(uint32_t);
  byte_count -= 2 * sizeof(uint32_t);
  data += pool.word_count * sizeof(word_t);
  byte_count -= pool.word_count * sizeof(word_t);

  code = program_code_create(data, byte_count);


  // Skip over the program code
  data += 2 * sizeof(uint32_t);
  byte_count -= 2 * sizeof(uint32_t);
  data += code.byte_count;
  byte_count -= code.byte_count;


  free(the_file.data);
  set_input(stdin);
  set_output(stdout);
  the_frames = (frames){NULL};

  frame main_frame = frame_create(DUMMY_RETURN_ADDRESS, 0);

  frames_push(&the_frames, main_frame);
  
  return SUCCESS;
}

void destroy_ijvm(void) 
{
  frames_destroy(the_frames);
  free(code.text);
  free(pool.constants);
}

byte_t *get_text(void) 
{
  return code.text;
}

unsigned int get_text_size(void) 
{
  return (int)code.byte_count;
}

word_t get_constant(int i) 
{
  
  return pool.constants[i];
}

unsigned int get_program_counter(void) 
{
 return (int)code.program_counter;
}

word_t tos(void) 
{
  
  const word_t return_value = get_stack()[stack_size() - 1];
  return return_value;
}

bool finished(void) 
{
 if (get_program_counter() >= get_text_size())
  {
    return true;
  }

  const byte_t instruction = get_instruction();

  if (instruction == OP_ERR)
  {
    fprintf(out, "OP_ERR encountered.\n");
    return true;
  }

  if (instruction == OP_HALT)
  {
    return true;
  }

  return false;
}

word_t get_local_variable(int i) 
{
  bool         ok = false;
  const word_t result
    = frame_read_local_variable(top_frame(), (uint16_t)i, &ok);
  
  return result;
}

void step(void) 
{
  bool temp = true;
  
  if (finished())
  {
    return;
  }

  byte_t instruction = get_instruction();
  bool   is_wide     = false;

  if (instruction == OP_WIDE)
  {
    is_wide = true;
    code.program_counter++;
    instruction = get_instruction();
  }

  switch (instruction)
  {
  case OP_BIPUSH:
     do_bipush(&code, top_stack());
     break;
  case OP_DUP:
    op_dup(top_stack());
    code.program_counter++;
    break;
  case OP_GOTO:
     op_goto(&code);
     break;
  case OP_IADD:
    op_iadd(top_stack());
    code.program_counter++;
    break;
  case OP_IAND:
    op_iand(top_stack());
    code.program_counter++;
    break;
  case OP_IFEQ:
    do_ifeq(&code, top_stack());
    break;
  case OP_IFLT:
    do_iflt(&code, top_stack());
    break;
  case OP_IF_ICMPEQ:
    do_icmpeq(&code, top_stack());
    break;
  case OP_IINC:
     do_iinc(&code, top_frame(), &is_wide);
     break;
  case OP_ILOAD:
     do_iload(&code, top_frame(), top_stack(), &is_wide);
     break;
  case OP_IN:
      do_in(&code, top_stack(), in);
     break;
  case OP_INVOKEVIRTUAL:
     op_invokevirtual(pool, &code, &the_frames);
     break;
  case OP_IOR:
    op_ior(top_stack());
    code.program_counter++;
    break;
  case OP_IRETURN:
    op_ireturn(&code, &the_frames);
    break;
  case OP_ISTORE:
    do_istore(&code, top_frame(), top_stack(), &is_wide);
    break;
  case OP_ISUB:
     op_isub(top_stack());
    code.program_counter++;
    break;
  case OP_LDC_W:
     do_ldc_w(&code, top_stack(), pool);
     break;
  case OP_OUT:
    op_out(top_stack(), out);
    code.program_counter++;
    break;
  case OP_POP:
    stack_pop(top_stack(), &temp);
    code.program_counter++;
    break;
  case OP_SWAP:
    op_swap(top_stack());
    code.program_counter++;
    break;
  default:
    code.program_counter++;
    break;
  }
  
}

void run(void) 
{
  while (!finished()) 
  {
    step();
  }
}

byte_t get_instruction(void) 
{ 
  const int program_counter = get_program_counter();
  return get_text()[program_counter];
}
