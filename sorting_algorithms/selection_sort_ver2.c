#include <stdio.h>

int main()
{
		int arr[] = { 9}, t;
		long unsigned int i, j, low_idx;

		for (i = 0; i < sizeof(arr) / sizeof(arr[0]) ; i++)
		{
			low_idx = i;
			for (j = i + 1 ; j < sizeof(arr) / sizeof(arr[0]) ; j++)
				if (arr[j] < arr[low_idx])
					low_idx = j;
			if (low_idx != i)
			{
				t = arr[i];
				arr[i] = arr[low_idx];
				arr[low_idx] = t;
			}
		}

		for (i = 0; i < sizeof(arr) / sizeof(arr[0]) ; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return (0);

}
