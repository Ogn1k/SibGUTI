#include <iostream>
#include <locale.h>
#include <vector>
#include <sstream>

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

int main()
{
    setlocale(LC_ALL, "");
    std::vector<float> a;
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

    return 0;
}