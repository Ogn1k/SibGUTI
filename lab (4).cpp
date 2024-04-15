#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <cmath>

void VectorPrint(const std::vector<std::vector<int>>& vect)
{
    for(const auto& row : vect)
    {
        for(int num : row)
            std::cout << num << " ";
        std::cout << "\n";
    }
}

void VectorRand(std::vector<std::vector<int>>& vect)
{
    for (int i = 0; i < vect.size(); ++i) 
        for (int j = 0; j < vect[0].size(); ++j) 
            vect[i][j] = rand() % 101;
}

int main()
{
    srand(time(nullptr));
    //1 
    {
        int n = 5, m = 5, xmax=0, ymax=0;
        std::vector<std::vector<int>> b(m, std::vector<int>(n));
        std::vector<std::vector<int>> c(m-1, std::vector<int>(n-1));
        int max=b[0][0]; 

        VectorRand(b);
        VectorPrint(b);
        
        std::cout << std::endl;

        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                if (b[i][j] > max) {
                    max = b[i][j];
                    xmax = i;
                    ymax = j;
                }
            }
        }
    
        int newRow = 0;
        for (int i = 0; i < b.size(); ++i) 
        {
            if (i == xmax) continue;
            int newCol = 0;

            for (int j = 0; j < b[0].size(); ++j) 
            {
                if (j == ymax) continue; 
                c[newRow][newCol++] = b[i][j];
            }
            ++newRow;
        }

        VectorPrint(c);
    }
    std::cout << std::endl;
    //2
    {
        int m=5, n=5;
        std::vector<std::vector<int>> a(m, std::vector<int>(n+1));
        std::vector<std::vector<int>> d(m+1, std::vector<int>(n+1));
        
        VectorRand(a);
        VectorPrint(a);
        std::cout << std::endl;

        for(int i=0; i<m;++i)
            for(int j=0;j<n;++j)
                d[i][j]=a[i][j];
        
        for (int i = 0; i < m; ++i) 
        {
            int rs = 0;
            for (int j = 0; j < n; ++j) 
                rs += a[i][j];
            d[i][n] = rs;
        }

        for (int j = 0; j < n; ++j) 
        {
        int cs = 0;
        for (int i = 0; i < m; ++i) 
            cs += a[i][j];
        d[m][j] = cs; 
        }

        int ts = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) 
                ts += a[i][j];
        }
        d[m][n] = ts;

        VectorPrint(d);
    }
    return 0;
}