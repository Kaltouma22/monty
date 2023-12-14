#include "monty.h"

/**
 * push_to_stack - This adds a node to the stack.
 * @new: The pointer to the new node.
 * @line: The int representing the line number of the opcode.
 */

void push_to_stack(stack_t **new, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tmp = head;
	head = *new;
	head->next = tmp;
	tmp->prev = head;
}
