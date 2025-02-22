#include "push_swap.h"

int tail_smaller_median(node *stack, int median)
{
    while (stack->next)
        stack = stack->next;
    if (stack->data < median)
        return (1);
    return (0);
}

void sa_partition(node **src, node **dst, int *partition_size)
{
    int median;
    int i = 0;

    median = find_median(*src, count_nodes(*src), partition_size);
    while (i < *partition_size)
    {
        if ((*src)->data < median)
        {
            push_to_stack(src, dst);
            ft_putstr_fd("pb\n", 1);
            i++;
        }
        else
        {
            if (tail_smaller_median(*src, median))
            {
                rev_rotate_stack(src);
                ft_putstr_fd("rra\n", 1);
                push_to_stack(src, dst);
                ft_putstr_fd("pb\n", 1);
                i++;
            }
            else
            {
                rotate_stack(src);
                ft_putstr_fd("ra\n", 1);
            }
        }
    }
}

void to_b(node **src, node **dst, int *sizes, int *index)
{
    int partition_size;

    partition_size = 0;
    if (count_nodes(*src) == 2)
    {
        if (!is_sorted(*src))
            swap_first_two(src);
        return;
    }
    sa_partition(src, dst, &partition_size);
    sizes[(*index)++] = partition_size;
    to_b(src, dst, sizes, index);
}