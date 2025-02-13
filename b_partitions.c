#include "push_swap.h"

void handle_small_stack(node **src, node **dst, int size, int *pushed)
{
    if (!src || !(*src))
        return;
    if (size == 2)
    {
        if (*src && (*src)->next && (*src)->data < (*src)->next->data)
        {
            swap_first_two(src);
            // printf("Data %d next %d\n", (*src)->data, (*src)->next->data);
            ft_putstr_fd("sb\n", 1);
        }
        // printf("push small %d\n", (*src)->data);
        push_to_stack(src, dst);
        ft_putstr_fd("pa\n", 1);
        (*pushed)++;
    }
    // printf("push small %d\n", (*src)->data);
    push_to_stack(src, dst);
    ft_putstr_fd("pa\n", 1);
    (*pushed)++;
}

int has_bigger(int num, node *src)
{
    if (!src)
        return 0;
    while (src)
    {
        if (src->data > num)
            return 1;
        src = src->next;
    }
    return 0;
}

void b_partir(node **src, node **dst, int partition_size, int *pushed)
{
    int median;
    int count_bigger;
    int i = 0;
    int rotations = 0;

    median = find_median(*src, partition_size, &count_bigger);
    count_bigger = partition_size - count_bigger - 1;
    // printf("Median %d\n", median);
    // printf("count_bigger %d\n", count_bigger);
    while (i < partition_size && (*pushed) < count_bigger)
    {
        if ((*src) && (*src)->data > median && !has_bigger((*src)->data, *src))
        {
            push_to_stack(src, dst);
            ft_putstr_fd("pa\n", 1);
            // printf("push %d\n", (*src)->data);
            // printf("push now %d\n", push_now(*src, median, count_bigger, partition_size));
            (*pushed)++;
        }
        else
        {
            rotate_stack(src);
            ft_putstr_fd("rb\n", 1);
            rotations++;
        }
        // if (partition_size - i == 2)
        //     handle_small_stack(src, dst, 2, pushed);
        i++;
    }
    while (rotations)
    {
        rev_rotate_stack(src);
        ft_putstr_fd("rrb\n", 1);
        rotations--;
    }
    // printf("b_partir - pushed %d\n", partition_size - (*pushed));
}

void back_to_a(node **src, node **dst, int *sizes, int *index)
{
    int current_partition_size;
    static int pushed;
    int leftover = 0;
    // int curr_index = (*index) - 1;
    // If there are 3 partitions, current index is 2, the last one.

    current_partition_size = sizes[(*index) - 1];
    // printf("Stage1 ==> Index %d Size %d Leftover %d Pushed %d\n", *index - 1, current_partition_size, leftover, pushed);
    if (current_partition_size <= 2)
    {
        handle_small_stack(src, dst, current_partition_size, &pushed);
        // printf("to_a small\n");
    }
    else
    {
        b_partir(src, dst, current_partition_size, &pushed);
        // printf("to_a large\n");
    }

    leftover = current_partition_size - pushed;
    // printf("Stage2 ==> Index %d Size %d Leftover %d Pushed %d\n", *index - 1, current_partition_size, leftover, pushed);
    if (leftover > 0)
    {
        sizes[(*index) - 1] = leftover;
        pushed = 0;
        back_to_a(src, dst, sizes, index);
    }
    else
    {
        (*index)--;
        pushed = 0;
        if ((*index) - 1 >= 0)
            back_to_a(src, dst, sizes, index);
    }
}
