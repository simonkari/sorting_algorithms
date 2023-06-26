#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, int left, int right);
void quick_sort(int *array, int left, int right);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers according to
 *                   the Hoare partition scheme (middle element as pivot).
 * @array: The array of integers.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, int left, int right)
{
    int pivot = array[left];
    int i = left - 1;
    int j = right + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_ints(&array[i], &array[j]);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order using
 *              the quicksort algorithm.
 * @array: An array of integers.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme and an iterative
 *              implementation of the quicksort algorithm.
 */
void quick_sort(int *array, int left, int right)
{
    if (left < right)
    {
        int partition = hoare_partition(array, left, right);
        quick_sort(array, left, partition);
        quick_sort(array, partition + 1, right);
    }
}
