#include "push_swap.h"

void handle_two(node **src, node **dst, int size, int *pushed)
{
    if (!src || !(*src))
        return;
    // printf("Handle small num1 %d\n", (*src)->data);
    if ((*src)->next)
        // printf("Handle small num2 %d\n", (*src)->next->data);
        if (size == 2)
        {
            if ((*src)->next && ((*src)->data < (*src)->next->data))
                swap_first_two(src, 'b');
            push_to_stack(src, dst, 'a');
            (*pushed)++;
        }
    push_to_stack(src, dst, 'a');
    (*pushed)++;
}

void handle_three_asc(node **src, char s_name)
{
    int max;
    int min;

    max = max_index(*src);
    min = min_index(*src);
    if (is_sorted(*src))
        return;
    else if (min == 2 && max == 0)
    {
        rotate_stack(src, s_name);
        swap_first_two(src, s_name);
    }
    else if (min == 2 && max == 1)
        rev_rotate_stack(src, s_name);
    else if (min == 0 && max == 1)
    {
        rev_rotate_stack(src, s_name);
        swap_first_two(src, s_name);
    }
    else if (min == 1 && max == 2)
        swap_first_two(src, s_name);
    else if (min == 1 && max == 0)
        rotate_stack(src, s_name);
}
