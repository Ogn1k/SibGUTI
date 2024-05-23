#include <cstdint>
#include <vector>
#include <array>
#include <iostream>
#include "fill_array.hpp"

// ���������
const int L = 3; // ������������ ����� ����� � ��������
const int m = 256; // ��������� ������� ��������� (���������� ��������)

// ��������� ��� ������������� ���� ������
struct Node 
{
    std::array<uint8_t, L> digits; // ������ ��� �������� ���� �����
    Node* next; // ��������� �� ��������� ������� ������
};

// ������� ��� ���������� ������ �� ��������
int radixSort(Node*& head, int L) 
{
    std::vector<Node*> queues[m]; // ������ �������� (��������)
    int move=0;
    
    for (int j = L - 1; j >= 0; --j) 
    { // ������ �� ������ ������ ������
        // ������������� ��������
        for (int i = 0; i < m; ++i) 
        {
            queues[i].clear();
        }

        Node* p = head; // ������ ������
        // ������������� ��������� �� �������� � ������������ � j-�� ������
        while (p != nullptr) {
            int d = p->digits[j]; // ���������� j-�� �����
            queues[d].push_back(p); // ���������� ���� � ��������������� �������
            p = p->next; // ������� � ���������� ����
        }

        // ������� �������� � ���� ������
        Node* newHead = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < m; ++i) {
            for (Node* node : queues[i]) 
            {
                move++;
                if (newHead == nullptr) {
                    newHead = node;
                    tail = node;
                } else {
                    tail->next = node;
                    tail = node;
                }
            }
        }
        if (tail != nullptr) {
            tail->next = nullptr; // ��������� ������
        }
        head = newHead; // ��������� ��������� �� ������ ������
    }
    return move;
}

// ��������������� ������� ��� �������������� ����� � ������ ����
std::array<uint8_t, L> numberToDigits(int number) {
    std::array<uint8_t, L> digits = {0};
    for (int i = L - 1; i >= 0 && number > 0; --i) {
        digits[i] = number % 10;
        number /= 10;
    }
    return digits;
}

// ������� ��� �������� ������ �� ������� �����
Node* createList(const std::vector<int>& numbers) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int number : numbers) {
        Node* newNode = new Node{numberToDigits(number), nullptr};
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// ������� ��� ������ ������ �����
void printList(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        for (uint8_t digit : p->digits) {
            std::cout << (int)digit;
        }
        std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

// ������ �������������
int main() {
    setlocale(LC_ALL, "Russian");
    // �������� ������ �����
    std::vector<int> numbers = {33, 25, 124, 11, 10, 9, 2};

    int asize=100,bsize=200,csize=300,dsize=400,esize=500;

    int tra=asize, tia=tra, tda=tra;
    int trb=bsize, tib=trb, tdb=trb;
    int trc=csize, tic=trc, tdc=trc;
    int trd=dsize, tid=trd, tdd=trd;
    int tre=esize, tie=tre, tde=tre;

    Node* a = createList(FillInc(std::vector<int>(100), 100));
    Node* b = createList(FillInc(std::vector<int>(200), 200));
    Node* c = createList(FillInc(std::vector<int>(300), 300));
    Node* d = createList(FillInc(std::vector<int>(400), 400));
    Node* e = createList(FillInc(std::vector<int>(500), 500));

    Node* ar = createList(FillRand(std::vector<int>(100), 100));
    Node* br = createList(FillRand(std::vector<int>(200), 200));
    Node* cr = createList(FillRand(std::vector<int>(300), 300));
    Node* dr = createList(FillRand(std::vector<int>(400), 400));
    Node* er = createList(FillRand(std::vector<int>(500), 500));

    Node* ad = createList(FillDec(std::vector<int>(100), 100));
    Node* bd = createList(FillDec(std::vector<int>(200), 200));
    Node* cd = createList(FillDec(std::vector<int>(300), 300));
    Node* dd = createList(FillDec(std::vector<int>(400), 400));
    Node* ed = createList(FillDec(std::vector<int>(500), 500));
    // �������� ������
    Node* head = createList(numbers);

    // ����� ��������� ������
    printList(head);

    // ����� ������� ����������
    radixSort(head, L);
    
    // ����� ���������������� ������
    printList(head);

    printTableHeader("digitalSort");
    printRow(asize, tda, tra, tia, radixSort( ad, L), radixSort( ar, L), radixSort( a, L));
    printRow(bsize, tdb, trb, tib, radixSort( bd, L), radixSort( br, L), radixSort( b, L));
    printRow(csize, tdc, trc, tic, radixSort( cd, L), radixSort( cr, L), radixSort( c, L));
    printRow(dsize, tdd, trd, tid, radixSort( dd, L), radixSort( dr, L), radixSort( d, L));
    printRow(esize, tde, tre, tie, radixSort( ed, L), radixSort( er, L), radixSort( e, L));
    

    // ������� ������
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}