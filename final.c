#include "push_swap.h"

int desc_sorted(node *stack)
{
    node *temp;

    temp = stack;
    while (temp->next)
    {
        if (temp->data < temp->next->data)
            return (0);
        temp = temp->next;
    }
    return (1);
}

void final(node **sa)
{
    node *sb = NULL;
    int size;
    int *medians;

    size = count_nodes(*sa);
    if (!sa || !(*sa) || is_sorted(*sa) || size <= 1)
        return;
    else if (size == 2 && !is_sorted(*sa))
    {
        swap_first_two(sa, 'a');
        return;
    }
    else if (size >= 3 && size <= 10)
        simple_sort(sa, &sb, size);
    else if (size > 10 && size <= 100)
    {
        medians = malloc((4 - 1) * sizeof(int));
        find_median(*sa, size, 4, &medians);
        to_b(sa, &sb, 4, &medians);
        to_a(&sb, sa);
    }
    else if (size > 100)
    {
        medians = malloc((8 - 1) * sizeof(int));
        find_median(*sa, size, 8, &medians);
        to_b(sa, &sb, 8, &medians);
        to_a(&sb, sa);
    }
    free_stack(&sb);
    printf("Sorted: %d\n", is_sorted(*sa) && count_nodes(*sa) == size);
}

// node *temp = *sa;
// while (temp)
// {
//     printf("A %i\n", temp->data);
//     temp = temp->next;
// }
// temp = sb;
// while (temp)
// {
//     printf("B %i\n", temp->data);
//     temp = temp->next;
// }