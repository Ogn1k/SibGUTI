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

    void rehashLinear() {
        int oldCapacity = capacity;
        capacity *= 2;
        std::vector<HashNode*> oldTable = table;
        table.clear();
        table.resize(capacity, nullptr);
        size = 0;

        for (int i = 0; i < oldCapacity; ++i) {
            if (oldTable[i] && !oldTable[i]->isDeleted) {
                insertLinear(oldTable[i]->key, oldTable[i]->value);
                delete oldTable[i];
            }
        }
    }

    void rehashQuadratic() {
        int oldCapacity = capacity;
        capacity *= 2;
        std::vector<HashNode*> oldTable = table;
        table.clear();
        table.resize(capacity, nullptr);
        size = 0;

        for (int i = 0; i < oldCapacity; ++i) {
            if (oldTable[i] && !oldTable[i]->isDeleted) {
                insertQuadratic(oldTable[i]->key, oldTable[i]->value);
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

    void insertLinear(K key, V value) {
        if (static_cast<float>(size) / capacity >= loadFactor) {
            rehashLinear();
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

    void insertQuadratic(K key, V value) {
        if (static_cast<float>(size) / capacity >= loadFactor) {
            rehashQuadratic();
        }

        int index = hashFunction(key);
        int i = 0;

        while (table[index] && !table[index]->isDeleted && table[index]->key != key) {
            index = (index + i * i) % capacity;
            i++;
            if (i == capacity) {
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

    V getLinear(K key) const {
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

    V getQuadratic(K key) const{
        int index = hashFunction(key);
        int i = 0;

        while (table[index] && (table[index]->isDeleted || table[index]->key != key)) {
            index = (index + i * i) % capacity;
            i++;
            if (i == capacity) {
                throw std::runtime_error("Key not found");
            }
        }

        if (!table[index] || table[index]->isDeleted) {
            throw std::runtime_error("Key not found");
        }

        return table[index]->value;
    }

    void removeLinear(K key) {
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

    void removeQuadratic(K key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[index] && (table[index]->isDeleted || table[index]->key != key)) {
            index = (index + i * i) % capacity;
            i++;
            if (i == capacity) {
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

    hashTable.insertLinear("one", 1);
    hashTable.insertLinear("two", 2);
    hashTable.insertLinear("three", 3);

    hashTable.insertLinear("one", 124);
    hashTable.insertLinear("four", 124);
    hashTable.insertLinear("five", 124);

    hashTable.insertQuadratic("one", 1);
    hashTable.insertQuadratic("two", 2);
    hashTable.insertQuadratic("three", 3);

    hashTable.insertQuadratic("three", 124);
    hashTable.insertQuadratic("four", 124);
    hashTable.insertQuadratic("five", 124);

    try {
        std::cout << hashTable.getLinear("one") << std::endl;
        std::cout << hashTable.getLinear("two") << std::endl;
        std::cout << hashTable.getLinear("three") << std::endl;
        std::cout << hashTable.getLinear("four") << std::endl;
        std::cout << hashTable.getLinear("five") << "\n" << std::endl;

        // std::cout << hashTable.getQuadratic("one") << std::endl;
        // std::cout << hashTable.getQuadratic("two") << std::endl;
        // std::cout << hashTable.getQuadratic("three") << std::endl;
        // std::cout << hashTable.getQuadratic("four") << std::endl;
        // std::cout << hashTable.getQuadratic("five") << std::endl;

        // std::cout << "collisions: " << hashTable.collisions << std::endl;

        //hashTable.removeLinear("two");
        //std::cout << "Value for 'two' after removal: " << hashTable.getQuadratic("two") << std::endl; // This will throw an exception
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}