#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "myvector.cpp"

void FillRand(int arr[], int size)
{
    for(int i =0; i<size; i++)
    {
        arr[i] = rand()% 200 - 100;
    }
}

//1
void func1()
{
    int n;
    scanf("%d", &n); 
    if(n!=0)
        func1();
    
    if(n>0)
        printf("%d\n", n);//можно ли воспользоваться return возвратив числа в таком же формате и обойтись без массива?
}

//2
void func2(int arr[], int ind, int arrSize)
{
    if(ind < arrSize)
    {
        if(arr[ind]<0)
            printf("%d ", arr[ind]);
        func2(arr, ind+1, arrSize);
        if(arr[ind]>0)
            printf("%d ", arr[ind]);
    }
}

//3
void func3(int n)
{
    std::string t;
    if(n>=1)
    {
        if(n%2==0)
            t=t+"0";
        if(n%2==1)
            t=t+"1";
        func3(n/2);
    }
    printf("%s", t.c_str());
}

int main()
{
    srand(time(NULL));
    func1();

    //int a[10];
    //FillRand(a, 10);
    //func2(a, 0, 10);

    //func3(63);
    
    return 0;
}