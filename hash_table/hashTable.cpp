#include "hashTable.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

HashTable::HashTable(unsigned int &baseSize)
{
    auto *newHashTable = new HashTable;
    newHashTable->buckets.resize(baseSize);
}

double HashTable::loadFactor()
{
    return (double) size / (double) buckets.size();
}

unsigned long long HashTable::getHash(const string &word)
{
    unsigned long long int hashSum = 0;
    int base = 1;
    const int constant = 53;

    for (int character : word)
    {
        hashSum += base * character;
        base *= constant;
    }

    return hashSum;
}

void HashTable::expandSize()
{
    buckets.resize(buckets.size() * 2);

    vector<pair<string, string>> buffer;

    for (size_t i = 0; i < (buckets.size() / 2); ++i)
    {
        for (const pair<string, string> &current : buckets[i])
        {
            buffer.push_back(current);
        }

        buckets[i].clear();
    }

    size = 0;

    for (const pair<string, string> &current : buffer)
    {
        this->addToTable(current.first, current.second);
    }
}

void HashTable::addToTable(const string &key, const string &value)
{
    if (this->loadFactor() > 1.0)
    {
        this->expandSize();
    }

    const long long keyHash = getHash(key) % buckets.size();
    buckets[keyHash].push_back({key, value});
    ++size;
}

string HashTable::getValueByKey(const string &key)
{
    const long long keyHash = getHash(key) % buckets.size();
    for (const pair<string, string> &current : buckets[keyHash])
    {
        if (current.first == key)
        {
            return current.second;
        }
    }

    return string();
}

bool HashTable::keyExists(const string &key)
{
    return (this->getValueByKey(key)).empty();
}
