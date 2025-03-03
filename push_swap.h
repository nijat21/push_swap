#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"
#include <limits.h>

typedef struct s_node
{
    int data;
    struct s_node *prev;
    struct s_node *next;
} node;

// Format input and checks
node *
format_input(int ac, char **av);
int is_valid(int num, char *str, node **head);

// Sort operations
void swap_first_two(node **stack, char vocal);
void push_to_stack(node **src, node **dst, char vocal);
void rotate_stack(node **stack, char vocal);
void rev_rotate_stack(node **stack, char vocal);

// Helper functions
int count_nums(char *str);
int count_nodes(node *stack);
int find_median(node *stack, int size, int *count);
void free_stack(node **stack);
void free_arr(char ***str);
int find_max(node *src);

// Specific node counts
void handle_two(node **src, node **dst, int size, int *pushed);
void handle_three_nodes(node **src, node **dst, int *pushed);

// Simplified sort
void final(node **stack);
void to_b(node **src, node **dst, int *sizes, int *index);
void back_to_a(node **src, node **dst, int *sizes, int *index);
int is_sorted(node *stack);

void quicksort_stack(node **stack_a, node **stack_b, int size);

#endif