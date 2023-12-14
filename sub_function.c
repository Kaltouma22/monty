#include "monty.h"

/**
 * func_subt_nodes - The function adds the two top elements of the stack.
 * @subtrac: Pointer to a pointer pointing to top node of the stack.
 * @num: Interger representing the line number of of the opcode.
 */

void func_subt_nodes(stack__t **subtrac, unsigned int num)
{
	int totl;

	if (subtrac == NULL || *subtrac == NULL || (*subtrac)->next == NULL)
		err1(8, num, "sub");

	(*subtrac) = (*subtrac)->next;
	totl = (*subtrac)->n - (*subtrac)->prev->n;
	(*subtrac)->n = totl;
	free((*subtrac)->prev);
	(*subtrac)->prev = NULL;
}
