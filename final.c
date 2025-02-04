#include "push_swap.h"

int is_sorted(node *stack)
{
    while (stack->next)
    {
        if (stack->data > stack->next->data)
            return (0);
        return (1);
    }
}

int tail_smaller_median(node *a, int median)
{
    while (a->next)
        a = a->next;
    if (a->data < median)
        return (1);
    return (0);
}

int has_smaller(node *a, int median)
{
    while (a)
    {
        if (a->data < median)
            return 1;
        a = a->next;
    }
    return 0;
}

void partition(node **stack, node **b, int size, int median)
{
    node *a;

    a = *stack;
    while (!is_sorted(a) && has_smaller(a, median))
    {
        if (a->data < median)
            pb(&a, b);
        else
        {
            if (tail_smaller_median(a, median))
            {
                rra(&a);
                pb(&a, b);
            }
            else
                ra(&a);
        }
    }
}

void final(node **stack)
{
    int median;
    node *b = NULL;
    int size;

    size = count_nodes(*stack);
    median = find_median(*stack, size);
    while (*stack && count_nodes(*stack) > 2)
    {
        partition(stack, &b, size, median);
    }
    if (count_nodes(*stack) == 2 && !is_sorted(*stack))
        sa(stack);
}