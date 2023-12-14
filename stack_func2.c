#include "monty.h"

/**
 * func_nop - This func Not does anything.
 * @stk: The pointer to a pointer pointing to top node of the stack.
 * @line_num: The int representing the line number of the opcode.
 */

void func_nop(stack_t **stk, unsigned int line_num)
{
	(void)stk;
	(void)line_num;
}

/**
 * func_swap_nd - This function swaps the two top elements of the stack.
 * @swp: Ths pointer to a pointer pointing to top node of the stack.
 * @ln_numb: Interger representing the line number of the opcode.
 */
void func_swap_nd(stack_t **swp, unsigned int ln_numb)
{
	stack_t *t;

	if (swp == NULL || *swp == NULL || (*swp)->next == NULL)
		more_err(8, ln_numb, "swap");
	t = (*swp)->next;
	(*swp)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *swp;
	t->next = *swp;
	(*swp)->prev = t;
	t->prev = NULL;
	*swp = t;
}

/**
 * func_adds_nod - This function adds the two top elements of the stack.
 * @adnod: The pointer to a pointer pointing to top node of the stack.
 * @ln_numb: Interger representing the line number of of the opcode.
 */
void func_adds_nod(stack_t **adnod, unsigned int ln_numb)
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

/**
 * func_subt_nodes - The function adds the two top elements of the stack.
 * @subtrac: Pointer to a pointer pointing to top node of the stack.
 * @num: Interger representing the line number of of the opcode.
 */

void func_subt_nodes(stack_t **subtrac, unsigned int num)
{
	int totl;

	if (subtrac == NULL || *subtrac == NULL || (*subtrac)->next == NULL)
		more_err(8, num, "sub");

	(*subtrac) = (*subtrac)->next;
	totl = (*subtrac)->n - (*subtrac)->prev->n;
	(*subtrac)->n = totl;
	free((*subtrac)->prev);
	(*subtrac)->prev = NULL;
}

/**
 * func_divis_nod - The function adds the two top elements of the stack.
 * @divs: The pointer to a pointer pointing to top node of the stack.
 * @line: The interger representing the line number of the opcode.
 */

void func_divis_nod(stack_t **divs, unsigned int line)
{
	int s;

	if (divs == NULL || *divs == NULL || (*divs)->next == NULL)
		more_err(8, line_number, "div");

	if ((*divs)->n == 0)
		more_err(9, line);
	(*divs) = (*divs)->next;
	s = (*divs)->n / (*divs)->prev->n;
	(*divs)->n = s;
	free((*divs)->prev);
	(*divs)->prev = NULL;
}
