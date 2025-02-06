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

int arr_to_stack(node **head, node **temp, char ***split_res, int size)
{
    int i;
    int num;
    node *new_node = NULL;

    i = 0;
    while (i < size)
    {
        num = ft_atoi((*split_res)[i]);
        if ((!num && ft_strlen((*split_res)[i]) > 0) ||
            !check_for_numeric((*split_res)[i]) ||
            !check_duplicate(num, (*head)))
        {
            ft_putstr_fd("Error\n", 1);
            free_stack(head);
            free_arr(split_res, size);
            return 0;
        }
        new_node = create_node(num);
        if (!new_node)
        {
            free_stack(head);
            free_arr(split_res, size);
            return 0;
        }
        if (!(*head))
            (*head) = new_node;
        if ((*temp))
        {
            (*temp)->next = new_node;
            new_node->prev = (*temp);
        }
        (*temp) = new_node;
        new_node = NULL;
        i++;
    }
    free_arr(split_res, size);
    return (1);
}

int create_stack(char *str, node **head)
{
    node *temp = NULL;
    char **split_res;
    int size;
    int res;

    size = count_nums(str);
    split_res = ft_split(str, ' ');
    if (!split_res)
        return (0);
    if ((*head) != NULL)
    {
        temp = (*head);
        while (temp->next)
            temp = temp->next;
    }
    res = arr_to_stack(head, &temp, &split_res, size);
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
    node *tail;
    int list_created;
    int i;

    i = 1;
    while (i < ac)
    {
        list_created = create_stack(av[i], &head);
        if (!list_created)
        {
            free_stack(&head);
            return NULL;
        }
        i++;
    }
    tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    return head;
}
