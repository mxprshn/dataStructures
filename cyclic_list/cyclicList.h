#pragma once

struct CyclicList;
struct Node;

//returns pointer to the new list
CyclicList *newList();

//checks the list for emptiness
bool isEmpty(CyclicList *list);

//returns value of the node
int value(const Node *targetNode);

//returns pointer to the node on particular position
Node *findNode(const CyclicList *list, const int position);

//inserts a new element to the beginning of the list
void insert(CyclicList *list, const int value);

//inserts a new element after another element
bool insertNext(CyclicList *list, const int value, const int previousPosition);

//removes the first element of the list
bool removeHead(CyclicList *list);

//removes the element after another element
bool removeNext(CyclicList *list, const int previousPosition);

//deletes the list completely 
void deleteList(CyclicList *&list);

//rotates the list
void rotate(CyclicList *list);

