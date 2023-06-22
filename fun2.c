#include "monty.h"
void f_add(stack_t **stack, unsigned int in_line_num);
void f_sub(stack_t **stack, unsigned int in_line_num);
void f_mul(stack_t **stack, unsigned int in_line_num);
void f_div(stack_t **stack, unsigned int in_line_num);
void f_mod(stack_t **stack, unsigned int in_line_num);
/**
 * f_add - adds top two val of stack
 * @stack: pointer to the head
 * @in_line_num: working line numbers
 */
void f_add(stack_t **stack, unsigned int in_line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(math_stack_err(in_line_num, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	f_pop(stack, in_line_num);
}
/**
 * f_sub - substracts second value from top val of stack
 * @stack: pointer to the head
 * @in_line_num: working line numbers
 */
void f_sub(stack_t **stack, unsigned int in_line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(math_stack_err(in_line_num, "sub"));
		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	f_pop(stack, in_line_num);
}
/**
 * f_mul - finds product of second value and top val of stack
 * @stack: pointer to the head
 * @in_line_num: working line numbers
 */
void f_mul(stack_t **stack, unsigned int in_line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(math_stack_err(in_line_num, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	f_pop(stack, in_line_num);
}
/**
 * f_div - divides top value by the  second value of stack
 * @stack: pointer to the head
 * @in_line_num: working line numbers
 */
void f_div(stack_t **stack, unsigned int in_line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(math_stack_err(in_line_num, "div"));
		return;
	}
	if ((*stack)->next == 0)
	{
		set_op_tok_error(div_err(in_line_num));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	f_pop(stack, in_line_num);
}
/**
 * f_mod - finds modulus of second value and top val of stack
 * @stack: pointer to the head
 * @in_line_num: working line numbers
 */
void f_mod(stack_t **stack, unsigned int in_line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(math_stack_err(in_line_num, "mod"));
		return;
	}
	if ((*stack)->next == 0)
	{
		set_op_tok_error(div_err(in_line_num));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	f_pop(stack, in_line_num);
}
