#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

bool Is_number(const std::string& s) 
{
    return !s.empty() && std::atof(s.c_str());
}

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

bool findValue (const std::vector<int>& data, int value)
{
    auto result{ std::find(begin(data), end(data), value) };
    if (result == end(data))
        return false;
    return true;
 }

int main()
{
    setlocale(LC_ALL, "");
    std::vector<float> a;
    std::string ab = "";

    std::vector<float> b;
    std::string bb = "";

    std::vector<float> c;

    int cc;

    // std::cout << "enter first array\n";
    // while(ab != "end")
    // {
    //     std::cin >> ab;
    //     if(isFloat(ab))
    //     {
    //         a.insert(a.begin(), stringToFloat(ab));
    //     }       
    // }
    
    // std::cout << "enter second array\n";
    // while(bb != "end")
    // {
    //     std::cin >> bb;
    //     if(isFloat(bb))
    //     {
    //         b.insert(b.begin(), stringToFloat(bb));
    //     }       
    // }
    a = {12, 23, 34, 45, 0.34};
    b = {56, 67, 51, 45, 0.34, 51.24};

    std::sort(begin(a), end(a));
    std::sort(begin(b), end(b));

    a.erase( unique( a.begin(), a.end() ), a.end() );
    b.erase( unique( b.begin(), b.end() ), b.end() );

    std::cout << "choose command:";
    std::cout << " 0 - Выход из программы\n 1 - Пересечение\n 2 - Объединение\n 3 - Разность\n 4 - операция подмножества\n";
    std::cin >> cc;
    switch (cc)
    {
        case 1:
            for(int i=0; i<a.size(); i++)
            {
                for(int j=0; j<b.size(); j++)
                {
                    if(a[i] == b[j])
                    {
                        c.insert(c.begin(), a[i]);
                    }
                }
            }
            std::sort(begin(c), end(c));
            c.erase( unique( c.begin(), c.end() ), c.end() );
            for(float num : c) std::cout << num << " ";
            break;
        case 2:
            for(int i=0, j=0, k=0; k<std::max(a.size(), b.size())+1; k++)
            {
                c.insert(c.begin(), a[i]);
                c.insert(c.begin(), b[i]);

                if(i<a.size()) i++;
                if(j<b.size()) j++;
            }
            std::sort(begin(c), end(c));
            c.erase( unique( c.begin(), c.end() ), c.end() );
            for(float num : c) std::cout << num << " ";
            break;
        case 3:
            for (float elem : a) {
                if (std::find(b.begin(), b.end(), elem) == b.end()) {
                    c.push_back(elem); // Добавляем элемент, если его нет во втором векторе
                }
            }
            std::sort(begin(c), end(c));
            c.erase( unique( c.begin(), c.end() ), c.end() );
            for(float num : c) std::cout << num << " ";
            break;
        case 4:
            bool flag = false;
            for(float elem : a)
            {
                if(std::find(b.begin(), b.end(), elem) == b.end())
                {   
                    flag = true;
                    std::cout << "b не является подмножеством a";
                    break;
                }
            }
            if(!flag) std::cout << "b является подмножеством a";
            break;

    }

    return 0;
}

