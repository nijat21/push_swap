#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.

// Swap first two elements of stack
void swap_first_two(node **stack)
{
    node *first;
    node *second;

    if (!stack || !(*stack) || !(*stack)->next)
        return;

    first = (*stack);
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    *stack = second;
}

// Push the first element from src to dst
void push_to_stack(node **src, node **dst)
{
    node *t_s;

    if (!src || !(*src))
        return;

    t_s = (*src);
    (*src) = (*src)->next;
    if ((*src))
        (*src)->prev = NULL;

    t_s->next = (*dst);
    if ((*dst))
        (*dst)->prev = t_s;
    (*dst) = t_s;
    (*dst)->prev = NULL;
}

// Rotate stack up by 1
void rotate_stack(node **stack)
{
    node *temp;
    node *iter;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    temp = (*stack);
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    iter = (*stack);
    while (iter->next)
        iter = iter->next;
    iter->next = temp;
    temp->prev = iter;
    temp->next = NULL;
}

// Rotate stack down by 1
void rev_rotate_stack(node **stack)
{
    node *iter;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    iter = *stack;
    while (iter->next)
        iter = iter->next;

    if (iter->prev)
        iter->prev->next = NULL;
    iter->prev = NULL;

    iter->next = *stack;
    (*stack)->prev = iter;
    (*stack) = iter;
}
