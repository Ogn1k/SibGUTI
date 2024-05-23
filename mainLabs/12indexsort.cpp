#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    std::vector<std::list<int>> table;
    int bucketCount;

    int hashFunction(int key) {
        return key % bucketCount;
    }

public:
    HashTable(int size) : bucketCount(size) {
        table.resize(bucketCount);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int item : table[index]) {
            if (item == key) {
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < bucketCount; ++i) {
            std::cout << i << ": ";
            for (int item : table[i]) {
                std::cout << item << " -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
};

int main() {
    HashTable hashTable(7);

    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(15);
    hashTable.insert(7);
    hashTable.insert(30);

    hashTable.display();

    std::cout << "Search 15: " << (hashTable.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 25: " << (hashTable.search(25) ? "Found" : "Not Found") << std::endl;

    hashTable.remove(15);
    hashTable.display();

    return 0;
}