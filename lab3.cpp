#include <iostream>
#include <locale.h>
#include <vector>
#include <sstream>
#include <algorithm>

bool isFloat(const std::string& str) 
{
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f; 
    return iss.eof() && !iss.fail();
}

float stringToFloat(const std::string& str) 
{
    std::istringstream iss(str);
    float result;
    iss >> std::noskipws >> result; 
    return result;
}

bool Next_p(std::vector<int>& arr, int n)
{
    int k = n-2;
    while(k>=0 && arr[k] >= arr[k+1])
    {
        k-=1;
        if(k==-1) return false;
    }
    int l = n-1;
    while(arr[k] >= arr[l])
        l-=1;
    std::swap(arr[k], arr[l]);
    std::reverse(arr.begin(), arr.end());
    return true;
}

int main()
{
    setlocale(LC_ALL, "");
    std::vector<int> a;
    std::string aa = "";
    
    std::cout << "enter array\n";
    while(aa != "end")
    {
        std::cin >> aa;
        if(isFloat(aa))
        {
            a.insert(a.begin(), stringToFloat(aa));
        }
    }
    std::sort(a.begin(), a.end());

    do
    {
        for(int n : a) std::cout << n << " ";
        std::cout << "\n";
    }
    while(Next_p(a,a.size()));
    return 0;
}