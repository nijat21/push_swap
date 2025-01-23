#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"

typedef struct s_node
{
    int data;
    struct s_node *prev;
    struct s_node *next;
} node;

void format_input(int ac, char **av);

#endif