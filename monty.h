#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define QUEUE 1
#define STACK 0
#define DELIMS " \n\t\a\b"

/**
 * GLOBAL TOKEN
 */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**err1.c
 */
int use_err(void);
int malloc_err(void);
int fopen_err(char *filename);
int instr_err(char *opcode, unsigned int err_line);
int push_arg_err(unsigned int err_line);
/**
 * err2.c
 */
int pop_err(unsigned int err_line);
int show_empty_err(unsigned int err_line);
int math_stack_err(unsigned int err_line, char *cm);
int div_err(unsigned int err_line);
int char_err(unsigned int err_line, char *m);
/**
 * fun1.c
 */
void f_push(stack_t **stack, unsigned int in_line_num);
void f_pall(stack_t **stack, unsigned int in_line_num);
void f_pint(stack_t **stack, unsigned int in_line_num);
void f_pop(stack_t **stack, unsigned int in_line_num);
void f_swap(stack_t **stack, unsigned int in_line_num);
/**
 * fun2.c
 */
void f_add(stack_t **stack, unsigned int in_line_num);
void f_sub(stack_t **stack, unsigned int in_line_num);
void f_mul(stack_t **stack, unsigned int in_line_num);
void f_div(stack_t **stack, unsigned int in_line_num);
void f_mod(stack_t **stack, unsigned int in_line_num);
/**
 * fun3.c
 */
void f_nop(stack_t **stack, unsigned int in_line_num);
void f_pchar(stack_t **stack, unsigned int in_line_num);
void f_pstr(stack_t **stack, unsigned int in_line_num);
/**
 * fun4.c
 */
void f_queue(stack_t **stack, unsigned int in_line_num);
void f_rotl(stack_t **stack, unsigned int in_line_num);
void f_rotr(stack_t **stack, unsigned int in_line_num);
void f_stack(stack_t **stack, unsigned int in_line_num);
/**
 * run_monty.c
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *file_fd);
void free_tkn(void);
unsigned int get_tok_arr_len(void);
int is_line_mty(char *line, char *delims);
/**
 * set_op_tok_error
 */
void set_op_tok_error(int error_code);
/**
 * stack.c
 */
void free_stack(stack_t  **stack);
int check_mode(stack_t  **stack);
int init_stack(stack_t  **stack);
/**
 * strfun2.c
 */
int is_delim(char ch, char *delims);
char **strtow(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
int get_word_length(char *str, char *delims);
/**
 * str_fun.c
 */
void num_base_mem(unsigned int num, unsigned int base, char *mem, int mem_sze);
char *get_int(int num);
unsigned int _abs(int i);
int num_base_len(unsigned int num, unsigned int base);
#endif
