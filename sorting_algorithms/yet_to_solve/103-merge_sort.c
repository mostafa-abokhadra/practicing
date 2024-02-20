#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int *merge(int *arr1, size_t size1, int *arr2, size_t size2)
{
		unsigned long int i = 0, j = 0, k = 0;
		int *final_arr = malloc(sizeof(int) *(size1 + size2));

		printf("=======================\n");
		print_array(arr1, size1);
		printf("----\n");
		print_array(arr2, size2);
		printf("========================\n");

		for (i = 0; i < size1; i++, arr1++)
		{
			for (j = 0; j < size2; j++)
			{
				if (*(arr1) <= *(arr2))
				{
					
					final_arr[k] = *(arr1);
					k++;
					arr1++;
					break;
				}
				else
				{
					final_arr[k] = *(arr2);
					k++;
					arr2++;
				}
			}

			if (j == size2)
			{
				for (; i <size1; i++, k++, arr1++)
					final_arr[k] = *(arr1);
				break;
			}
		}
		
		for (; j < size2; j++, arr2++)
			final_arr[k] = *(arr2);

		for (i = 0; i < size1 + size2; i++)
			printf("%d ", final_arr[i]);
		printf("\n====================\n");

		return final_arr;
}

int *merge_sorting(int *array, size_t size)
{
		size_t size1, size2, i;
		int *arr;

		if (!array || size <= 1)
		{
			return array;
		}
		size1 = size / 2;
		size2 = size - (size / 2);
		arr = merge(merge_sorting((array + size1), size2), size2, merge_sorting(array, size1), size1);

		for (i = 0; i < size; i++)
		{
			*array = *(arr);
			arr++;
			array++;
		}
		print_array(array, size);
		printf("===================\n");
		return array;
}

void merge_sort(int *array, size_t size)
{
		merge_sorting(array, size);
}
