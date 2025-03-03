#include "push_swap.h"

int is_sorted(node *stack)
{
    node *temp;

    temp = stack;
    while (temp->next)
    {
        if (temp->data > temp->next->data)
        {
            // printf("Sort break %d\n", temp->data);
            return (0);
        }
        temp = temp->next;
    }
    return (1);
}

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
    int sizes[count_nodes(*sa) - 2];
    int index = 0;

    size = count_nodes(*sa);
    if (is_sorted(*sa))
        return;
    else if (size == 2 && !is_sorted(*sa))
    {
        swap_first_two(sa, 'a');
        return;
    }

    to_b(sa, &sb, sizes, &index);
    // back_to_a(&sb, sa, sizes, &index);

    // }

    // for (int i = 2; i >= 0; i--)
    // {
    //     printf("Sizes %i\n", sizes[i]);
    // }

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
    printf("Sorted: %d\n", is_sorted(*sa));
    free_stack(&sb);
}
