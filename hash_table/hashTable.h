#pragma once

#include <string>
#include <vector>

class HashTable
{
private:
    int size = 0;
    std::vector<std::vector<std::pair<std::string, std::string>>> buckets;

    // Generate a hash
    unsigned long long getHash(const std::string &word);

public:
    // Create a new hash table
    HashTable() = default;

    // Delete hash table completely
    ~HashTable() = default;

    explicit HashTable(unsigned int &baseSize);

    // Get load factor of the table
    double loadFactor();

    // Expand size of the table, when it hits the limit
    void expandSize();

    // Add a word to the table
    void addToTable(const std::string &key, const std::string &value);

    // Returns value from table by key
    std::string getValueByKey(const std::string &key);

    // Check a word for existence in the table
    bool keyExists(const std::string &key);
};
