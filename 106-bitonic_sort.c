#include "sort.h"
/**
 * bitonic_merge - Sorts and merges a sequence of elements
 * in either ascending or descending order.
 * @array: The array to be sorted and merged.
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: ascending or descending
 */

void bitonic_merge(int *array, int l, int r, int direction)
{
int tmp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

if (r - l >= 1)
{
	for (i = l; i < l + mid; i++)
	{
		if (direction == (array[i] > array[i + mid]))
		{
			tmp = array[i + mid];
			array[i + mid] = array[i];
			array[i] = tmp;
		}
	}
	bitonic_merge(array, l, step, direction);
	bitonic_merge(array, step + 1, r, direction);
}

}

/**
 * bitonic_recursion - Recursive function for the
 * bitonic sort algorithm.
 * @array: The array to be sorted.
 * @l: The index of the leftmost element.
 * @r: The index of the rightmost element.
 * @direction: The sorting direction (ascending
 * or descending).
 * @size: The size of the array.
 */

void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
int step;

if (r - l >= 1)
{
	step = (r + l) / 2;
	printf("Merging [%d/%lu] ", r - l + 1, size);
	if (direction)
		printf("(UP):\n");
	else
		printf("(DOWN):\n");
	print_array(array + l, r - l + 1);
	bitonic_recursion(array, l, step, 1, size);
	bitonic_recursion(array, step + 1, r, 0, size);
	bitonic_merge(array, l, r, direction);
	printf("Result [%d/%lu] ", r - l + 1, size);
	if (direction)
		printf("(UP):\n");
	else
	printf("(DOWN):\n");
	print_array(array + l, r - l + 1);
}
}

/**
 * bitonic_sort - Sorts an array of integers using the
 * Bitonic sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: size of the array
 */

void bitonic_sort(int *array, size_t size)
{
if (!array || size < 2)
	return;

bitonic_recursion(array, 0, size - 1, 1, size);
}
