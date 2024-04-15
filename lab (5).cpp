#include <vector>
#include <iostream>
#include <stdlib.h>

void VectorPrint(const std::vector<std::vector<int>>& vect)
{
    for(const auto& row : vect)
    {
        for(int num : row)
            std::cout << num << " ";
        std::cout << "\n";
    }
            // for (int i = 0; i < numRows; ++i) 
        // {
        //     for (int j = 0; j < k; ++j) 
        //         std::cout << b[i][j] << " ";
        //     std::cout << std::endl;
        // }
}

int main()
{
    //1
    {
        int k=7, m=10;
        std::vector<int> a(m);

        for(int &i : a)
            i = rand()%100;
        
        int numRows = m / k;
        if (m % k != 0)
            numRows++;
        
        std::vector<std::vector<int>> b(numRows, std::vector<int>(k, 0));
        int elt = 0;
        for (int i = 0; i < numRows; ++i) 
            for (int j = 0; j < k; ++j) 
                if (elt < m) 
                    b[i][j] = a[elt++];

        VectorPrint(b);

        std::cout << "\n\n";
    }

    //2
    {
        int n=12;
        std::vector<std::vector<int>> a(n);

        for (int i = 0; i < n; ++i) 
        {
            a[i].resize(i + 1);
            for (int j = 0; j <= i; ++j) 
                a[i][j] = (i + 1) * (j + 1);
        }

        VectorPrint(a);

    }
    return 0;
}