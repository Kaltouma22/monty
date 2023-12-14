#include "monty.h"

/**
 * func_swap_nd - This function swaps the two top elements of the stack.
 * @swp: Ths pointer to a pointer pointing to top node of the stack.
 * @ln_numb: Interger representing the line number of the opcode.
 */

void func_swap_nd(stack__t **swp, unsigned int ln_numb)
{
	stack__t *t;

	if (swp == NULL || *swp == NULL || (*swp)->next == NULL)
		err1(8, ln_numb, "swap");
	t = (*swp)->next;
	(*swp)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *swp;
	t->next = *swp;
	(*swp)->prev = t;
	t->prev = NULL;
	*swp = t;
}
