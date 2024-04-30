#include <locale.h>
#include <string>
#include <iostream>
#include <sstream>  
#include <vector>
#include <set>
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

bool IsReflexive(const std::vector<std::pair<float, float>>& R, const std::vector<float>& A) 
{
    for (float elem : A) 
    {
        bool found = false;
        for (const auto& pair : R) 
        {
            if (pair.first == elem && pair.second == elem) 
            {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool IsSymmetric(const std::vector<std::pair<float, float>>& R) 
{
    for (const auto& pair : R) 
    {
        std::pair<float, float> inversePair = std::make_pair(pair.second, pair.first);
        if (std::find(R.begin(), R.end(), inversePair) == R.end()) return false;
    }
    return true;
}

bool IsAntiSymmetric(const std::vector<std::pair<float, float>>& R) 
{
    for (const auto& pair : R) 
    {
        if (pair.first != pair.second && 
            std::find(R.begin(), R.end(), 
            std::make_pair(pair.second, pair.first)) != R.end()) 
            return false;
    }
    return true;
}

bool IsTransitive(const std::vector<std::pair<float, float>>& R) 
{
    for (const auto& pair1 : R) 
    {
        for (const auto& pair2 : R) 
        {
            if (pair1.second == pair2.first) 
            {
                std::pair<float, float> transitivePair = std::make_pair(pair1.first, pair2.second);
                if (std::find(R.begin(), R.end(), transitivePair) == R.end()) 
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "");
    std::vector<float> a = {1, 2, 3, 4, 5, 6};
    std::string aa = "";

    std::vector<std::pair<float, float>> R = {{1, 2}, {3, 4}, {5, 6}};
    std::string ab = "", ba = "";

    // std::cout << "enter array\n";
    // while(aa != "end")
    // {
    //     std::cin >> aa;
    //     if(isFloat(aa))
    //     {
    //         a.insert(a.begin(), stringToFloat(aa));
    //     }       
    // }

    // std::cout << "enter pairs\n";
    // int i =0;
    // while(ab != "end" || ba != "end")
    // {
    //     std::cin >> ab >> ba;
    //     if(isFloat(ab))
    //     {
    //         R[i].first == stringToFloat(ab);
    //         R[i].second == stringToFloat(ba);
    //     }       
    // }
    std::sort(a.begin(), a.end());

    for (int i = 0; i < R.size(); ++i) {
        std::cout << "(" << R[i].first << ", " << R[i].second << ")\n";
    }
    printf("рефлективность: %s\n", IsReflexive(R, a) ? "true" : "false");
    printf("симметричность: %s\n", IsSymmetric(R) ? "true" : "false");
    printf("антисимметричность: %s\n", IsAntiSymmetric(R) ? "true" : "false");
    printf("транзитивность: %s\n", IsTransitive(R) ? "true" : "false");
    
    return 0;
}