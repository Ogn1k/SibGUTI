#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

template <typename K, typename V>
class HashTable {
private:
    // Node structure to hold the key-value pair
    struct Node {
        K key;
        V value;
        Node(K k, V v) : key(k), value(v) {}
    };

    // Array of lists (separate chains) to hold the nodes
    
    int capacity; // Total number of buckets
    int size;     // Number of elements in the hash table

    // Hash function to map keys to bucket index
    int hashFunction(K key) const {
        return std::hash<K>{}(key) % capacity;
    }

    int hashFunctionDirect(int key) {
        return key % table.size();
    }

public:
    std::vector<std::list<V>> table;
    int collisions=0;
    // Constructor to initialize hash table with a given capacity
    HashTable(int capacity) : capacity(capacity), size(0) {
        table.resize(capacity);
    }

    // Function to insert a key-value pair into the hash table
    void insert(K key, V value) {
        int index = hashFunction(key);
        auto& chain = table[index];

        // Check if key already exists in the chain
        auto it = std::find_if(chain.begin(), chain.end(), [&](const Node& node) {
            return node.key == key;
        });

        if (it != chain.end()) {
            
            it->value = value; // Update value if key already exists
        } else {
            chain.emplace_back(key, value); // Insert new node if key doesn't exist
            size++;
        }
    }

    void insertDirect(int key) {
        int index = hashFunctionDirect(key);
        table[index].push_back(key);
    }

    // Function to retrieve a value by key from the hash table
    // V get(K key) const {
    //     int index = hashFunction(key);
    //     const auto& chain = table[index];

    //     for (const auto& node : chain) {
    //         if (node.key == key) {
    //             return node.value;
    //         }
    //     }

    //     throw std::runtime_error("Key not found");
    // }

    // Function to remove a key-value pair from the hash table
    // void remove(K key) {
    //     int index = hashFunction(key);
    //     auto& chain = table[index];

    //     auto it = std::find_if(chain.begin(), chain.end(), [&](const Node& node) {
    //         return node.key == key;
    //     });

    //     if (it != chain.end()) {
    //         chain.erase(it);
    //         size--;
    //     } else {
    //         throw std::runtime_error("Key not found");
    //     }
    // }

    // Function to get the number of elements in the hash table
    int getSize() const {
        return size;
    }

    // Function to check if the hash table is empty
    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    HashTable<std::string, int> hashTable(10);

    hashTable.insertDirect( 1);
    hashTable.insertDirect( 2);
    hashTable.insertDirect( 3);

    hashTable.insertDirect( 1);
    hashTable.insertDirect( 1);

    hashTable.insertDirect(23);
    hashTable.insertDirect( 56);

    try {
        // std::cout << hashTable.get("one") << std::endl;
        // std::cout << hashTable.get("two") << std::endl;
        // std::cout << hashTable.get("three") << std::endl;
        // std::cout << hashTable.get("four") << std::endl;
        // std::cout << hashTable.get("five") << std::endl;

        for(int i = 0; i < hashTable.table.size(); i++/*auto& x : hashTable.table*/)
        {
            std::cout << "table: " << i << ": ";
            for(auto& x : hashTable.table[i])
                std::cout << " key: " << x << " ";
            std::cout << std::endl;
        }
        //std::cout << "collisions: " << hashTable.collisions << std::endl;
        //hashTable.remove("two");
        //std::cout << hashTable.get("two") << std::endl; // This will throw an exception
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}