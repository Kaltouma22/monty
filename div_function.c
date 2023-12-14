#include "monty.h"

/**
 * func_divis_nod - The function adds the two top elements of the stack.
 * @divs: The pointer to a pointer pointing to top node of the stack.
 * @line: The interger representing the line number of the opcode.
 */

void func_divis_nod(stack__t **divs, unsigned int line)
{
	int s;

	if (divs == NULL || *divs == NULL || (*divs)->next == NULL)
		more_err(8, line, "div");

	if ((*divs)->n == 0)
		more_err(9, line);
	(*divs) = (*divs)->next;
	s = (*divs)->n / (*divs)->prev->n;
	(*divs)->n = s;
	free((*divs)->prev);
	(*divs)->prev = NULL;
}
