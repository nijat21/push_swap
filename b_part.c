#include "push_swap.h"

void to_a(node **src, node **dst)
{
    int max_i;
    int node_c;

    if (!src || !(*src))
        return;
    while (*src)
    {
        max_i = max_index(*src);
        node_c = count_nodes(*src);
        if (max_i == 0)
            push_to_stack(src, dst, 'a');
        else if (max_i < node_c / 2)
        {
            rotate_stack(src, 'b');
        }
        else
        {
            rev_rotate_stack(src, 'b');
        }
    }
}