#include "push_swap.h"

// What if it's only spaces but not num
int check_for_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && !(str[i] == ' ' || str[i] == '-' || str[i] == '+'))
            return 0;
        i++;
    }
    return 1;
}

int check_duplicate(int num, node *list)
{
    while (list)
    {
        if (num == list->data)
            return 0;
        list = list->next;
    }
    return 1;
}
