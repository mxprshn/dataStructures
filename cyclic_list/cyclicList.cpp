#include "cyclicList.h"

struct Node
{
	int value = 0;
	Node *next = nullptr;
};

struct CyclicList
{
	Node *head = nullptr;
	Node *tail = nullptr;
	int length = 0;
};

Node *head(const CyclicList *list)
{
	return list->head;
}

Node *tail(const CyclicList *list)
{
	return list->head;
}

bool isEmpty(CyclicList *list)
{
	return list->length == 0;
}

int value(const Node *targetNode)
{
	return targetNode->value;
}

CyclicList *newList()
{
	return new CyclicList;
}

Node *findNode(const CyclicList *list, const int position)
{
	Node *temp = list->head;

	for (int i = 0; i < position; ++i)
	{
		temp = temp->next;
	}

	return temp;
}

void insert(CyclicList *list, const int value)
{
	Node *newNode = new Node{value, list->head};
	list->head = newNode;

	if (isEmpty(list))
	{
		list->tail = list->head;
	}

	list->tail->next = newNode;
	++list->length;
}

bool insertNext(CyclicList *list, const int value, const int previousPosition)
{
	if (previousPosition >= list->length || previousPosition < 0)
	{
		return false;
	}

	Node *previousNode = findNode(list, previousPosition);
	previousNode->next = new Node{value, previousNode->next};

	if (previousNode == list->tail)
	{
		list->tail = list->tail->next;
	}

	++list->length;
	return true;
}

bool removeHead(CyclicList *list)
{
	if (list->head == nullptr)
	{
		return false;
	}

	if (list->head == list->tail)
	{
		delete list->head;
		list->head = nullptr;
		list->tail = nullptr;
		--list->length;
		return true;
	}

	const Node *temp = list->head;
	list->head = temp->next;
	list->tail->next = list->head;
	delete temp;
	--list->length;

	return true;
}

bool removeNext(CyclicList *list, const int previousPosition)
{
	if (previousPosition >= list->length - 1 || previousPosition < 0)
	{
		return false;
	}

	Node *previousNode = findNode(list, previousPosition);
	const Node *temp = previousNode->next;
	previousNode->next = temp->next;
	list->tail = previousNode;
	delete temp;
	--list->length;
	return true;
}

void deleteList(CyclicList *&list)
{
	while (removeHead(list));
	delete list;
	list = nullptr;
}

void rotate(CyclicList *list)
{
	Node *first = list->tail;
	Node *second = list->head;

	while (second != list->tail)
	{
		Node *temp = second->next;
		second->next = first;
		first = second;
		second = temp;
	}

	second->next = first;

	Node *temp = list->head;
	list->head = list->tail;
	list->tail = temp;
}
