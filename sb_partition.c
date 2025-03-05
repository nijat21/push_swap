#include "push_swap.h"

void back_to_a(node **src, node **dst)
{
    int max;
    int max_i;
    int size;

    size = count_nodes(*src);
    while (*src && size > 0)
    {
        max = find_max(*src);
        max_i = max_index(*src);
        if ((*src)->data == max)
            push_to_stack(src, dst, 'b');
        else if (max_i == 1)
        {
            swap_first_two(src, 'b');
            push_to_stack(src, dst, 'a');
        }
        else
            cheap_rotate(src, max_i, 'b');
        size = count_nodes(*src);
    }
}
