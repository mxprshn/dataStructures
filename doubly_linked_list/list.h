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
    // Constructor creates a new empty list
    List() = default;

    // Constructor creates a new list with specified parameters
    List(Node *newHead, Node *newTail, const int &size);

    // Destructor deletes list completely
    ~List();

    // Returns length
    int getLength();

    // Get pointer to the first element of list
    Node *getHead();

    // Get pointer to the last element of list
    Node *getTail();

    // Returns a pointer to the element on specified position
    Node *getElementAt(const int &position);

    // Check the list for emptiness
    bool isEmpty();

    // Add new element to the end of the list
    void pushBack(const KeyType &key, const ValueType &value);

    // Add new element to the beginning of the list
    void pushFront(const KeyType &key, const ValueType &value);

    // Removes tail element and returns its key-value pair
    std::pair<KeyType, ValueType> popTail();

    // Removes head element and returns its key-value pair
    std::pair<KeyType, ValueType> popHead();

    // Add a new element after specified position
    void insertAfter(const KeyType &key, const ValueType &value, const int &position);

    // Add a new element before specified position
    void insertBefore(const KeyType &key, const ValueType &value, const int &position);

    // Removes element from the list and returns its key-value pair
    std::pair<KeyType, ValueType> popElementAt(const int &position);

    // Returns position of element with a similar key
    int getPositionByKey(const KeyType &key);

    // Returns position (first met) of element with a similar value
    int getPositionByValue(const ValueType &value);

    // Check if element with a key exists in the list
    bool isKeyExist(const KeyType &key);

    // Check if element (at least one) with a value exists in the list
    bool isValueExists(const ValueType &value);
};
