#include "sort.h"
/**
 * partition - Finds the pivot index for the Quicksort algorithm.
 * @array: The array to find the pivot in.
 * @left: The index of the left element.
 * @right: The index of the right element.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */

int partition(int *array, int left, int right, size_t size)
{
int tmp, pivot = array[right];
size_t i, j;

i = left - 1;
j = right + 1;
while (1)
{
	do {
		i++;
	} while (array[i] < pivot);
	do {
		j--;
	} while (array[j] > pivot);
	if (i >= j)
		return (i);
	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
return (0);
}

/**
 * quick_recursion - Helper function for the
 * Quicksort algorithm.
 * @array: The array to be sorted.
 * @left: The index of the left element.
 * @right: The index of the right element.
 * @size: The size of the array.
 */

void quick_recursion(int *array, int left, int right, size_t size)
{
int piv;

if (left < right)
{
	piv = partition(array, left, right, size);
	quick_recursion(array, left, piv - 1, size);
	quick_recursion(array, piv, right, size);
}
}

/**
 * quick_sort_hoare - Sorts an array of integers using the
 * Quicksort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
if (!array || size < 2)
	return;

quick_recursion(array, 0, (int)size - 1, size);
}
