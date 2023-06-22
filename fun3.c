#include "monty.h"
void f_nop(stack_t **stack, unsigned int in_line_num);
void f_pchar(stack_t **stack, unsigned int in_line_num);
void f_pstr(stack_t **stack, unsigned int in_line_num);
/**
 * f_nop - does nothing
 * @stack: pointer to top node of the stack
 * @in_line_num: line number
 */
void f_nop(stack_t **stack, unsigned int in_line_num)
{
	(void)stack;
	(void)in_line_num;
}
/**
 * f_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to top node of the stack
 * @in_line_num: line number
 */
void f_pchar(stack_t **stack, unsigned int in_line_num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(char_err(in_line_num,
					"can't pchar, stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(char_err(in_line_num,
					"can't pchar, value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: pointer to top node of the stack
 * @in_line_num: line number
 */
void f_pstr(stack_t **stack, unsigned int in_line_num)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)in_line_num;
}
