#include <string>
#include <iostream>

void qsort(int *arr, int n)
{
    int i = 0, j = n - 1;
    int mid = arr[n / 2];
    do 
    {
        while(arr[i] < mid) 
        {
            i++;
        }
        while(arr[j] > mid) 
        {
            j--;
        }
        if (i <= j) 
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) 
    {
        qsort(arr, j + 1);
    }
    if (i < n) 
    {
        qsort(&arr[i], n - i);
    }
}

struct PhoneNum
{
    std::string Name;
    int Number;
};

bool customer_sorter(PhoneNum *lhs, PhoneNum *rhs) 
{
    if (lhs->Name != rhs->Name)
        return lhs->Name < rhs->Name;
    return lhs->Name < rhs->Name;
}

int main()
{
  //srand(time(NULL));
    {
        int n=10;
        PhoneNum * a = new PhoneNum[n];
        PhoneNum ** b = new PhoneNum*[n];

        for (int j = 0, i = n; i > 0; i--, j++) 
        {
            
            a[j] = {"name"+std::to_string(i), rand()% 200 - 100};
            b[j] = &a[j];
        }
        //std::sort(b, b+n, &customer_sorter);
        //std::sort(b,b+n,[](const PhoneNum* lhs, const PhoneNum* rhs){ return *lhs->Name < *rhs->Name; });
        printf("a:");
            for (int i = 0; i < n; ++i) 
            {
                std::cout << a[i].Name << " ";
            }
        printf("\nb:");
        for (int i = 0; i < n; ++i) 
            {
                std::cout << b[i]->Name << " ";
            }
    }

}