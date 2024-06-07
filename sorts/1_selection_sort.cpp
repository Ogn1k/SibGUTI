#include <stdio.h>

void SelectSort(int A[], int arrSize)
{
	int i, j, min, temp, moves = 0, comps = 0;
	for (i = 0; i < arrSize - 1; i++)
	{
		min = i;
		for (j = i + 1; j < arrSize; j++)
		{
			//comps++;
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		//moves += 3;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
	//printf("\n: %d\n : %d \n", comps, moves);
}