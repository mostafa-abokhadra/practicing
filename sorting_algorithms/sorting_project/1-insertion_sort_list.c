#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
		int flag = 1, flag2 = 0;
		listint_t *ptr, *to_sort;

		if (!(*list) || (*list)->next == NULL)
			return;
		ptr = to_sort = (*list)->next;

		while (flag)
		{
			printf("in\n");
			flag = 0;
			flag2 = 0;
			
			while (to_sort != NULL && ptr->prev->n > to_sort->n)
			{
				printf("in2 ");
				ptr = ptr->prev;
				if (ptr->prev == NULL)
				{
					to_sort->prev->next = to_sort->next;
					to_sort->next->prev = to_sort->prev;
					to_sort->next = ptr;
					ptr->prev = to_sort;
					to_sort->prev = NULL;
					*(list) = to_sort;

					printf("%d\n", to_sort->n);

					to_sort = ptr->next;
					ptr = to_sort;

					if (to_sort == NULL)
					printf("here");

					ptr = to_sort;
					flag2 = 1;
					flag = 0;
					break;
				}
				flag = 1;
			}
			if (flag)
			{
				ptr->next = to_sort->next;
				to_sort->next->prev = ptr;
				to_sort->prev = ptr->prev;
				ptr->prev = to_sort;
				to_sort->next = ptr;
				ptr->prev = to_sort;
			}
			if (!flag2)
			{
				to_sort = to_sort->next;
				ptr = to_sort;	
				flag = 1;
			}
			if (flag2)
			{
				flag = 1;
			printf("why\n");}
		}
}
