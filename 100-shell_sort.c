#include "sort.h"
/**
 * swap - This function swaps the value of the array.
 * @a: 1st value.
 * @b: 2nd value.
 * Return: void.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * shell_sort - Sorts an array of integers
 * using the shell sort
 * @array: The array.
 * @size: Array size.
 */
void shell_sort(int *array, size_t size)
{
	size_t increment, i, j;

	if (array == NULL || size < 2)
		return;

	for (increment = 1; increment < (size / 3);)
		increment = increment * 3 + 1;

	for (; increment >= 1; increment /= 3)
	{
		for (i = increment; i < size; i++)
		{
			j = i;
			while (j >= increment && array[j - increment] > array[j])
			{
				swap(array + j, array + (j - increment));
				j -= increment;
			}
		}
		print_array(array, size);
	}
}
