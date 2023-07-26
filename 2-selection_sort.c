#include "sort.h"

/**
 * swap - Swaps the values of array
 * @a: 1st value
 * @b: 2nd value
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers with selection
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
