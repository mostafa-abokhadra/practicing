#include <stdio.h>

int main()
{
		int arr[] = {0, 1, 0, 33, 3333, 0, 0 ,0}, t;
		long unsigned int i, j;

		for (i = 0 ; i < sizeof(arr) / sizeof(arr[0]) ; i++)
		{
			if (i + 1 < sizeof(arr) /sizeof(arr[0]) &&
					arr[i + 1] < arr[i])
			{
				t = arr[i + 1];
				for (j = i; (int)j >= 0; j--)
				{
					if (arr[j] > t)
					{
						arr[j + 1] = arr[j];
						continue;
					}
					break;
				}
				arr[j + 1] = t;
			}
		}
		for (i = 0; i < sizeof(arr) / sizeof(arr[0]) ; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return (0);
}
