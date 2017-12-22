#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *next;
    double value;
} node_t;

typedef struct
{
    node_t *head;
} stack_t;

void init_stack(stack_t *stack)
{
    stack->head = NULL;
}

void push(stack_t *stack, double value)
{
    node_t *new = malloc(sizeof(node_t));
    new->value = value;
    new->next = stack->head;
    stack->head = new;
}

double pop(stack_t *stack)
{
    node_t *temp = stack->head;
    stack->head = temp->next;
    double value = temp->value;
    free(temp);
    return value;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Primer pokretanja programa: ./a.out ime_datoteke.txt\n");
        return 1;
    }

    stack_t stack;
    init_stack(&stack);

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        puts("Greska pri otvaranju datoteke!\n");
        return 2;
    }

    char str[10];
    while (fscanf(file, "%s", str) == 1)
    {
        if (strcmp(str, "+") == 0)
        {
            push(&stack, pop(&stack) + pop(&stack));
        }
        else if (strcmp(str, "*") == 0)
        {
            push(&stack, pop(&stack) * pop(&stack));
        }
        else if (strcmp(str, "-") == 0)
        {
            double a = pop(&stack);
            double b = pop(&stack);
            push(&stack, b - a);
        }
        else if (strcmp(str, "/") == 0)
        {
            double a = pop(&stack);
            double b = pop(&stack);
            push(&stack, b / a);
        }
        else
        {
            push(&stack, atof(str));
        }
    }

    printf("%lf\n", pop(&stack));
    return 0;
}

