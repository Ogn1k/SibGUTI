#include <iostream>
#include <string>

void bubbleSort(std::string &str) {
    int n = str.length();
    int iter = 0;
    for (int i = 0; i <= n-1; i++) {
        for (int j = n; j >= i+1; j--) {
            if (str[j] < str[j-1]) {
                // ������ ������� str[j] � str[j+1]
                std::swap(str[j], str[j-1]);
            }
            std::cout << "�������� " << iter++ << ": " << str << std::endl;
        }
        // ������� ������ ����� ������ ��������
        
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    std::string str = "����������";
    std::cout << "�������� ������: " << str << std::endl;
    bubbleSort(str);
    std::cout << "��������������� ������: " << str << std::endl;
    return 0;
}