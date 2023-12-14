#include "monty.h"

/**
 * remove_top - This func adds a node to the stack.
 * @rmv: The pointer to a pointer pointing to top node of the stack.
 * @ln_num: The int representing the line number of the opcode.
 */

void remove_top(stack_t **rmv, unsigned int ln_num)
{
	stack_t *tmp;

	if (rmv == NULL || *rmv == NULL)
		more_err(7, ln_num);

	tmp = *rmv;
	*rmv = tmp->next;
	if (*rmv != NULL)
		(*rmv)->prev = NULL;
	free(tmp);
}
