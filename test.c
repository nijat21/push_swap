#include "push_swap.h"

// Helper function to find the position of the next maximum value
static int find_max_pos(node *stack, int max_val)
{
    int pos = 0;
    node *current = stack;

    while (current)
    {
        if (current->data == max_val)
            return pos;
        pos++;
        current = current->next;
    }
    return -1;
}

// Helper function to find the next maximum value in stack
static int find_next_max(node *stack, int current_max)
{
    int max = INT_MIN;
    node *current = stack;

    while (current)
    {
        if (current->data < current_max && current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

void optimize_rotations(node **stack, int pos, int stack_size)
{
    // Determine whether to use rotate or reverse rotate based on position
    if (pos <= stack_size / 2)
    {
        while (pos > 0)
        {
            rotate_stack(stack);
            ft_putstr_fd("rb\n", 1);
            pos--;
        }
    }
    else
    {
        while (pos < stack_size)
        {
            rev_rotate_stack(stack);
            ft_putstr_fd("rrb\n", 1);
            pos++;
        }
    }
}

void back_to_a(node **src, node **dst, int *sizes, int *index)
{
    if (!src || !(*src))
        return;

    int stack_size = sizes[(*index) - 1];
    if (stack_size <= 2)
    {
        // Handle small stacks directly
        if (stack_size == 2 && (*src)->data < (*src)->next->data)
        {
            swap_first_two(src);
            ft_putstr_fd("sb\n", 1);
        }
        while (stack_size--)
        {
            push_to_stack(src, dst);
            ft_putstr_fd("pa\n", 1);
        }
    }
    else
    {
        // Find current maximum value in the stack
        node *current = *src;
        int max_val = INT_MIN;
        while (current)
        {
            if (current->data > max_val)
                max_val = current->data;
            current = current->next;
        }

        // Push elements to stack A in descending order
        while (stack_size > 0)
        {
            int pos = find_max_pos(*src, max_val);
            if (pos != -1)
            {
                optimize_rotations(src, pos, stack_size);
                push_to_stack(src, dst);
                ft_putstr_fd("pa\n", 1);
                stack_size--;
                max_val = find_next_max(*src, max_val);
            }
        }
    }

    (*index)--;
    if ((*index) - 1 >= 0)
        back_to_a(src, dst, sizes, index);
}