#include "sort.h"

/**
 * swap - This function swap the values of array
 * @a: 1st value.
 * @b: 2nd value
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heap - Changes a binary tree into a max heap.
 * @array: Array representing the binary tree.
 * @size: Array size.
 * @first: Index of the first row.
 * @index: Index of the root node.
 */
void max_heap(int *array, size_t size, size_t first, size_t index)
{
	size_t j, k, max_idx;

	j = 2 * index + 1;
	k = 2 * index + 2;
	max_idx = index;

	if (j < first && array[j] > array[max_idx])
		max_idx = j;
	if (k < first && array[k] > array[max_idx])
		max_idx = k;

	if (max_idx != index)
	{
		swap(&array[index], &array[max_idx]);
		print_array(array, size);
		max_heap(array, size, first, max_idx);
	}
}

/**
 * heap_sort - Sorts an array of integers using
 * the heap sort.
 * @array: Array of integers.
 * @size: Array size.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
}
