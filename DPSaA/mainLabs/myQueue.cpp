#pragma once
#include "myList.cpp"


template <typename T>
class Queue : public List<T> {
public:
    void enqueue(T value) {
        Node<T>* node = new Node<T>(value);
        if (!this->tail) {
            this->head = this->tail = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
        this->listSize++;
    }

    T dequeue() {
        if (this->empty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node<T>* node = this->head;
        T value = node->value;
        this->head = this->head->next;
        if (this->head) {
            this->head->prev = nullptr;
        } else {
            this->tail = nullptr;
        }
        delete node;
        this->listSize--;
        return value;
    }

    T front() {
        if (this->empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return this->head->value;
    }
};