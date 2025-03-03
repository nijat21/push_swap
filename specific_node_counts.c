#include "push_swap.h"

int find_max(node *src)
{
    int max;

    max = 0;
    while (src)
    {
        if (src->data > max)
            max = src->data;
        src = src->next;
    }
    return max;
}

int find_min(node *src)
{
    int min;

    min = 0;
    while (src)
    {
        if (src->data < min)
            min = src->data;
        src = src->next;
    }
    return min;
}

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

void handle_three_nodes(node **src, node **dst, int *pushed)
{
    int max;
    int min;

    max = find_max(*src);
    min = find_min(*src);
    if (min == 2 && max == 0)
        return;
    else if (min == 0 && max == 2)
    {
        rotate_stack(src, 'b');
        swap_first_two(src, 'b');
    }
    else if (min == 2 && max == 1)
        swap_first_two(src, 'b');
    else if (min == 0 && max == 1)
        rotate_stack(src, 'b');
    else if (min == 1 && max == 2)
        rev_rotate_stack(src, 'b');
    else
    {
        rev_rotate_stack(src, 'b');
        swap_first_two(src, 'b');
    }
    while (src && *src)
    {
        push_to_stack(src, dst, 'a');
        (*pushed)++;
    }
}