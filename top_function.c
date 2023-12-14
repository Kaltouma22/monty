#include "monty.h"

/**
 * func_prnt_top - This function prints the top node of the stack.
 * @top: The pointer to pointer, pointing to top node of the stack.
 * @line_num: The interger representing the line number of the opcode.
 */

void func_prnt_top(stack_t **top, unsigned int line_num)
{
	if (top == NULL || *top == NULL)
		more_err(6, line_num);

	printf("%d\n", (*top)->n);
}
