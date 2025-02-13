void sb_partition(node **sb, node **sa)
{
    int median;
    int count;
    int i = 0;
    int length = 0;

    length = count_nodes(*sb);
    median = find_median(*sb, length, &count);
    printf("Median %d\n", median);
    printf("Count %d\n", length - count);
    if (count_nodes(*sb) == 2)
    {
        if (is_sorted(*sb))
            swap_first_two(sb);
        push_to_stack(sb, sa);
        ft_putstr_fd("pa\n", 1);
        push_to_stack(sb, sa);
        ft_putstr_fd("pa\n", 1);
        i += 2;
        return;
    }
    while (i < (length - count - 1))
    {
        if ((*sb)->data > median)
        {
            push_to_stack(sb, sa);
            ft_putstr_fd("pb\n", 1);
            i++;
        }
        else
        {
            rotate_stack(sb);
            ft_putstr_fd("B ra\n", 1);
        }
    }
}

void to_a(node **sb, node **sa)
{
    if (count_nodes(*sb) == 0)
        return;
    sb_partition(sb, sa);
    to_a(sb, sa);
}