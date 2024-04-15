#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "myvector.cpp"
#include <cmath>

myvector<int> prime( int n)
{
    myvector<int> si;
    myvector<bool> sb(n+1, true);

    for (int i = 2; i * i <= n; i++) 
       if (sb[i] == true) 
        {
            si.push(i);
            for (int j = i * i; j <= n; j += i)
                sb[j] = false;
        }

    for (int i = 2; i <= n; i++)
        if (sb[i])
            si.push(i);

    return si;
}

int main()
{
    srand(time(NULL));
    //1
    // {
    // int n;
    // scanf("%d", &n);
    // myvector<int> b(n);
    // myvector<int> c;
    // myvector<int> d;
    // for(int i=0,j=0,k=0; i<n;i++)
    // {
    //     b.push(rand() % 100 - 50);
    //     printf("b: %d\n", b.get(i));
    //     if(b.get(i)>0)
    //     {
    //         c.push(b.get(i));
    //         printf("c: %d\n", c.get(j));
    //         j++;
    //     }
    //     else
    //     {
    //         d.push(b.get(i));
    //         printf("d: %d\n", d.get(k));
    //         k++;
    //     }
    // }
    // b.rmVec();
    // c.rmVec();
    // d.rmVec();
    // }

    //2
    // {
    //     int n;
    //     scanf("%d", &n);
    //     int * a = new int[n];
    //     int ** b = new int*[n];

    //     for (int i = 0; i < n; ++i) 
    //     {
    //         a[i] = rand()% 200 - 100;
    //         b[i] = &a[i];
    //     }

    //     std::sort(b,b+n,[](const int* lhs, const int* rhs){ return *lhs < *rhs; });

    //     for (int i = 0; i < n; ++i) 
    //     {
    //         printf("a: %d\n", a[i]);
    //         printf("b: %d\n", *b[i]);
    //     }
    // }

    //3
    {
        int n;
        scanf("%d", &n);
        myvector<int> a = prime(n);
        
        for(int i=0;i<a.size();i++)
           printf("%d ", a[i]);
        
    }
    return 0;
}