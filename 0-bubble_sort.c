#include "sort.h"
/**
 * swap - This function swaps the values of array
 * @a: 1st value
 * @b: 2nd value
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * bubble_sort - This sorts array elements
 * @array: Array
 * @size: Array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL && size == 0)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
