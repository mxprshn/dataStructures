#pragma once
#include <string>
#include <vector>

struct HashTable;

//get pointer to the new hash table 
HashTable *newTable();

//get load factor of the table
float loadFactor(const HashTable *hashTable);

//add a word to the table
void add(HashTable *hashTable, const std::string &key, const std::string &value);

//delete the table completely
void deleteTable(HashTable *&hashTable);

//check a word for existence in the table
bool keyExists(const HashTable *hashTable, const std::string &key);

//returns value from table by key
std::string value(const HashTable *hashTable, const std::string &key);