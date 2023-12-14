#include "monty.h"

/**
 * push_to_stack - Thats push a node to the stack.
 * @new: Pointer to the new node.
 * @line: Integer representing the line number of the opcode.
 */

void push_to_stack(stack_t **new, __attribute__((unused))unsigned int line)
{
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	(*new_node)->next = head;
	head->prev = *new_node;
	head = *new_node;
}

/**
 * prt_stack - This funcgtion Prints all elements of the stack.
 * @wrt: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Line number of the opcode.
 */

void prt_stack(stack_t **wrt, unsigned int line_num)
{
	if (wrt == NULL || *wrt == NULL)
		exit(EXIT_FAILURE);

	(void)line_num; // Unused variable

	stack_t *tmp = *wrt;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * remove_top - Removes the top node from the stack.
 * @rmv: Pointer to a pointer pointing to the top node of the stack.
 * @line: Integer representing the line number of the opcode.
 */

void remove_top(stack_t **rmv, unsigned int line)
{
	stack_t *t;

	if (rmv == NULL || *rmv == NULL)
		more_err(7, line);

	t = *rmv;
	*rmv = (*rmv)->next;

	if (*rmv != NULL)
		(*rmv)->prev = NULL;

	free(t);
}

/**
 * prnt_stack_top - Func prints the value of the top node of the stack.
 * @topNode: Pointer to a pointer pointing to the top node of the stack.
 * @op_line_number: Integer representing the line number of the opcode.
 */

void prnt_stack_top(stack_t **topNode, unsigned int op_line_number)
{
	if (topNode == NULL || *topNode == NULL)
		more_err(6, op_line_number);

	printf("Top of stack: %d\n", (*topNode)->n);
}
