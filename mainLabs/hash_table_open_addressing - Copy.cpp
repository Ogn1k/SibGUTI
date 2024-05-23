#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>

template <typename K, typename V>
class HashTable {
private:
    struct HashNode {
        K key;
        V value;
        bool isDeleted;
        HashNode(K k, V v) : key(k), value(v), isDeleted(false) {}
    };

    std::vector<HashNode*> table;
    int capacity;
    int size;
    float loadFactor;

    int hashFunction(K key) const {
        return std::hash<K>{}(key) % capacity;
    }

    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        std::vector<HashNode*> oldTable = table;
        table.clear();
        table.resize(capacity, nullptr);
        size = 0;

        for (int i = 0; i < oldCapacity; ++i) {
            if (oldTable[i] && !oldTable[i]->isDeleted) {
                insert(oldTable[i]->key, oldTable[i]->value);
                delete oldTable[i];
            }
        }
    }

public:
    int collisions =0;
    HashTable(int initialCapacity = 10, float maxLoadFactor = 0.75)
        : capacity(initialCapacity), size(0), loadFactor(maxLoadFactor) {
        table.resize(capacity, nullptr);
    }

    ~HashTable() {
        for (int i = 0; i < capacity; ++i) {
            if (table[i]) {
                delete table[i];
            }
        }
    }

    void insert(K key, V value) {
        if (static_cast<float>(size) / capacity >= loadFactor) {
            rehash();
        }

        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] && !table[index]->isDeleted && table[index]->key != key) {
            collisions++;
            index = (index + 1) % capacity;
            if (index == startIndex) {
                throw std::runtime_error("HashTable is full");
            }
        }

        if (!table[index] || table[index]->isDeleted) {
            if (!table[index]) {
                table[index] = new HashNode(key, value);
            } else {
                table[index]->key = key;
                table[index]->value = value;
                table[index]->isDeleted = false;
            }
            size++;
        } else {
            table[index]->value = value;
        }
    }

    V get(K key) const {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] && (table[index]->isDeleted || table[index]->key != key)) {
            index = (index + 1) % capacity;
            if (index == startIndex) {
                throw std::runtime_error("Key not found");
            }
        }

        if (!table[index] || table[index]->isDeleted) {
            throw std::runtime_error("Key not found");
        }

        return table[index]->value;
    }

    void remove(K key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] && (table[index]->isDeleted || table[index]->key != key)) {
            index = (index + 1) % capacity;
            if (index == startIndex) {
                throw std::runtime_error("Key not found");
            }
        }

        if (!table[index] || table[index]->isDeleted) {
            throw std::runtime_error("Key not found");
        }

        table[index]->isDeleted = true;
        size--;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    HashTable<std::string, int> hashTable(10);

    hashTable.insert("one", 1);
    hashTable.insert("two", 2);
    hashTable.insert("three", 3);

    hashTable.insert("one", 124);
    hashTable.insert("four", 124);
    hashTable.insert("five", 124);

    try {
        std::cout << hashTable.get("one") << std::endl;
        std::cout << hashTable.get("two") << std::endl;
        std::cout << hashTable.get("three") << std::endl;
        std::cout << hashTable.get("four") << std::endl;
        std::cout << hashTable.get("five") << std::endl;

        std::cout << "collisions: " << hashTable.collisions << std::endl;

        hashTable.remove("two");
        std::cout << "Value for 'two' after removal: " << hashTable.get("two") << std::endl; // This will throw an exception
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}