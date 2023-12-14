#include "monty.h"

/**
 * add_func - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: num of the line
 * 
*/
void add_func(stack__t **stack, unsigned int line_number)
{
    int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err1(8, line_number, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_func - subtract the top two elements of the stack
 * @line_number: line's number
 * @stack: ptr to the strack
*/
void sub_func(stack__t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err1(8, line_number, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_func - divise the top to elements of the stack
 * @stack: ptr to the stack
 * @ln_num: line number
*/
void div_func(stack__t **stack, unsigned int ln_num)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err1(8, ln_num, "div");

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_func - multiple the top to elements of the stack
 * @ln_num: line number
 * @stack: ptr to the stack
*/
void mul_func(stack__t **stack, unsigned int ln_num)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err1(8, ln_num, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modulo_func - calculates the modulo of the top two elements of the stack
 * @ln_num: line number
 * @stack: ptr to the stack
*/
void modulo_func(stack__t **stack, unsigned int ln_num)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err1(8, ln_num, "mul");

	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
