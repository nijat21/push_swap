#include "push_swap.h"

int find_max(node *src)
{
    int max;

    max = src->data;
    while (src)
    {
        if (src->data > max)
            max = src->data;
        src = src->next;
    }
    return max;
}

int max_index(node *src)
{
    int i;
    int max;

    i = 0;
    max = find_max(src);
    while (src)
    {
        if (src->data == max)
            return i;
        src = src->next;
        i++;
    }
    return 0;
}

int find_min(node *src)
{
    int min;

    min = src->data;
    while (src)
    {
        if (src->data < min)
            min = src->data;
        src = src->next;
    }
    return min;
}

int min_index(node *src)
{
    int i;
    int min;

    i = 0;
    min = find_min(src);
    while (src)
    {
        if (src->data == min)
            return i;
        src = src->next;
        i++;
    }
    return 0;
}

void cheap_rotate(node **src, int index, char s_name)
{
    int size;

    size = count_nodes(*src);
    if (index < size / 2)
        rotate_stack(src, s_name);
    else
        rev_rotate_stack(src, s_name);
}