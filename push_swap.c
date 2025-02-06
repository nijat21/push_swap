#include "push_swap.h"

void free_list(node *stack)
{
    node *temp;

    if (!stack)
        return;
    while (stack)
    {
        temp = (stack)->next;
        free(stack);
        stack = temp;
    }
    stack = NULL;
}

int main(int ac, char **av)
{
    node *res;
    // node *tail;

    if (ac < 2)
        return (0);

    res = format_input(ac, av);
    if (!res)
    {
        free_stack(&res);
        return (0);
    }

    sort(&res);

    printf("Res\n");
    while (res)
    {
        printf("%i\n", res->data);
        res = res->next;
    }
    free_list(res);
}
