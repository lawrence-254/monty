#include "monty.h"
void f_push(stack_t **stack, unsigned int in_line_num);
void f_pall(stack_t **stack, unsigned int in_line_num);
void f_pint(stack_t **stack, unsigned int in_line_num);
void f_pop(stack_t **stack, unsigned int in_line_num);
void f_swap(stack_t **stack, unsigned int in_line_num);
/**
 * f_push -  pushes an element to the stack
 * @stack: head of stack
 * @in_line_num: tracks size of stack
 * Return: void
 */
void f_push(stack_t **stack, unsigned int in_line_num)
{
	stack_t *n_node;
	
	n_node = (stack_t*)malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		set_op_tok_error(char_err(in_line_num,
					"Memory allocation failed\n"));
		return;
	}
	n_node->n = in_line_num;
	n_node->prev = NULL;

	if (*stack == NULL)
	{
		n_node->next = NULL;
		*stack = n_node;
	}
	else
	{
		n_node->next = *stack;
		(*stack)->prev = n_node;
		*stack = n_node;
	}
	printf("Element %d pushed to stack\n", in_line_num);
}
/**
 * f_pall -  prints all the values on the stack, starting from the top of the stack
 * @stack: head of stack
 * @in_line_num: tracks size of stack
 * Return: void
 */
void f_pall(stack_t **stack, unsigned int in_line_num)
{
	stack_t *current = *stack;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)in_line_num;
}
/**
 * f_pint - prints the value at the top of the stack, followed by a new line
 * @stack: head of stack
 * @in_line_num: tracks size of stack
 * Return: void
 */
void f_pint(stack_t **stack, unsigned int in_line_num)
{
	if (*stack == NULL)
	{
		set_op_tok_error(char_err(in_line_num,"Stack is empty\n"));
		return;
	}
	printf("%d\n", (*stack)->n);
}
/**
 * f_pop - removes the top element of the stack
 * @stack: head of stack
 * @in_line_num: tracks size of stack
 * Return: void
 */
void f_pop(stack_t **stack, unsigned int in_line_num)
{
	stack_t *temp;
	if (*stack == NULL)
	{
		set_op_tok_error(char_err(in_line_num,"Stack is empty\n"));
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	printf("Element popped from stack\n");
}
/**
 * f_swap - swaps the top two elements of the stack.
 * @stack: head of stack
 * @in_line_num: tracks size of stack
 * Return: void
 */
void f_swap(stack_t **stack, unsigned int in_line_num)
{
	stack_t *top = *stack, *second = top->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		set_op_tok_error(char_err(in_line_num,
					"can't swap, stack too short\n"));
		return;
	}
	top->prev = second;
	top->next = second->next;
	second->prev = NULL;
	second->next = top;

	if (top->next != NULL)
		top->next->prev = top;

	*stack = second;

	printf("Swapped the top two elements of the stack\n");
}
