#include "monty.h"

/**
 * nop - a function that does nothing xD
 * @stack: a pointer to the stack.
 * @line_number: the line number.
 */
void nop(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	(void)line_number;
}
