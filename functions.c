#include "monty.h"

/**
 * print_char - prints char
 * @stack: ptr to ptr to stack
 * @ln_num: line number
*/

void print_char(stack__t **stack, unsigned int ln_num)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		err2(11, ln_num);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		err2(10, ln_num);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string.
 * @stack: ptr to ptr to top node of the stack.
 * @ln: line number of of the opcode.
 */
void print_str(stack__t **stack)
{
	int ascii;

	stack__t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rot - Rotates the first node of the stack to the bottom.
 * @stack: ptr to ptr pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot(stack__t **stack)
{
	stack__t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rot1 - Rotates the last node of the stack to the top.
 * @stack: ptr to ptr pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot1(stack__t **stack)
{
	stack__t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack__t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		err1(6, line_number);
	printf("%d\n", (*stack)->n);
}




