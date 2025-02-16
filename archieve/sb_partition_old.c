#include "push_swap.h"

int sb_partition(node **src, node **dst, int partition_size)
{
    int median;
    int count;
    int i = 0;
    int rotations = 0;

    median = find_median(*src, partition_size, &count);
    count = partition_size - count - 1;
    while (i < count && *src)
    {

        printf("i: %d, count: %d, current number: %d, median: %d\n",
               i, count, (*src)->data, median);

        if (count - i <= 2)
        {
            if (count - i == 2 && *src && (*src)->next && (*src)->data < (*src)->next->data)
            {
                swap_first_two(src);
                push_to_stack(src, dst);
                ft_putstr_fd("pa\n", 1);
                i++;
            }
            push_to_stack(src, dst);
            ft_putstr_fd("pa\n", 1);
            i++;
            continue;
        }
        if (*src && (*src)->data > median)
        {
            push_to_stack(src, dst);
            ft_putstr_fd("pa\n", 1);
            i++;
        }
        else if (*src)
        {
            rotate_stack(src);
            ft_putstr_fd("rb\n", 1);
            rotations++;
        }

        // Add check for full rotation
        if (rotations >= partition_size)
        {
            printf("Full rotation without finding enough numbers > median\n");
            break;
        }
    }
    while (rotations > 0 && *src)
    {
        rev_rotate_stack(src);
        ft_putstr_fd("rrb\n", 1);
        rotations--;
    }

    printf("Count: %d I: %d\n", count, i);

    return i;
}

void to_a(node **src, node **dst, int *sizes, int index)
{
    int i;

    i = index - 1;
    while (i >= 0)
    {
        if (sizes[i] <= 2)
        {
            if (sizes[i] == 2 && *src && (*src)->next && (*src)->data < (*src)->next->data)
            {
                swap_first_two(src);
                push_to_stack(src, dst);
                ft_putstr_fd("pa\n", 1);
            }
            push_to_stack(src, dst);
            ft_putstr_fd("pa\n", 1);
        }
        else
        {
            sb_partition(src, dst, sizes[i]);
            if (*src)
                to_a(src, dst, sizes, i);
            // int pushed = sb_partition(src, dst, sizes[i]);
            // int remaining = sizes[i] - pushed;
            // if (remaining > 0)
            // {
            //     sizes[i] = remaining;         // Update size to remaining elements
            //     to_a(src, dst, sizes, index); // Reprocess current partition
            // }
        }
        i--;
    }
}

void small_partitions(node **src, node **dst, int size, int *i)
{ // Handle small partitions directly
    if (size == 2 && *src && (*src)->data < (*src)->next->data)
    {
        swap_first_two(src);
        push_to_stack(src, dst);
        ft_putstr_fd("pa\n", 1);
        (*i)++;
    }
    push_to_stack(src, dst);
    ft_putstr_fd("pa\n", 1);
    (*i)++;
}
