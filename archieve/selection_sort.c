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

// Function to find the minimum value in the stack
int find_min(node *stack)
{
    int min = stack->data;
    node *current = stack;

    while (current)
    {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }
    return min;
}

// Function to find the maximum value in the stack
int find_max(node *stack)
{
    int max = stack->data;
    node *current = stack;

    while (current)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

// Function to count nodes in stack
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

// Function to find the best rotation direction and count for a target number
void find_best_rotation(node *stack, int target, int *rotations, int *reverse)
{
    int position = 0;
    int size = count_nodes(stack);
    node *current = stack;

    while (current && current->data != target)
    {
        position++;
        current = current->next;
    }

    if (position <= size / 2)
    {
        *rotations = position;
        *reverse = 0;
    }
    else
    {
        *rotations = size - position;
        *reverse = 1;
    }
}

// Main sorting function
void sort_stacks(node **stack_a, node **stack_b)
{
    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;

    // Push all elements except 2 to stack_b
    while (count_nodes(*stack_a) > 2)
        pb(stack_a, stack_b);

    // Sort the 2 remaining elements in stack_a if needed
    if ((*stack_a)->data > (*stack_a)->next->data)
        sa(stack_a);

    // Now insert elements back into stack_a in sorted order
    while (*stack_b)
    {
        node *current = *stack_a;
        int target = (*stack_b)->data;
        int rotations, reverse;

        // Find the correct position in stack_a
        if (target < find_min(*stack_a))
        {
            // If smaller than min, rotate to put min at top
            find_best_rotation(*stack_a, find_min(*stack_a), &rotations, &reverse);
        }
        else if (target > find_max(*stack_a))
        {
            // If larger than max, rotate to put max at bottom
            find_best_rotation(*stack_a, find_max(*stack_a), &rotations, &reverse);
            rotations = (rotations + 1) % count_nodes(*stack_a);
        }
        else
        {
            // Find position between two numbers
            while (current->next)
            {
                if (target > current->data && target < current->next->data)
                    break;
                current = current->next;
            }
            find_best_rotation(*stack_a, current->data, &rotations, &reverse);
        }

        // Perform rotations
        while (rotations--)
        {
            if (reverse)
                rra(stack_a);
            else
                ra(stack_a);
        }

        // Push element to correct position
        pa(stack_b, stack_a);
    }

    // Final rotation to ensure minimum is at top
    int rotations, reverse;
    find_best_rotation(*stack_a, find_min(*stack_a), &rotations, &reverse);
    while (rotations--)
    {
        if (reverse)
            rra(stack_a);
        else
            ra(stack_a);
    }
}
