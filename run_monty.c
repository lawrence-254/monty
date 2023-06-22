#include "monty.h"
#include <string.h>

/**
 * free_tkn - clears global token array
 */
void free_tkn(void)
{
	size_t i = 0;
	
	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}
/**
 * get_tok_arr_len - calculates the length of oop global token
 * Return: length of token
 */
unsigned int get_tok_arr_len(void)
{
	unsigned int arr_len = 0;

	while (op_toks[arr_len])
		arr_len++;
	return (arr_len);
}
/**
 * is_line_mty - checks for delimiters from the read line
 * @line: pointer to the line
 * @delims: delimiters
 * Return: 0 if not found, 1 if found
 */
int is_line_mty(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] =='\0')
			return (0);
	}
	return (1);
}
/**
 * get_op_func - matches a function with corresponding call
 * @opcode: code to match to function
 * Return: pointer to function corresponding to opcode called
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruct_t op_funcs[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mod", f_mod},
		{"mul", f_mul},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"stack", f_stack},
		{"queue", f_queue},
		{NULL, NULL}};
	int i;
	
	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}
/**
 * run_monty - starts monty and loops through the code to execute tasks
 * @file_fd: file descriptor
 * Return: exit failure or exit success
 */
int run_monty(FILE *file_fd)
{
	char *line = NULL;
	stack_t *stack = NULL;
	void (*op_func)(stack_t**, unsigned int);
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int in_line_num = 0, prev_tok_len = 0;
	
	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, file_fd) != -1)
	{
		in_line_num++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (id_line_mty(line,DELIMS))
				continue;

