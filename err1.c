#include "monty.h"
int use_err(void);
int malloc_err(void);
int fopen_err(char *filename);
int instr_err(char *opcode, unsigned int err_line);
int push_arg_err(unsigned int err_line);

/**
 * use_err - prints errors arising from usage
 * Return: always exits the prog
 */
int use_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * malloc_err - prints memory allocation error messages
 * Return: always exits the prog
 */
int malloc_err(void)
{
	fprintf(stderr, "Error: mem allocation failed\n");
	return (EXIT_FAILURE);
}
/**
 * fopen_err - prints errors that arise from opening a file
 * @filename: the file in question
 * Return: always exits the prog
 */
int fopen_err(char *filename)
{
	fprintf(stderr, "Error: file cannot be opened\n");
	return (EXIT_FAILURE);
}
/**
 * instr_err - prints error from unregistered instruction
 * @opcode: loction of the code giving ou errors
 * @err_line: the line of the error
 * Return: always 1
 */
int instr_err(char *opcode, unsigned int err_line)
{
	fprintf(stderr, "L%u: unidentified command %s\n", err_line, opcode);
	return (EXIT_FAILURE);
}
/**
 * push_arg_err - prints invalid push error messages
 * @err_line: the line of the error
 * Return: always exit 1
 */
int push_arg_err(unsigned int err_line)
{
	fprintf(stderr, "L%u: usage: push command invalid\n", err_line);
	return (EXIT_FAILURE);
}
