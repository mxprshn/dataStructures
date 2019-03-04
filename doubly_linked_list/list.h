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

public:
    List() = default;

    List(Node *newHead, Node *newTail, const int &count);

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

//remove node from the list
bool removeNode(List *list, const int position);

//checks value for existence int the list
bool exists(const List *list, const int targetValueType);

//get value by pointer to node
int value(const Node *targetNode);

//get pointer to the first element of list
Node *head(const List *list);

//get pointer to the last element of list
Node *tail(const List *list);

//get pointer to the next element of list
Node *next(const Node *current);

//get pointer to the previous element of list
Node *previous(const Node *current);

//create a new list and get pointer to it
List *newList();

//get the length of list
int listLength(const List *list);

//check the list for emptiness
bool isEmpty(const List *list);

//returns pointer to the node of specific position
Node *findNode(const List *list, const int position);

//adds a new element to the beginning of the list
void insertFirst(List *list, const int value);

//adds a new element to the end of the list
void insertLast(List *list, const int value);

//adds a new element after another
bool insertAfter(List *list, const int value, const int previousPosition);

//adds a new element before another
bool insertBefore(List *list, const int value, const int nextPosition);

//delete list completely
void deleteList(List *&list);
