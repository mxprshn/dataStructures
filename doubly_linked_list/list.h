#pragma once
#include <string>

struct List;
struct Node;

//remove node from the list
bool removeNode(List *list, const int position);

//checks value for existence int the list
bool exists(const List *list, const int targetValue);

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
