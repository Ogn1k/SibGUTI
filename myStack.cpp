template <typename T>
class Stack : public List<T> {
public:
    void push(T value) {
        Node<T>* node = new Node<T>(value);
        if (!this->head) {
            this->head = this->tail = node;
        } else {
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
        }
        this->listSize++;
    }

    T pop() {
        if (this->empty()) {
            throw std::out_of_range("Stack is empty");
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

    T top() {
        if (this->empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return this->head->value;
    }
};