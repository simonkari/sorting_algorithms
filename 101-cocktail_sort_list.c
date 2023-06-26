#include "sort.h"

/**
 * list_len - Computes the length of a linked list.
 * @list: The head of the linked list.
 * Return: The length of the list.
*/

size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}

	return (len);
}

/**
 * switch_nodes - Swaps a node at the given pointer
 * with the following node in a linked list.
 * @list: The head of the linked list.
 * @p: Pointer to the node to be swapped.
*/

void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;

	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;

	if (one)
		one->next = three;

	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using the cocktail sort algorithm.
 * @list: Pointer to the head of the list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;

	while (!sorted)
	{
		sorted = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorted = 0;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}

		if (sorted)
			break;
		p = p->prev;

		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorted = 0;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}

			else
				p = p->prev;
		}
	}
}
