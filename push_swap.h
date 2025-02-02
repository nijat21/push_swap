#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"

typedef struct s_node
{
    int data;
    struct s_node *prev;
    struct s_node *next;
} node;

// Format input and checks
node *format_input(int ac, char **av);
int check_for_numeric(char *str);
int check_duplicate(int num, node *list);
void clear_list(node *list);
int list_size(node *list);

// Sort operations
void swap_first_two(node **stack);
void push_to_stack(node **src, node **dst);
void rotate_stack(node **stack);
void rev_rotate_stack(node **stack);

// Helper functions
int count_nums(char *str);
int count_nodes(node *stack);
int find_median(node *stack);

// Simplified sort
void sort(node **stack);

#endif