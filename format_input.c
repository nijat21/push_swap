#include "push_swap.h"

// input is given as "1 3 4 5 6 7 8" -> 1 string av[1]
// input is given as 1 3 4 5 6 7 8 -> 7 strings av[1], av[2] ....av[6]
// input is given as "1 2 3 5" 5 6 7 8 -> 2 strings av[1], av[2]

// check non-numeric
// check duplicate -> ft_split -> ?
// check min max int -> ft_split -> ft_atoi

int count_nums(char *str)
{
    int count;
    int num;

    num = 0;
    count = 0;
    while (*str)
    {
        if (*str != ' ' && !num)
        {
            num = 1;
            count++;
        }
        else if (*str == ' ' && num)
            num = 0;
        str++;
    }
    return count;
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

node *create_node(int num)
{
    node *new_node;

    new_node = NULL;
    new_node = malloc(sizeof(node));
    if (!new_node)
        return NULL;
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

node *split_to_node(char *str)
{
    node *head = NULL;
    node *new_node;
    node *temp = NULL;
    char **split_res;
    int i;
    int num;

    split_res = ft_split(str, ' ');
    i = 0;
    while (i < count_nums(str))
    {
        num = ft_atoi(split_res[i]);
        if ((!num && ft_strlen(split_res[i]) > 0) ||
            !check_for_numeric(split_res[i]) ||
            !check_duplicate(num, head))
        {
            ft_putstr_fd("Error\n", 1);
            return NULL;
        }
        new_node = create_node(num);
        if (!new_node)
            return NULL;
        if (!head)
            head = new_node;
        if (temp)
        {
            temp->next = new_node;
            new_node->prev = temp;
        }
        temp = new_node;
        i++;
    }
    return head;
}

void format_input(int ac, char **av)
{
    node *head = NULL;
    node *temp;
    node *list;
    int i;

    i = 1;
    while (i < ac)
    {
        list = split_to_node(av[i]);
        if (!list)
            return;
        if (!head)
            head = list;
        else
        {
            temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = list;
        }
        i++;
    }
    temp = head;
    while (temp)
    {
        printf("%i\n", temp->data);
        temp = temp->next;
    }
}
