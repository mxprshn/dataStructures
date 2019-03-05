#include "list.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Node::Node(const KeyType &key, const ValueType &value, Node *n, Node *p)
{
    this->key = key;
    this->value = value;
    this->next = n;
    this->previous = p;
}

List::List(Node *newHead, Node *newTail, const int &count)
{
    this->head = newHead;
    this->tail = newTail;
    this->length = count;
}

int List::getLength()
{
    return length;
}

Node *List::getHead()
{
    return head;
}

Node *List::getTail()
{
    return tail;
}

Node *List::getElementAt(const int &position)
{
    if (position + 1 > length || position < 0)
    {
        cerr << "Requested element position: " << position << ", length of the list: " << length << endl;
        throw range_error("Error: position is out of range or incorrect.");
    }

    auto *current = head;

    for (int i = 0; i < position; ++i)
    {
        current = current->next;
    }

    // Always returns right pointer, because position always < length
    // otherwise exception would be thrown
    return current;
}

bool List::isEmpty()
{
    return length == 0;
}

void List::pushBack(const KeyType &key, const ValueType &value)
{
    tail = new Node(key, value, tail, nullptr);

    if (isEmpty())
    {
        head = tail;
    }
    else
    {
        tail->previous->next = tail;
    }

    ++length;
}

void List::pushFront(const KeyType &key, const ValueType &value)
{
    head = new Node(key, value, nullptr, head);

    if (isEmpty())
    {
        tail = head;
    }
    else
    {
        head->next->previous = head;
    }

    ++length;
}

pair<KeyType, ValueType> List::popTail()
{
    if (isEmpty())
    {
        cerr << "Could not pop from end of the list.\n\t List is already empty." << endl;
        throw logic_error("Error: trying to delete element in empty list.");
    }

    // make key-value pair to return
    pair<KeyType, ValueType> data = make_pair(tail->key, tail->value);
    auto *oldTail = tail;

    // correct pointers
    if (length == 1)
    {
        tail = head = nullptr;
    }
    else
    {
        tail = tail->previous;
        tail->next = nullptr;

    }
    // actually delete tail element
    delete oldTail;
    --length;
    return data;
}

pair<KeyType, ValueType> List::popHead()
{
    if (isEmpty())
    {
        cerr << "Could not pop from beginning of the list.\n\t List is already empty." << endl;
        throw logic_error("Error: trying to delete element in empty list.");
    }

    // make key-value pair to return
    pair<KeyType, ValueType> data = make_pair(head->key, head->value);
    auto *oldHead = head;

    // correct pointers
    if (length == 1)
    {
        tail = head = nullptr;
    }
    else
    {
        head = head->next;
        head->previous = nullptr;

    }
    // actually delete head element
    delete oldHead;
    --length;
    return data;
}

void List::insertAfter(const KeyType &key, const ValueType &value, const int &position)
{
    auto *previousNode = getElementAt(position);
    auto *newNode = new Node(key, value, previousNode, previousNode->next);

    if (previousNode->next)
    {
        previousNode->next->previous = newNode;
    }
    else
    {
        tail = newNode;
    }

    previousNode->next = newNode;
    ++length;
}

void List::insertBefore(const KeyType &key, const ValueType &value, const int &position)
{
    auto *nextNode = getElementAt(position);
    auto *newNode = new Node(key, value, nextNode->previous, nextNode);

    if (nextNode->previous)
    {
        nextNode->previous->next = newNode;
    }
    else
    {
        head = newNode;
    }

    nextNode->previous = newNode;
    ++length;
}

pair<KeyType, ValueType> List::removeElementAt(const int &position)
{
    Node *target = getElementAt(position);

    if (target->previous)
    {
        target->previous->next = target->next;
    }
    else
    {
        head = target->next;
    }

    if (target->next)
    {
        target->next->previous = target->previous;
    }
    else
    {
        tail = target->previous;
    }

    --length;
    pair<KeyType, ValueType> temp = make_pair(target->key, target->value);
    delete target;
    return temp;
}

int List::getPositionByKey(const KeyType &key)
{
    auto *current = head;
    int counter = 0;

    while (current)
    {
        if (key == current->key)
        {
            return counter;
        }

        current = current->next;
        ++counter;
    }

    // no such key
    return -1;
}

int List::getPositionByValue(const ValueType &value) // if all values are unique
{
    auto *current = head;
    int counter = 0;

    while (current)
    {
        if (value == current->value)
        {
            return counter;
        }

        current = current->next;
        ++counter;
    }

    // no such value
    return -1;
}

bool List::isKeyExist(const KeyType &key)
{
    auto *current = head;

    while (current)
    {
        if (key == current->key)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool List::isValueExists(const ValueType &value)
{
    auto *current = head;

    while (current)
    {
        if (value == current->value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

void List::deleteList()
{
    while (length > 0)
    {
        popHead();
    };

    tail = head = nullptr;
}

List::~List()
{
    deleteList();
}
