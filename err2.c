#include "monty.h"
int pop_err(unsigned int err_line);
int show_empty_err(unsigned int err_line);
int math_stack_err(unsigned int err_line, char *cm);
int div_err(unsigned int err_line);
int char_err(unsigned int err_line, char *m);
/**
 * pop_err - prints error when you try to pop empty stacks
 * @err_line: the line of error
 * Return: always exit 1
 */
int pop_err(unsigned int err_line)
{
	fprintf(stderr, "L%u: Stack is empty, unable to pop\n", err_line);
	return (EXIT_FAILURE);
}
/**
 * show_empty_err - prints error when empty stacks
 * @err_line: the line of error
 * Return: always exit 1
 */
int show_empty_err(unsigned int err_line)
{
	fprintf(stderr, "L%d: Stack is empty, unable to print\n", err_line);
	return (EXIT_FAILURE);
}
/**
 * math_stack_err - shows math errors for stack/queus smaller than two nodes
 * @err_line: the line of error
 * @cm: command that resulted to error
 * Return: always exit 1
 */
int math_stack_err(unsigned int err_line, char *cm)
{
	fprintf(stderr, "L%u: Unable to %s, short stacks/queues\n",
			err_line, cm);
	return (EXIT_FAILURE);
}
/**
 * div_err - prints error when you try to divide by zero
 * @err_line: the line of error
 * Return: always exit 1
 */
int div_err(unsigned int err_line)
{
	fprintf(stderr, "L%u: unable to divide by zero\n", err_line);
	return (EXIT_FAILURE);
}
/**
 * char_err - show math error for stack/queu where there is invalid character
 * @err_line: the line of error
 * @m: error message to be printed
 * Return: always exit 1
 */
int char_err(unsigned int err_line, char *m)
{
	fprintf(stderr, "L%u: Unable to print char%s\n", err_line, m);
	return (EXIT_FAILURE);
}
