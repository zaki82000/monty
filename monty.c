#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = (stack_t*)malloc(sizeof(stack_t));

    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    temp->n = line_number;
    temp->next = *stack;
    temp->prev = NULL;

    if (*stack != NULL)
    {
        (*stack)->prev = temp;
    }
        *stack = temp;
    
}