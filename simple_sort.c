#include "push_swap.h"

void merge_back(node **src, node **dst, int size, int count)
{
    if (size == 3)
        handle_three_asc(src, 'a');
    while (*dst && --count >= 0)
        push_to_stack(dst, src, 'a');
}

void simple_sort(node **src, node **dst, int size)
{
    int min;
    int min_i;
    int count;

    count = 0;
    while (*src && size > 3)
    {
        min = find_min(*src);
        min_i = min_index(*src);
        if ((*src)->data == min)
        {
            push_to_stack(src, dst, 'b');
            count++;
        }
        else if (min_i == 1)
        {
            swap_first_two(src, 'a');
            push_to_stack(src, dst, 'b');
            count++;
        }
        else
            cheap_rotate(src, min_i, 'a');
        size = count_nodes(*src);
    }
    merge_back(src, dst, size, count);
}
