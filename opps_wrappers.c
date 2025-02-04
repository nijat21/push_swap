#include "push_swap.h"

// Wrapper functions for the operations
void sa(node **stack_a)
{
    swap_first_two(stack_a);
}

void sb(node **stack_b)
{
    swap_first_two(stack_b);
}

void ss(node **stack_a, node **stack_b)
{
    swap_first_two(stack_a);
    swap_first_two(stack_b);
}

void pa(node **stack_b, node **stack_a)
{
    push_to_stack(stack_b, stack_a);
}

void pb(node **stack_a, node **stack_b)
{
    push_to_stack(stack_a, stack_b);
}

void ra(node **stack_a)
{
    rotate_stack(stack_a);
}

void rb(node **stack_b)
{
    rotate_stack(stack_b);
}

void rr(node **stack_a, node **stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
}

void rra(node **stack_a)
{
    rev_rotate_stack(stack_a);
}

void rrb(node **stack_b)
{
    rev_rotate_stack(stack_b);
}

void rrr(node **stack_a, node **stack_b)
{
    rev_rotate_stack(stack_a);
    rev_rotate_stack(stack_b);
}