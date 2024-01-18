#include <stdio.h>

void swap(int *num1, int *num2)
{
		int temp;

		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
}
int main()
{

		int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2,1};
		long unsigned int i;

		for (i = 0 ; i < sizeof(arr) / sizeof(arr[0]) ; i++)
		{
			if (i + 1 < sizeof(arr) / sizeof(arr[0]) &&
					arr[i + 1] < arr[i])
			{
				swap(&arr[i], &arr[i + 1]);
				i = -1;
			}
		}

		for (i = 0; i < sizeof(arr) / sizeof(arr[0]) ; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return (0);
}
