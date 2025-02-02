#include "push_swap.h"

int get_size(node *stack)
{
    int count = 0;

    while (stack->next)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

int main(int ac, char **av)
{
    node *res;
    // node *tail;

    (void)av;
    if (ac < 2)
        return (0);

    res = format_input(ac, av);

    find_median(res);

    sort(&res);

    printf("Res\n");
    while (res)
    {
        printf("%i\n", res->data);
        res = res->next;
    }
}
