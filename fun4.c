#include "monty.h"
void f_queue(stack_t **stack, unsigned int in_line_num);
void f_rotl(stack_t **stack, unsigned int in_line_num);
void f_rotr(stack_t **stack, unsigned int in_line_num);
void f_stack(stack_t **stack, unsigned int in_line_num);

/**
 * f_rotl - rotates the stack to the top
 * @stack: pointer to the top node of the stack
 * in_line_num: in line number
 */
void f_rotl(stack_t **stack, unsigned int in_line_num)
{
	stack_t *tp, *bttm;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	tp = (*stack)->next;
	bttm  = (*stack)->next;
	while (bttm->next != NULL)
		bttm = bttm->next;

	tp->next->prev = *stack;
	(*stack)->next = tp->next;
	bttm->next = tp;
	tp->next = NULL;
	tp->prev = bttm;

	(void)in_line_num;
}
/**
 * f_rotr - rotates the stack to the bottom
 * @stack: pointer to the top node of the stack
 * in_line_num: in line number
 */
void f_rotr(stack_t **stack, unsigned int in_line_num)
{
	stack_t *tp, *bttm;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	tp = (*stack)->next;
	bttm  = (*stack)->next;
	while (bttm->next != NULL)
		bttm = bttm->next;

	bttm->prev->next = NULL;
	(*stack)->next = bttm;
	bttm->prev = *stack;
	bttm->next = tp;
	tp->prev = bttm;

	(void)in_line_num;
}
/**
 * f_stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the top node of the stack
 * in_line_num: in line number
 */
void f_stack(stack_t **stack, unsigned int in_line_num)
{
	(*stack)->n = STACK;
	(void)in_line_num;
}
/**
 * f_queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the top node of the stack
 * in_line_num: in line number
 */
void f_queue(stack_t **stack, unsigned int in_line_num)
{
        (*stack)->n = QUEUE;
        (void)in_line_num;
}
