#include "monty.h"

/**
 * prt_my_stack - Is adds a node to the stack.
 * @stk: The pointer to a pointer pointing to top node of the stack.
 * @line_num: The line number of  the opcode.
 */

void prt_my_stack(stack_t **stk, unsigned int line_num)
{
	stack_t *t;

	(void) line_num;
	if (stk == NULL)
	exit(EXIT_FAILURE);
	t = *stk;
	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}
