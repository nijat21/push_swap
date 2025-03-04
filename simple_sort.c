#include "push_swap.h"

void simple_sort(node **src, node **dst)
{
    int min;
    int min_i;
    int size;

    size = count_nodes(*src);
    while (*src && size > 3)
    {
        min = find_min(*src);
        min_i = min_index(*src);
        if ((*src)->data == min)
            push_to_stack(src, dst, 'b');
        else if (min_i == 1)
        {
            swap_first_two(src, 'a');
            push_to_stack(src, dst, 'b');
        }
        else
            cheap_rotate(src, min_i, 'a');
        size = count_nodes(*src);
    }
    if (size == 3)
        handle_three_asc(src, 'a');
    while (*dst)
        push_to_stack(dst, src, 'a');
}
