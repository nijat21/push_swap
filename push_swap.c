#include "push_swap.h"

int main(int ac, char **av)
{
    node *res = NULL;
    // node *tail;

    if (ac < 2)
        return (0);

    res = format_input(ac, av);
    if (!res)
    {
        free_stack(&res);
        return (0);
    }

    // sort(&res);
    final(&res);

    node *temp = res;

    printf("Res\n");
    while (temp)
    {
        printf("%i\n", temp->data);
        temp = temp->next;
    }
    free_stack(&res);
}
