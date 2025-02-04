#include "push_swap.h"

// Count numbers from mixed string => 1 23 4 5 " 34 67 88 "
int count_nums(char *str)
{
    int count;
    int num;

    num = 0;
    count = 0;
    while (*str)
    {
        if (*str != ' ' && !num)
        {
            num = 1;
            count++;
        }
        else if (*str == ' ' && num)
            num = 0;
        str++;
    }
    return count;
}

// Free linked list
void free_stack(node **stack)
{
    node *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

// Count nodes of the linked list
int count_nodes(node *stack)
{
    int count = 0;
    node *current = stack;

    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}
