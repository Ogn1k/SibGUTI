#include <iostream>
#include <string>

void shellSort(std::string& str) {
    int n = str.length();
    int h = 2;

    // ��������� ��������� �������� h
    while (h < n / 2) {
        h = 2*h + 1;
    }

    while (h >= 1) {
        // ���������� ��������� ��� �������� �������� h
        for (int i = h; i < n; ++i) {
            char key = str[i];
            int j = i;

            while (j >= h && str[j - h] > key) {
                std::cout << "�������� � h = " << h << ": " << str << std::endl;
                str[j] = str[j - h];
                j -= h;
                
            }

            str[j] = key;
        }

        // ������� ������� ��������� ������ ����� ��������
        

        // ��������� �������� h
        h /= 3;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input = "����������";
    std::cout << "�������� ������: " << input << std::endl;   
    

    shellSort(input);

    std::cout << "��������������� ������: " << input << std::endl;

    return 0;
}