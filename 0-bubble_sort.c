#include "sort.h"

/**
 * swap_ints - Exchange the positions of two integers within an array.
 * @a: The first integer to exchange.
 * @b: The second integer to exchange.
*/

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorting algorithm that sorts an array in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
*/

void bubble_sort(int *array, size_t size)
{
	size_t k, flag, i, temp;

	if (array == NULL || size < 2)
		return;

	for (k = 1; k <= size - 1; k++)
	{
		flag = 0;
		for (i = 0; i <= size - k - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)

			break;
	}
}
