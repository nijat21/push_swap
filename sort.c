#include "push_swap.h"

int min(node *stack)
{
    node *temp;
    int res = stack->data;

    temp = stack;
    while (temp)
    {
        if (temp->data < res)
            res = temp->data;
        temp = temp->next;
    }
    return res;
}

void sort(node **stack)
{
    node *temp = NULL;

    while ((*stack))
    {
        while ((*stack)->data != min((*stack)))
        {
            rotate_stack(stack);
        }
        push_to_stack(stack, &temp);
    }
    while (temp)
    {
        push_to_stack(&temp, stack);
    }
}
