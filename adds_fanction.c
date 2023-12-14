#include "monty.h"

/**
 * func_adds_nod - This function adds the two top elements of the stack.
 * @adnod: The pointer to a pointer pointing to top node of the stack.
 * @ln_numb: Interger representing the line number of of the opcode.
 */

void func_adds_nod(stack__t **adnod, unsigned int ln_numb)
{
	int total;

	if (adnod == NULL || *adnod == NULL || (*adnod)->next == NULL)
		more_err(8, ln_numb, "add");

	(*adnod) = (*adnod)->next;
	total = (*adnod)->n + (*adnod)->prev->n;
	(*adnod)->n = total;
	free((*adnod)->prev);
	(*adnod)->prev = NULL;
}
