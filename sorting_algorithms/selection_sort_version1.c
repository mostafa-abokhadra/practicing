#include <stdio.h>

int main()
{
		int arr[] = {10, 2, 3, 4, 9, 8, 5, 6, 4,33}, t, num;
		long unsigned int i, j, lowest_ind = 0;

		for (i = 0; i < sizeof(arr) / sizeof(arr[0]) ; i++)
			printf("%d ", arr[i]);
		printf("\n");

		for (i = 0; i < sizeof(arr) / sizeof(arr[0]) ; i++)
		{
			num = arr[i];
			for (j = i ; j < sizeof(arr) / sizeof(arr[0]) ; j++)
				if (arr[j] < num)
				{
					num = arr[j];
					lowest_ind = j;
				}
			if (num != arr[i])
			{
				t = arr[i];
				arr[i] = arr[lowest_ind];
				arr[lowest_ind] = t;
			}
		}

		for (i = 0 ; i < sizeof(arr) / sizeof(arr[0]); i++)
			printf("%d ", arr[i]);
		printf("\n");
		return (0);
}
