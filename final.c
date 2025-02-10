#include "push_swap.h"

int is_sorted(node *stack)
{
    node *temp;

    temp = stack;
    while (temp->next)
    {
        if (temp->data > temp->next->data)
            return (0);
        temp = temp->next;
    }
    return (1);
}

int tail_smaller_median(node *stack, int median)
{
    while (stack->next)
        stack = stack->next;
    if (stack->data < median)
        return (1);
    return (0);
}

int has_smaller(node **stack, int median)
{
    node *temp;

    temp = *stack;
    while (temp)
    {
        if (temp->data < median)
            return (1);
        temp = temp->next;
    }
    return 0;
}

int has_bigger(node **stack, int median)
{
    node *temp;

    temp = *stack;
    while (temp)
    {
        if (temp->data > median)
            return (1);
        temp = temp->next;
    }
    return 0;
}

void sa_partition(node **src, node **dst)
{
    int median;

    median = find_median(*src, count_nodes(*src));
    while (count_nodes(*src) > 2 && has_smaller(src, median)) //
    {
        if ((*src)->data < median)
        {
            push_to_stack(src, dst);
            ft_putstr_fd("pb\n", 1);
        }
        else
        {
            if (tail_smaller_median(*src, median))
            {
                rev_rotate_stack(src);
                ft_putstr_fd("rra\n", 1);
                push_to_stack(src, dst);
                ft_putstr_fd("pb\n", 1);
            }
            else
            {
                rotate_stack(src);
                ft_putstr_fd("ra\n", 1);
            }
        }
    }
}

void to_b(node **src, node **dst)
{
    if (count_nodes(*src) == 2)
    {
        if (!is_sorted(*src))
            swap_first_two(src);
        return;
    }

    sa_partition(src, dst);

    to_b(src, dst);
}

void sb_partition(node **src, node **dst)
{
    int median;

    median = find_median(*src, count_nodes(*src));
    while (count_nodes(*src) > 2 && has_bigger(src, median))
    {
        if ((*src)->data > median)
        {
            push_to_stack(src, dst);
            ft_putstr_fd("pb\n", 1);
        }
        else
        {
            rotate_stack(src);
            ft_putstr_fd("ra\n", 1);
        }
    }
}

void to_a(node **src, node **dst)
{
    if (count_nodes(*src) == 2)
    {
        if (is_sorted(*src))
        {
            swap_first_two(src);
        }
        push_to_stack(src, dst);
        ft_putstr_fd("pa\n", 1);
        push_to_stack(src, dst);
        ft_putstr_fd("pa\n", 1);
        return;
    }

    sb_partition(src, dst);

    to_a(src, dst);
}

void until_sorted(node **sa, node **sb, int size)
{
    if ((is_sorted(*sa) && count_nodes(*sa) == size))
        return;
    to_b(sa, sb);
    to_a(sb, sa);

    until_sorted(sa, sb, size);
}

void final(node **sa)
{
    node *sb = NULL;
    int size;

    printf("Final\n");
    size = count_nodes(*sa);
    if (size <= 1 || is_sorted(*sa)) // || is_sorted(*sa)
        return;
    else if (size == 2 && !is_sorted(*sa))
    {
        swap_first_two(sa);
        return;
    }

    // if (!(is_sorted(*sa) && count_nodes(*sa) == 100))
    // {
    //     to_b(sa, &sb);
    //     to_a(&sb, sa);
    // }
    until_sorted(sa, &sb, size);

    node *temp = *sa;
    while (temp)
    {
        printf("A %i\n", temp->data);
        temp = temp->next;
    }
    printf("Size %d\n", size);
    printf("Final size %d\n", count_nodes(*sa));
    printf("Sorted %d\n", is_sorted(*sa));
    free_stack(&sb);
}
