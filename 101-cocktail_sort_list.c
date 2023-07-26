#include "sort.h"

/**
 * swap_front_node - Swaps a node in a doubly-linked list
 * with the node in front of it.
 * @list: Head pointer.
 * @tail: Tail pointer.
 * @curr: A pointer to the curr swapping node
 */
void swap_front_node(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->next;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*curr)->prev;
	(*curr)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *curr;
	else
		*tail = *curr;
	(*curr)->prev = temp;
	temp->next = *curr;
	*curr = temp;
}

/**
 * swap_back_node - Swaps a node in a doubly-linked
 * list with the node at the back of it.
 * @list: A pointer to the head of a doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr: A pointer to the current swapping node
 */
void swap_back_node(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*curr)->next;
	(*curr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *curr;
	else
		*list = *curr;
	(*curr)->next = temp;
	temp->prev = *curr;
	*curr = temp;
}

/**
 * cocktail_sort_list - Sorts a doubly-linked list of
 * integers using cocktail sort
 *
 * @list: A pointer to the head of a doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *curr;
	int shaken_not_stirred = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (!shaken_not_stirred)
	{
		shaken_not_stirred = true;
		for (curr = *list; curr != tail; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_front_node(list, &tail, &curr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (curr = curr->prev; curr != *list; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_back_node(list, &tail, &curr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
