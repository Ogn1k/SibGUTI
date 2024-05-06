// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

const int size = 10;

void FillInc(int arr[])
{
    for(int i = 0; i<size; i++)
    {
        arr[i] = i;
    }
}

void FillDec(int arr[])
{
    for(int i = 0; i<size; i++)
    {
        arr[i] = size - i; 
    }
}

void FillRand(int arr[])
{
    for(int i =0; i<size; i++)
    {
        arr[i] = rand() % 100 +1;
    }
}

void CheckSum(int arr[])
{
    int b = 0;
    for(int i = 0; i<size; i++)
    {
        b += arr[i];
    }
    printf("\n%d\n", b);
}

void RunNumber(int arr[])
{
    int maxS = 1;
    for(int i = 0; i<size-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            maxS +=1;
        }
    }
    printf("\n%d \n", maxS);
}

void PrintMas(int arr[])
{
    for(int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void SelectSort(int A[], int arrSize)
{
	int i, j, min, temp, moves = 0, comps = 0;
	for (i = 0; i < arrSize - 1; i++)
	{
		min = i;
		for (j = i + 1; j < arrSize; j++)
		{
			comps++;
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		moves += 3;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
	printf("\n: %d\n : %d \n", comps, moves);
}

void SelectSortModified(int A[], int arrSize)
{
	int i, j, min, temp, moves = 0, comps = 0;
	for (i = 0; i < arrSize - 1; i++)
	{
		min = i;
		for (j = i + 1; j < arrSize; j++)
		{
			comps++;
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			moves += 3;
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
	printf("\n: %d\n : %d \n", comps, moves);
}

int main() {
    
    int A[size];
    int arr[size];
    
    srand(time(NULL));

    FillDec(arr);
    PrintMas(arr);
    RunNumber(arr);
    CheckSum(arr);
    
    SelectSortModified(arr, size);

    PrintMas(arr);
    RunNumber(arr);
    CheckSum(arr);

    // FillInc(A);
    // CheckSum(A);
    // std::cout << "\n";
    // PrintMas(A);
    // std::cout << "\n";
    // RunNumber(A);
    
    // std::cout << "\n\n";

    // FillDec(A);
    // CheckSum(A);
    // std::cout << "\n";
    // PrintMas(A);
    // std::cout << "\n";
    // RunNumber(A);
    
    // std::cout << "\n\n";

    // FillRand(A);
    // CheckSum(A);
    // std::cout << "\n";
    // PrintMas(A);
    // std::cout << "\n";
    // RunNumber(A);



    return 0;
}

