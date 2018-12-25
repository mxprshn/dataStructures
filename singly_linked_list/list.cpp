#include "list.h"

struct Node
{
	int value = 0;
	Node *next = nullptr;
};

struct List
{
	Node *head = nullptr;
	int length = 0;
};

int value(const Node *targetNode)
{
	return targetNode->value;
}

List *newList()
{
	return new List;
}

Node *head(const List *list)
{
	return list->head;
}

Node *next(const Node *previousNode)
{
	return previousNode->next;
}

int listLength(const List *list)
{
	return list->length;
}

bool isEmpty(const List *list)
{
	return list->length == 0;
}

Node *findNode(const List *list, const int position)
{
	Node *temp = list->head;

	for (int i = 0; i < position; ++i)
	{
		if (temp == nullptr)
		{
			return temp;
		}

		temp = temp->next;
	}

	return temp;
}

bool removeNext(List *list, const int previousPosition)
{
	if (previousPosition >= list->length - 1 || previousPosition < 0)
	{
		return false;
	}

	Node *previousNode = findNode(list, previousPosition);
	const Node *temp = previousNode->next;
	previousNode->next = temp->next;
	delete temp;
	--list->length;
	return true;
}

bool removeHead(List *list)
{
	if (list->head == nullptr)
	{
		return false;
	}

	const Node *temp = list->head;
	list->head = temp->next;
	delete temp;
	--list->length;
	return true;
}

void insert(List *list, const int value)
{
	Node *newNode = new Node{value, list->head};
	list->head = newNode;
	++list->length;
}

bool insertNext(List *list, const int value, const int previousPosition)
{
	if (previousPosition >= list->length || previousPosition < 0)
	{
		return false;
	}

	Node *previousNode = findNode(list, previousPosition);
	previousNode->next = new Node{value, previousNode->next};
	++list->length;
	return true;
}

void deleteList(List *&list)
{
	while (removeHead(list));
	delete list;
	list = nullptr;
}

