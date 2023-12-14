#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack__t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* file operations */
void handle_file(char *file_name); /*Done*/
int parse_line(char *buffer, int line_number, int format);/*Done*/
int len_chars(FILE *);/*Not yet*/
void find_fct(char *, char *, int, int);/*Done*/
void call_fct(op_func, char *, char *, int, int);/*Done*/

/*operations*/
void mul_func(stack__t **stack, unsigned int ln_num); /*done*/
void modulo_func(stack__t **stack, unsigned int ln_num); /*done*/

/* All Stack operations Kaltoum */
void push_to_stack(stack__t **, unsigned int); /* K done */
void prt_my_stack(stack__t **, unsigned int); /* k done */
void remove_top(stack__t **, unsigned int); /* k done */
void func_prnt_top(stack__t **, unsigned int); /* k done */

void func_nop(stack__t **, unsigned int); /* k done */
void func_swap_nd(stack__t **, unsigned int); /* k done */
void func_adds_nod(stack__t **, unsigned int); /* k done */
void func_subt_nod(stack__t **, unsigned int); /* k done */
void func_divis_nod(stack__t **, unsigned int); /* k done */

/* wait */
stack_t *create_node(int n);/*Kaltoum*/
void free_nodes(void);/*Kaltoum*/
void add_to_queue(stack__t **, unsigned int);/*Kaltoum*/

/*String operations*/
void print_char(stack__t **, unsigned int);
void print_str(stack__t **);
void rot(stack__t **);

/*Error hanlding*/
void err(int error_code, ...);
void err1(int error_code, ...);
void err2(int error_code, ...);
void rot1(stack__t **);

#endif
