#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

#define DELIMS " \n\t\a\b"

extern char **args;
extern size_t error;

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
} stack_t;

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

/* HELPERS */
int is_delim(char ch, char *delim);
char **strtow(char *str, char *delim);
int is_int(char *str);

/* ERRORS */
size_t _stderr(char *message);
size_t invalid_opcode(unsigned int l_num, char *opcode);
size_t usage_error(unsigned int l_num, char *opcode, char *message);
size_t line_error(unsigned int l_num, char *message);
size_t stack_short_error(unsigned int l_num, char *message);

/* RUN */
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
size_t run(FILE *script);

/* STACK FUNCTIONS */
void free_stack(stack_t **);
void stack_push(stack_t **, unsigned int);
void stack_pall(stack_t **, unsigned int);
void stack_pint(stack_t **, unsigned int);
void stack_pop(stack_t **, unsigned int);
void stack_nop(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void stack_sub(stack_t **, unsigned int);
void stack_div(stack_t **, unsigned int);
void stack_mul(stack_t **, unsigned int);
void stack_mod(stack_t **, unsigned int);
void stack_swap(stack_t **, unsigned int);
void stack_pchar(stack_t **, unsigned int);
void stack_pstr(stack_t **, unsigned int);
void stack_rotl(stack_t **, unsigned int);
void stack_rotr(stack_t **, unsigned int);
void queue_push(stack_t **, unsigned int);

#endif /* MONTY_H */
