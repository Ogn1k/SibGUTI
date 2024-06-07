#include <cstdint>
#include <vector>

// Константы
const int L = 3; // Максимальная длина числа в разрядах
const int m = 256; // Основание системы счисления (количество очередей)

// Структура для представления узла списка
struct Node 
{
    std::array<uint8_t, L> digits; // массив для хранения цифр числа
    Node* next; // указатель на следующий элемент списка
};

// Функция для сортировки списка по разрядам
int radixSort(Node*& head, int L) 
{
    std::vector<Node*> queues[m]; // массив очередей (векторов)
    int move=0;
    
    for (int j = L - 1; j >= 0; --j) 
    { // Проход по цифрам справа налево
        // Инициализация очередей
        for (int i = 0; i < m; ++i) 
        {
            queues[i].clear();
        }

        Node* p = head; // Начало списка
        // Распределение элементов по очередям в соответствии с j-ой цифрой
        while (p != nullptr) {
            int d = p->digits[j]; // Извлечение j-ой цифры
            queues[d].push_back(p); // Добавление узла в соответствующую очередь
            p = p->next; // Переход к следующему узлу
        }

        // Слияние очередей в один список
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
            tail->next = nullptr; // Завершаем список
        }
        head = newHead; // Обновляем указатель на начало списка
    }
    return move;
}

// Вспомогательная функция для преобразования числа в массив цифр
std::array<uint8_t, L> numberToDigits(int number) {
    std::array<uint8_t, L> digits = {0};
    for (int i = L - 1; i >= 0 && number > 0; --i) {
        digits[i] = number % 10;
        number /= 10;
    }
    return digits;
}

// Функция для создания списка из массива чисел
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