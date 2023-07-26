#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - Sorts an array using counting.
  * @array: The array.
  * @size: Array length.
  * Return: Void.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *count = NULL, j = 0, k = 0;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= k; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (j = 0; j < k; j++)
	{
		count[j + 1] += count[j];
		printf("%d, ", count[j]);
	}
	count[j + 1] += count[j];
	printf("%d\n", count[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = count[array[i]] - 1;
		if (array[i] != array[j])
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}
	free(count);
}
