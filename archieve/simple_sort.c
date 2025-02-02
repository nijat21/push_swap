#include "push_swap.h"

void simple_sort(node **stack)
{
    node *new_s = NULL;

    while (*stack)
    {
        if (!new_s)
        {
            push_to_stack(stack, &new_s);
            ft_putstr_fd("pb\n", 1);
        }
        if (*stack && (*stack)->data < new_s->data)
        {
            push_to_stack(&new_s, stack);
            ft_putstr_fd("pa\n", 1);
            swap_first_two(stack);
        }
        else
        {
            push_to_stack(stack, &new_s);
            ft_putstr_fd("pb\n", 1);
        }
    }
    while (new_s)
    {
        push_to_stack(&new_s, stack);
        ft_putstr_fd("pa\n", 1);
    }
}