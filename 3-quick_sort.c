#include "sort.h"

/**
 * swap - Swaps the value of array.
 * @a: 1st value.
 * @b: 2nd value.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partition
 * @array: The array.
 * @size: Array size.
 * @left: left partition.
 * @right: right partition.
 *
 * Return: Pivot.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, low, high;

	pivot = array + right;
	for (low = high = left; high < right; high++)
	{
		if (array[high] < *pivot)
		{
			if (low < high)
			{
				swap(array + high, array + low);
				print_array(array, size);
			}
			low++;
		}
	}

	if (array[low] > *pivot)
	{
		swap(array + low, pivot);
		print_array(array, size);
	}

	return (low);
}

/**
 * q_sort - sorts the array with quicksort.
 * @array: Array.
 * @size: Array size.
 * @left: left array indexition.
 * @right: right array indexition.
 */
void q_sort(int *array, size_t size, int left, int right)
{
	int index;

	if (right - left > 0)
	{
		index = partition(array, size, left, right);
		q_sort(array, size, left, index - 1);
		q_sort(array, size, index + 1, right);
	}
}

/**
 * quick_sort - Sort an array using quicksort algorithm.
 * @array: Unsorted array.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, size, 0, size - 1);
}
