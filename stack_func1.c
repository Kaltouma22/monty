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
