#pragma once
#include <iostream>

template <typename T>
class Node {
public:
    T value;
    Node* next;
    Node* prev;

    Node(T val) : value(val), next(nullptr), prev(nullptr) {}
};

// Базовый класс списка
template <typename T>
class List {
protected:
    Node<T>* head;
    Node<T>* tail;
    size_t listSize;

public:
    List() : head(nullptr), tail(nullptr), listSize(0) {}

    virtual ~List() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(T value) {
        Node<T>* node = new Node<T>(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        listSize++;
    }

    void pop_back() {
        if (!tail) return;

        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;

        delete temp;
        listSize--;
    }

    void push_front(T value) {
        Node<T>* node = new Node<T>(value);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        listSize++;
    }

    void pop_front() {
        if (!head) return;

        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;

        delete temp;
        listSize--;
    }

    List& operator=(const List& other) {
        if (this != &other) { // Защита от самоприсваивания
            // Удаление текущего списка
            while (head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            head = tail = nullptr;
            listSize = 0;

            // Копирование списка из other
            Node<T>* current = other.head;
            while (current != nullptr) {
                this->push_back(current->value);
                current = current->next;
            }
        }
        return *this; // Возврат ссылки на текущий объект
    }

    

    size_t size() const {
        return listSize;
    }

    bool empty() const {
        return listSize == 0;
    }

    void print() const {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }
};