#include "sort.h"

/**
 * swap_list - This function swaps two nodes in a list.
 * @head: Head pointer.
 * @a: First node.
 * @b: Second node.
 */
void swap_list(listint_t **head, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*head = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - sorts a list of integers with insertion
 * @list: list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *insert, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (curr = (*list)->next; curr != NULL; curr = temp)
	{
		temp = curr->next;
		insert = curr->prev;
		while (insert != NULL && curr->n < insert->n)
		{
			swap_list(list, &insert, curr);
			print_list((const listint_t *)*list);
		}
	}
}
