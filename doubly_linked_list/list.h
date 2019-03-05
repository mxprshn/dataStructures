#pragma once

#include <string>
#include <utility>

typedef std::string KeyType;
typedef int ValueType;

struct Node
{
    KeyType key;
    ValueType value = 0;

    Node *previous = nullptr;
    Node *next = nullptr;

    Node() = default;

    Node(const KeyType &key, const ValueType &value, Node *n = nullptr, Node *p = nullptr);
};

class List
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;

    // Self-destruction of a list
    // Called by destructor
    void deleteList();

public:
    List() = default;

    List(Node *newHead, Node *newTail, const int &count);

    ~List();

    int getLength();

    Node *getHead();

    Node *getTail();

    Node *getElementAt(const int &position);

    bool isEmpty();

    void pushBack(const KeyType &key, const ValueType &value);

    void pushFront(const KeyType &key, const ValueType &value);

    std::pair<KeyType, ValueType> popTail();

    std::pair<KeyType, ValueType> popHead();

    void insertAfter(const KeyType &key, const ValueType &value, const int &position);

    void insertBefore(const KeyType &key, const ValueType &value, const int &position);

    std::pair<KeyType, ValueType> removeElementAt(const int &position);

    int getPositionByKey(const KeyType &key);

    int getPositionByValue(const ValueType &value);

    bool isKeyExist(const KeyType &key);

    bool isValueExists(const ValueType &value);
};
