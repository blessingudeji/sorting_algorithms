i#include "sort.h"
/**
* merge_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: Array size.
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_array;

	if (array == NULL || size < 2)
		return;

	tmp_array = malloc(sizeof(int) * size);
	if (tmp_array == NULL)
		return;

	merge_sort_recursive(array, tmp_array, 0, size);

	free(tmp_array);
}

/**
 * merge - Sorts subarrays.
 * @array: Array to sort.
 * @tmp_array: A temporary array to store the sorted array.
 * @front: The front index
 * @mid: The middle index
 * @back: The back index
 */
void merge(int *array, int *tmp_array,
		size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[Left]: ");
	print_array(array + front, mid - front);

	printf("[Right]: ");
	print_array(array + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		tmp_array[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		tmp_array[k++] = array[i];
	for (; j < back; j++)
		tmp_array[k++] = array[j];
	for (i = front, k = 0; i < back; i++)
		array[i] = tmp_array[k++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}

/**
 * merge_sort_recursive - Implements the merge sort through recursion
 * @array: The array to sort
 * @tmp_array: A temporary array to store the result.
 * @front: The front index of the array.
 * @back: The back index of the array.
 */
void merge_sort_recursive(int *array, int *tmp_array,
		size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(array, tmp_array, front, mid);
		merge_sort_recursive(array, tmp_array, mid, back);
		merge(array, tmp_array, front, mid, back);
	}
}
