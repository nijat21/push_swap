#include "push_swap.h"

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    int j = start;

    while (j <= end - 1)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    return i;
}

void quick_sort(int *arr, int start, int end)
{
    if (end <= start)
        return;

    int pivot = partition(arr, start, end);

    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot + 1, end);
}

int *list_to_arr(node *stack, int size)
{
    int i;
    int *arr;

    if (!stack)
        return (0);
    arr = malloc(sizeof(int) * size);
    i = 0;
    while (i < size && stack)
    {
        arr[i] = stack->data;
        stack = stack->next;
        i++;
    }
    return arr;
}

int find_median(node *stack, int size, int denom, int **medians)
{
    int median;
    int *arr;
    int i;
    int j;

    i = 0;
    j = 1;
    arr = list_to_arr(stack, size);
    quick_sort(arr, 0, size - 1);
    while (i < denom && j < denom)
    {
        // printf("Iside %d\n", (size * j / denom));
        (*medians)[i] = arr[size * j / denom];
        i++;
        j++;
    }
    median = arr[(size / denom)];
    free(arr);
    arr = NULL;
    return median;
}
