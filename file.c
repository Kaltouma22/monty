#include "monty.h"

/**
 * handle_file - open and read the file
 * @file_name: file's name
*/
void handle_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

    int line_number, format = 0;

    char *buffer = NULL;

    size_t len = 0;

	if (file_name == NULL || fd == NULL)
		err(2, file_name);
    for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
	fclose(fd);
}

/**
 * parse_line - Separates each line into tokens to choose which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format: storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack or 1 if queue.
 */
int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;

	const char *delim = "\n ";

	/* if (buffer == NULL) */
	/* 	err(4); */
    /**
     * there is no metter if it, it the buffer is null
     * the for loop in the previous function will not be executed 
     * because of the condition 
     * getline(&buffer, &len, fd) != -1
     */

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_fct(opcode, value, line_number, format);
	return (format);
}

/**
 * find_fct - finds the function to call to execute the command
 * @opcode: operation code
 * @value: argument of opcode
 * @ln: line number
 * @format: storage format, If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
*/
void find_fct(char *opcode, char *value, int ln, int format)
{
	int i, flag;


	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", prt_stack},
		{"pint", print_top},
		{"pop", remove_top},
		{"nop", nop},
		{"swap", sub_nodes},
		{"add", add_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mul_func},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fct(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}

/**
 * call_fct - call the function to exercute
 * @func: Pointer to the function that is about to be called
 * @op: opcode
 * @value: string representing a numeric value
 * @ln: line number
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
*/
void call_fct(op_func func, char *op, char *value, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err(5, ln);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
