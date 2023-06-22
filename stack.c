#include "monty.h"
#include <string.h>
void free_stack(stack_t  **stack);
int check_mode(stack_t  **stack);
int init_stack(stack_t  **stack);
/**
 * free_stack - clears stack and sets memory free
 * @stack: pointer to thetop of the stack
 */
void free_stack(stack_t  **stack)
{
	stack_t temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
/**
 * init_stack - creates a new stack that end in queue nodes
 * @stack: pointer to the to be new stack
 * Return: exit success or exit failure
 */
int init_stack(stack_t  **stack)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (malloc_err());
	new->n = STACK;
	new->prev = NULL;
	new->next = NULL;

	*stack = new;

	return (EXIT_SUCCESS);
}
/**
 * check_mode - checks if stack or queue
 * @stack: ponter to the top a stack or tail of queue
 * Return: 1 if queue or 0 if stack else 2
 */
int check_mode(stack_t  **stack)
{
	if (stack->n == QUEUE)
		return (QUEUE);
	else if (stack-> == STACK)
		return (STACK);
	return (2);
}
