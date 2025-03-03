#include "push_swap.h"

int has_bigger(int num, node *src)
{
    if (!src)
        return 0;
    while (src)
    {
        if (src->data > num)
            return 1;
        src = src->next;
    }
    return 0;
}

int max_index(node *src, int part_size)
{
    int i;
    int max;

    i = 0;
    max = find_max(src);
    while (src && i < part_size)
    {
        if (src->data == max)
            return i;
        src = src->next;
        i++;
    }
    return 0;
}

void b_partition(node **src, node **dst, int part_size, int *pushed)
{
    int median;
    int count_bigger;
    int i = 0;
    int rotations = 0;
    int rev_rotates = 0;
    int m_i;
    int l_size;

    median = find_median(*src, part_size, &count_bigger);
    count_bigger = part_size - count_bigger - 1;
    while (*src && i < part_size && (*pushed) < count_bigger)
    {
        // if (count_bigger - *pushed <= 2)
        if ((*src)->data > median && !has_bigger((*src)->data, *src))
        {
            // AN ARRAY OF NUMBERS THAT HAS THE LOWER LIMITS OF EACH PARTITION
            // EXPORT CURRENT PARTITION TO AN ARRAY AND GIVE IT TO A FUNCTION TO FIGURE OUT BEST SORTING
            push_to_stack(src, dst, 'a');
            (*pushed)++;
            i++;
        }
        else
        {
            m_i = max_index(*src, part_size);
            l_size = count_nodes(*src);
            if (m_i < l_size / 2)
            {
                rotate_stack(src, 'b');
                rotations++;
            }
            else
            {
                rev_rotate_stack(src, 'b');
                rev_rotates++;
            }
        }
        i++;
    }
    while (rotations)
    {
        rev_rotate_stack(src, 'b');
        rotations--;
    }
    while (rev_rotates)
    {
        rotate_stack(src, 'b');
        rev_rotates--;
    }
    // printf("b_partition - pushed %d\n", part_size - (*pushed));
}

void back_to_a(node **src, node **dst, int *sizes, int *index)
{
    int current_part_size;
    static int pushed;
    int leftover = 0;
    // int curr_index = (*index) - 1;
    // If there are 3 partitions, current index is 2, the last one.

    current_part_size = sizes[(*index) - 1];
    // printf("Stage1 ==> Index %d Size %d Leftover %d Pushed %d\n", *index - 1, current_part_size, leftover, pushed);
    if (current_part_size <= 2)
    {
        handle_two(src, dst, current_part_size, &pushed);
        // printf("to_a lt_two\n");
    }
    else
    {
        b_partition(src, dst, current_part_size, &pushed);
        // printf("to_a large\n");
    }

    leftover = current_part_size - pushed;
    // printf("Stage2 ==> Index %d Size %d Leftover %d Pushed %d\n", *index - 1, current_part_size, leftover, pushed);
    pushed = 0;
    if (leftover > 0)
    {
        sizes[(*index) - 1] = leftover;
        back_to_a(src, dst, sizes, index);
    }
    else
    {
        (*index)--;
        if ((*index) - 1 >= 0)
            back_to_a(src, dst, sizes, index);
    }
}
