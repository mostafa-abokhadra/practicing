#include "sort.h"
#include <stdio.h>

/**
 * sort_front - sorting a node
 *
 * @head: head of list
 * @to_sort: node to be sorted
 * @ptr2: flag node to change positions
 *
 * Description: if the node should be the first element
 *
 * Return: nothing
 */
void sort_front(listint_t **head __attribute__((unused)),
		listint_t *to_sort, listint_t *ptr2)
{
		to_sort->prev->next = to_sort->next;
		if (to_sort->next != NULL)
			to_sort->next->prev = to_sort->prev;
		to_sort->next = ptr2;
		ptr2->prev = to_sort;
		to_sort->prev = NULL;
		*(head) = to_sort;
		print_list(*head);
}

/**
 * sort_any_where - sorting a node
 *
 * @to_sort: node to be sorted
 * @ptr2: flag pointer
 *
 * Description: if the node should be between other nodes
 *
 * Return: nothing
 */
void sort_any_where(listint_t *to_sort, listint_t *ptr2)
{
		ptr2->prev->next = to_sort;
		if (to_sort->next != NULL)
		{
			to_sort->next->prev = to_sort->prev;
			to_sort->prev->next = to_sort->next;
		}
		if (to_sort->next == NULL)
			to_sort->prev->next = NULL;
		to_sort->prev = ptr2->prev;
		to_sort->next = ptr2;
		ptr2->prev = to_sort;
}

/**
 * insertion_sort_list - sorting a list
 *
 * @list: list to be sorted
 *
 * Description: entry point of sorting
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
		listint_t *ptr, *ptr2, *to_sort;
		bool sort_occur = false;

		if (!(*list) || (*list)->next == NULL)
			return;
		ptr = (*list);
		while (ptr->next != NULL)
		{

			if (ptr->next->n >= ptr->n)
				ptr = ptr->next;
			else
			{
				ptr2 = to_sort = ptr->next;
				sort_occur = true;
				ptr = ptr->next->next;
				while (ptr2->prev != NULL &&
						ptr2->prev->n > to_sort->n)
					ptr2 = ptr2->prev;
			}
			if (sort_occur)
			{
				if (ptr2->prev == NULL)
					sort_front(list, to_sort, ptr2);
				else
				{
					sort_any_where(to_sort, ptr2);
					print_list(*list);
				}
			}
			if (sort_occur)
			{
				if (ptr != NULL)
					ptr = ptr->prev;
				else
					break;
			}
			sort_occur = false;
		}
}
