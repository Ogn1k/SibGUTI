#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
struct Numberstr
{
    std::string name;
    int num1;
};

void swap(Numberstr &var1, Numberstr &var2)
{
    Numberstr temp = var1;
    var1 = var2;
    var2 = temp;
}

void Sortthis(std::vector<Numberstr>& r, int n)
{

   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++) 
       {
            if (r[j].name > r[j+1].name)
            {
                
                swap(r[j], r[j+1]);
                
            }
            if(r[j].name == r[j+1].name)
            {
                if(r[j].num1 > r[j+1].num1)
                {
                    swap(r[j], r[j+1]);
                }
            }
       }
}

bool customer_sorter(Numberstr const& lhs, Numberstr const& rhs) {
    if (lhs.name != rhs.name)
        return lhs.name < rhs.name;
    return lhs.num1 < rhs.num1;
}

int main()
{
    std::vector<Numberstr> nums = 
        {
        {"bsdas", 100}, 
        {"aasdas", 120},
        {"aasdas", 80},
        {"juyg", 150}
        };

    for(const auto& aa : nums)
    {
        std::cout << aa.name << " " << aa.num1 << std::endl;
    }

    //std::sort(nums.begin(), nums.end(), &customer_sorter);
    Sortthis(nums, 4);
    std::cout << "\n";

    for(const auto& aa : nums)
    {
        std::cout << aa.name << " " << aa.num1 << std::endl;
    }

    return 0;
}