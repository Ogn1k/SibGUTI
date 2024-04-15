#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>

void FillRand(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        arr[i] = rand()% 1000 - 500;
    }
}

void ArrNuller(int n, int *arr)
{
    int min1=99, min2=99, in1, in2;
    for(int i=0; i<n; i++)
    {
        if(min1>arr[i])
        {
            min2=min1;
            min1=arr[i];
            in2=in1;
            in1=i;
        }
        else if(min2>arr[i])
        {
            min2=arr[i];
            in2=i;
        }
    }

    int start = std::min(in1, in2) + 1;
    int end = std::max(in1, in2);

    arr[start-1]=1;
    arr[end]=1;
    for(int i=start; i<end; i++)
    {
        arr[i]=0;
    }
    std::cout << min1 << " " << min2 << std::endl;
}

void VectorPrint(const std::vector<std::vector<int>>& vect)
{
    for(const auto& row : vect)
    {
        for(int num : row)
            std::cout << num << " ";
        std::cout << "\n";
    }
}

std::vector<int> RowSum(const std::vector<std::vector<int>> &arr)
{
    std::vector<int> s;
    for(const auto &row : arr)
    {
        int sum = 0;
        for (int i = 1; i <= row[0]; ++i) 
            sum += row[i];
        s.push_back(sum);
    }
    return s;
}

void QSort(int *arr, int size)
{
    int i=0, j=size-1;
    int mid=arr[size/2];

    do
    {
        while(arr[i]>mid)
            i++;

        while(arr[j]<mid)
            j--;

        if(i<=j)
        {
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;

            i++;
            j--;
        }
    } while (i<=j);

    if(j>0)
        QSort(arr,j+1);

    if(i<size)
        QSort(&arr[i], size-i);
}

int SelectFind(int *arr, int size, int num)
{
    int c=0;
    for(int i=0; i<size;i++)
    {
        c++;
        if(arr[i]==num)
            return c;
    }
    return -1;
}

int BinaryFind(int *arr, int size, int num)
{
    int c=0;
    int left=0, right=size-1;

    while(left<=right)
    {
        c++;
        int mid=left+(right-left)/2;

        if(arr[mid]==num)
            return c;

        if(arr[mid]<num)
            left=mid+1;
        else
            right = mid-1;
    }
}

int main()
{
    srand(time(NULL));
    //1
    {
        const int n = 10;
        int array[n];
        FillRand(array, n);
        for(const int &i : array) std::cout << i << " ";
        std::cout << std::endl;
        ArrNuller(n, array);
        for(const int &i : array) std::cout << i << " ";
        std::cout << "\n\n";
    }
    // //2
    // {
    //     int n=5;
    //     std::vector<std::vector<int>> a(n);

    //     for (int i = 0; i < n; ++i) 
    //     {
    //         int rl = rand() % 9 + 2; 
    //         a[i].push_back(rl); 
    //         for (int j = 0; j < rl; ++j) 
    //             a[i].push_back(rand() % 100); 
    //     }
    //     VectorPrint(a);
    //     std::vector<int> rs = RowSum(a);
    //     for (int i = 0; i < n; ++i)
    //         std::cout << rs[i] << " ";
    //     std::cout << "\n\n";
    // }
    // //3
    // {
    //     int mobPsiho100[100];
    //     int mobPsiho1000[1000];
    //     FillRand(mobPsiho100, 100);
    //     FillRand(mobPsiho1000, 100);
    //     QSort(mobPsiho100, 100);
    //     QSort(mobPsiho1000, 1000);
    //     std::cout << SelectFind(mobPsiho100, 100, mobPsiho100[70]) << std::endl;
    //     std::cout << SelectFind(mobPsiho1000, 1000, mobPsiho1000[700]) << std::endl;
    // }
}