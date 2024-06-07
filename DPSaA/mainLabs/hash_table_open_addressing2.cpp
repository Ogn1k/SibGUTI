#include <iostream>
#include <list>
#include <vector>

class DirectChainingHashTable {
public:
    DirectChainingHashTable(int size) : table(size) {}

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int elem : table[index]) {
            if (elem == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

private:
    int hashFunction(int key) {
        return key % table.size();
    }

    std::vector<std::list<int>> table;
};

class LinearProbingHashTable {
public:
    LinearProbingHashTable(int size) : table(size, -1), deleted(-2) {}

    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1 && table[index] != deleted) {
            index = (index + 1) % table.size();
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int start_index = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % table.size();
            if (index == start_index) {
                return false;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int start_index = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = deleted;
                return;
            }
            index = (index + 1) % table.size();
            if (index == start_index) {
                return;
            }
        }
    }

private:
    int hashFunction(int key) {
        return key % table.size();
    }

    std::vector<int> table;
    int deleted;
};

class QuadraticProbingHashTable {
public:
    QuadraticProbingHashTable(int size) : table(size, -1), deleted(-2) {}

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i * i) % table.size()] != -1 &&
               table[(index + i * i) % table.size()] != deleted) {
            i++;
        }
        table[(index + i * i) % table.size()] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i * i) % table.size()] != -1) {
            if (table[(index + i * i) % table.size()] == key) {
                return true;
            }
            i++;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i * i) % table.size()] != -1) {
            if (table[(index + i * i) % table.size()] == key) {
                table[(index + i * i) % table.size()] = deleted;
                return;
            }
            i++;
        }
    }

private:
    int hashFunction(int key) {
        return key % table.size();
    }

    std::vector<int> table;
    int deleted;
};

int main() {
    DirectChainingHashTable ht(10);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);

    std::cout << "Search 15: " << ht.search(15) << "\n";
    ht.remove(15);
    std::cout << "Search 15 after removal: " << ht.search(15) << "\n";

    return 0;
}