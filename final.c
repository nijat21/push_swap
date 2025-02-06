#include "push_swap.h"

int is_sorted(node *stack)
{
    while (stack->next)
    {
        if (stack->data > stack->next->data)
            return (0);
    }
    return (1);
}

int tail_smaller_median(node *stack, int median)
{
    while (stack->next)
        stack = stack->next;
    if (stack->data < median)
        return (1);
    return (0);
}

int tail_bigger_median(node *stack, int median)
{
    while (stack->next)
        stack = stack->next;
    if (stack->data < median)
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

void partition_a(node **stack, node **b)
{
    int median;

    median = find_median(*stack, count_nodes(*stack));
    while (!is_sorted(*stack) && has_smaller(*stack, median))
    {
        printf("A partition");
        if ((*stack)->data < median)
            pb(stack, b);
        else
        {
            if (tail_smaller_median(*stack, median))
            {
                rra(stack);
                pb(stack, b);
            }
            else
                ra(stack);
        }
    }
}

void partition_b(node **stack, node **b)
{
    int median;

    median = find_median(*stack, count_nodes(*b));
    while (*b && count_nodes(*b) > 0)
    {
        if ((*b)->data < median)
            pa(b, stack);
        else
        {
            if (tail_bigger_median(*b, median))
            {
                rrb(b);
                pa(b, stack);
            }
            else
                rb(b);
        }
    }
}

void final(node **stack)
{
    node *b = NULL;
    int size;

    printf("Final");
    size = count_nodes(*stack);
    if (size == 2 && !is_sorted(*stack))
        sa(stack);
    while (*stack && size > 2)
    {
        printf("A loop");
        partition_a(stack, &b);
    }
    while (b && count_nodes(b) > 0)
    {
        printf("B loop");
        partition_b(stack, &b);
    }
    // free_stack(stack);
    free_stack(&b);
}