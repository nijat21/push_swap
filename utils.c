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

    if (!stack || !(*stack))
        return;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
    *stack = NULL;
}

// Free a dynamic array
void free_arr(char ***str)
{
    int i;

    i = 0;
    while ((*str)[i])
    {
        free((*str)[i]);
        i++;
    }
    free(*str);
    *str = NULL;
}

// Count nodes of the linked list
int count_nodes(node *stack)
{
    int count = 0;

    if (!stack)
        return (0);
    node *current = stack;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

int is_sorted(node *stack)
{
    node *temp;

    temp = stack;
    while (temp->next)
    {
        if (temp->data > temp->next->data)
        {
            // printf("Sort break %d\n", temp->data);
            return (0);
        }
        temp = temp->next;
    }
    return (1);
}