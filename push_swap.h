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
int is_valid(int num, char *str, node **head);

// Sort operations
void swap_first_two(node **stack);
void push_to_stack(node **src, node **dst);
void rotate_stack(node **stack);
void rev_rotate_stack(node **stack);
// opps wrappers
void sa(node **stack_a);
void sb(node **stack_b);
void ss(node **stack_a, node **stack_b);
void pa(node **stack_b, node **stack_a);
void pb(node **stack_a, node **stack_b);
void ra(node **stack_a);
void rb(node **stack_b);
void rr(node **stack_a, node **stack_b);
void rra(node **stack_a);
void rrb(node **stack_b);
void rrr(node **stack_a, node **stack_b);

// Helper functions
int count_nums(char *str);
int count_nodes(node *stack);
int find_median(node *stack, int size);
void free_stack(node **stack);
void free_arr(char ***str);

// Simplified sort
void sort(node **stack);
void final(node **stack);

#endif