// #include "push_swap.h"

// #include "push_swap.h"

// void handle_small_stack(node **src, node **dst, int size, int *pushed)
// {
//     if (!src || !(*src))
//         return;
//     if (size == 2)
//     {
//         if (*src && (*src)->next && (*src)->data < (*src)->next->data)
//         {
//             swap_first_two(src);
//             ft_putstr_fd("sb\n", 1);
//         }
//         push_to_stack(src, dst);
//         ft_putstr_fd("pa\n", 1);
//         (*pushed)++;
//     }
//     push_to_stack(src, dst);
//     ft_putstr_fd("pa\n", 1);
//     (*pushed)++;
// }

// // Helper function to find the best element to push
// static int find_best_push(node *src, int median)
// {
//     node *current = src;
//     int best_pos = -1;
//     int pos = 0;
//     int min_distance = INT_MAX;

//     while (current)
//     {
//         if (current->data > median)
//         {
//             // Find element closest to median but still greater
//             int distance = current->data - median;
//             if (distance < min_distance)
//             {
//                 min_distance = distance;
//                 best_pos = pos;
//             }
//         }
//         pos++;
//         current = current->next;
//     }
//     return best_pos;
// }

// void b_partition(node **src, node **dst, int partition_size, int *pushed)
// {
//     int median;
//     int count_bigger;
//     int rotations = 0;
//     int best_pos;

//     median = find_median(*src, partition_size, &count_bigger);
//     count_bigger = partition_size - count_bigger - 1;

//     while (*src && *pushed < count_bigger)
//     {
//         best_pos = find_best_push(*src, median);
//         if (best_pos == -1)
//             break;

//         // Optimize rotations by choosing shortest path
//         if (best_pos <= partition_size / 2)
//         {
//             while (best_pos--)
//             {
//                 rotate_stack(src);
//                 ft_putstr_fd("rb\n", 1);
//                 rotations++;
//             }
//         }
//         else
//         {
//             while (best_pos < partition_size)
//             {
//                 rev_rotate_stack(src);
//                 ft_putstr_fd("rrb\n", 1);
//                 best_pos++;
//             }
//         }

//         push_to_stack(src, dst);
//         ft_putstr_fd("pa\n", 1);
//         (*pushed)++;
//         partition_size--;
//     }

//     // Optimize restoration of stack position
//     int restore_rotations = rotations % partition_size;
//     if (restore_rotations > partition_size / 2)
//         restore_rotations = partition_size - restore_rotations;

//     while (restore_rotations--)
//     {
//         rev_rotate_stack(src);
//         ft_putstr_fd("rrb\n", 1);
//     }
// }

// void back_to_a(node **src, node **dst, int *sizes, int *index)
// {
//     int current_partition_size;
//     static int pushed;
//     int leftover = 0;

//     current_partition_size = sizes[(*index) - 1];

//     if (current_partition_size <= 2)
//     {
//         handle_small_stack(src, dst, current_partition_size, &pushed);
//     }
//     else
//     {
//         b_partition(src, dst, current_partition_size, &pushed);
//     }

//     leftover = current_partition_size - pushed;

//     if (leftover > 0)
//     {
//         sizes[(*index) - 1] = leftover;
//         pushed = 0;
//         back_to_a(src, dst, sizes, index);
//     }
//     else
//     {
//         (*index)--;
//         pushed = 0;
//         if ((*index) - 1 >= 0)
//             back_to_a(src, dst, sizes, index);
//     }
// }