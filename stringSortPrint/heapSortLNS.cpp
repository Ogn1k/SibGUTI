#include <iostream>
#include <string>
#include <vector>

using namespace std;

void heapify(vector<char>& arr, int n, int i) {
    int largest = i; // �������������� ���������� ������� ��� ������
    int left = 2 * i + 1; // ����� = 2*i + 1
    int right = 2 * i + 2; // ������ = 2*i + 2

    // ���� ����� �������� ������� ������ �����
    if (left < n && arr[left] < arr[largest])
        largest = left;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (right < n && arr[right] < arr[largest])
        largest = right;

    // ���� ����� ������� ������� �� ������
    if (largest != i) {
        for (char c : arr)
            cout << c;
        cout << " heapify" << endl;
        swap(arr[i], arr[largest]);

        // ���������� ����������� � �������� ���� ���������� ���������
        heapify(arr, n, largest);
    }
}

void heapsort(vector<char>& arr) {
    int n = arr.size();

    // ���������� ���� (��������������� �������)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // ���� �� ������ ��������� �������� �� ����
    for (int i = n - 1; i > 0; i--) {
        // ���������� ������� ������ � �����
        swap(arr[0], arr[i]);

        // ������� ������� ��������
        for (char c : arr)
            cout << c ;
        cout << " sort" << endl;

        // �������� ��������� heapify �� ����������� ����
        heapify(arr, i, 0);
    }
}

int main() {
        setlocale(LC_ALL, "Russian");
    string str = "������������";
    vector<char> arr(str.begin(), str.end());

    cout << "�������� ������: " << str << endl;
    heapsort(arr);
    cout << "��������������� ������: ";
    for (char c : arr)
        cout << c ;
    cout << endl;

    return 0;
}