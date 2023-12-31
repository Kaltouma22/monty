#include "monty.h"

/**
 * remove_top - This func adds a node to the stack.
 * @rmv: The pointer to a pointer pointing to top node of the stack.
 * @ln_num: The int representing the line number of the opcode.
 */

void remove_top(stack__t **rmv, unsigned int ln_num)
{
	stack__t *tmp;

	if (rmv == NULL || *rmv == NULL)
		err1(7, ln_num);

	tmp = *rmv;
	*rmv = tmp->next;
	if (*rmv != NULL)
		(*rmv)->prev = NULL;
	free(tmp);
}
