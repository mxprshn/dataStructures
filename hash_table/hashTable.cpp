#include "hashTable.h"
#include <string>
#include <vector>
#include <algorithm>

struct HashTable
{
	int elementsAmount = 0;
	std::vector<std::vector<std::pair<std::string, std::string>>> buckets;
};

HashTable *newTable()
{
	const int baseSize = 5;
	HashTable *newHashTable = new HashTable;
	newHashTable->buckets.resize(baseSize);
	return newHashTable;
}

float loadFactor(const HashTable *hashTable)
{
	return (float)hashTable->elementsAmount / (float)hashTable->buckets.size();
}

unsigned long long int hash(const std::string &word)
{
	unsigned long long int hashSum = 0;
	int base = 1;

	for (int i : word)
	{
		hashSum += base * i;
		base *= 53;
	}

	return hashSum;
}

void expand(HashTable *hashTable)
{
	hashTable->buckets.resize(hashTable->buckets.size() * 2);

	std::vector<std::pair<std::string, std::string>> buffer;

	for (size_t i = 0; i < (hashTable->buckets.size() / 2); ++i)
	{
		for (const std::pair<std::string, std::string> &current : hashTable->buckets[i])
		{
			buffer.push_back(current);
		}

		hashTable->buckets[i].clear();		
	}

	hashTable->elementsAmount = 0;

	for (const std::pair<std::string, std::string> &current : buffer)
	{
		add(hashTable, current.first, current.second);
	}
}

void add(HashTable *hashTable, const std::string &key, const std::string &value)
{
	if (loadFactor(hashTable) > 1.0)
	{
		expand(hashTable);
	}

	const int keyHash = hash(key) % hashTable->buckets.size();
	hashTable->buckets[keyHash].push_back({key, value});
	++hashTable->elementsAmount;
}

void deleteTable(HashTable *&hashTable)
{
	delete hashTable;
	hashTable = nullptr;
}

std::string value(const HashTable *hashTable, const std::string &key)
{
	const int keyHash = hash(key) % hashTable->buckets.size();
	for (const std::pair<std::string, std::string> &current : hashTable->buckets[keyHash])
	{
		if (current.first == key)
		{
			return current.second;
		}
	}

	return "";
}

bool keyExists(const HashTable *hashTable, const std::string &key)
{
	return value(hashTable, key) != "";
}






