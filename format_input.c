#include "push_swap.h"

// input is given as "1 3 4 5 6 7 8" -> 1 string av[1]
// input is given as 1 3 4 5 6 7 8 -> 7 strings av[1], av[2] ....av[6]
// input is given as "1 2 3 5" 5 6 7 8 -> 2 strings av[1], av[2]
// check non-numeric
// check duplicate -> ft_split -> ?
// check min max int -> ft_split -> ft_atoi

node *create_node(int num)
{
    node *new_node = NULL;

    new_node = malloc(sizeof(node));
    if (!new_node)
        return NULL;
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

int arr_to_stack(node **head, node **tail, char ***split_res)
{
    int i;
    int num;
    node *new_node = NULL;

    i = 0;
    while ((*split_res)[i])
    {
        num = ft_atoi((*split_res)[i]);
        if (!is_valid(num, (*split_res)[i], head))
            return 0;
        new_node = create_node(num);
        if (!new_node)
            return 0;
        if (!(*head))
            (*head) = new_node;
        if ((*tail))
        {
            (*tail)->next = new_node;
            new_node->prev = (*tail);
        }
        (*tail) = new_node;
        new_node = NULL;
        i++;
    }
    return (1);
}

int create_stack(char *str, node **head, node **tail)
{
    char **split_res;
    int res;

    split_res = ft_split(str, ' ');
    if (!split_res)
    {
        free_arr(&split_res);
        free_stack(head);
        return (0);
    }
    if ((*head) != NULL)
    {
        (*tail) = (*head);
        while ((*tail)->next)
            (*tail) = (*tail)->next;
    }
    res = arr_to_stack(head, tail, &split_res);
    free_arr(&split_res);
    if (!res)
    {
        free_stack(head);
        return (0);
    }
    return 1;
}

node *format_input(int ac, char **av)
{
    node *head = NULL;
    node *tail = NULL;
    int list_created;
    int i;

    i = 1;
    while (i < ac)
    {
        list_created = create_stack(av[i], &head, &tail);
        if (!list_created)
        {
            free_stack(&head);
            return NULL;
        }
        i++;
    }
    return head;
}
