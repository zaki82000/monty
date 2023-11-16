#include "monty.h"

int main(int argc, char *argv[])
{
    stack_t *mystack = NULL;
    char *bytecode_file = argv[1];
    FILE *fp = fopen(bytecode_file, "r");
    char line[1024];
    instruction_t instructions[] = {
        {"push", push},
        {"nop", nop},
        {"NULL", NULL},
    };
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <bytecode_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open bytecode file: %s\n", bytecode_file);
        return EXIT_FAILURE;
    }
    /*else if (fp != 'c')
    {
        fprintf(stderr, "Failed to open bytecode file: %s\n", bytecode_file);
        return EXIT_FAILURE;
    }*/
    
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *opcode = strtok(line, " ");
        if (opcode != NULL && strcmp(opcode, "push") == 0)
        {
            char *argument = strtok(NULL, " ");
            if (argument != NULL)
            {
                int number = atoi(argument);
                instructions[0].f(&mystack, number);
            }
        }
    }

    fclose(fp);

    while (mystack != NULL)
    {
        printf("%d\n", mystack->n);
        mystack = mystack->next;
    }

    return EXIT_SUCCESS;
}
