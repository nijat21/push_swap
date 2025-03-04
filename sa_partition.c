#include "push_swap.h"

int tail_smaller_median(node *stack, int median)
{
    while (stack->next)
        stack = stack->next;
    if (stack->data < median)
        return (1);
    return (0);
}

int next_smaller(node *src, int median)
{
    int i;

    i = 0;
    while (src)
    {
        if (src->data <= median)
            return i;
        src = src->next;
        i++;
    }
    return -1;
}

void sa_partition(node **src, node **dst, int median)
{
    while (next_smaller(*src, median) != -1 && count_nodes(*src) > 3)
    {
        if ((*src)->data <= median)
            push_to_stack(src, dst, 'b');
        else
        {
            if (tail_smaller_median(*src, median))
            {
                rev_rotate_stack(src, 'a');
                push_to_stack(src, dst, 'b');
            }
            else
                cheap_rotate(src, next_smaller(*src, median), 'a');
        }
    }
    if (count_nodes(*src) == 3)
        handle_three_asc(src, 'a');
    return;
}

void sort_a(node **src)
{
    int min;
    int min_i;
    node *temp;

    temp = *src;
    while (!is_sorted(*src))
    {
        min = find_min(temp);
        min_i = min_index(temp);
        cheap_rotate(&temp, min_i, 'a');
        if (min == temp->data)
            temp++;
    }
    // if (count_nodes(temp) == 3)
    //     handle_three_asc(&temp, 'a');
}

void to_b(node **src, node **dst, int denom, int **medians)
{
    int list_len;
    static int index = 0;

    list_len = count_nodes(*src);
    if (list_len <= 1 || is_sorted(*src))
        return;
    else if (list_len == 2)
    {
        if (!is_sorted(*src))
            swap_first_two(src, 'a');
        return;
    }
    else if (list_len == 3)
    {
        handle_three_asc(src, 'a');
        return;
    }
    else
    {
        sa_partition(src, dst, (*medians)[index]);
        index++;
    }
    if (index < denom - 1)
        to_b(src, dst, denom, medians);
    else
    {
        free(*medians);
        sort_a(src);
    }
}