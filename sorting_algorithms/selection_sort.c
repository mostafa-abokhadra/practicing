#include <stdio.h>

int main()
{
		int arr[] = {5, 6, 7, 3, 4, 9, 10, 2, 17, 1}, t;
		long unsigned int i, j;

		for (i = 0; i < sizeof(arr) / sizeof(arr[0]) ; i++)
		{
			for (j = 0; j < sizeof(arr) / sizeof(arr[0]) ; j++)
			{
				if (arr[j] > arr[i])
				{
					t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
		}

		for (i = 0 ; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return (0);
}
