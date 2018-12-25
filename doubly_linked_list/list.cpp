#include "list.h"

struct Node
{
	int value = 0;
	Node *previous = nullptr;
	Node *next = nullptr;
};

struct List
{
	Node *head = nullptr;
	Node *tail = nullptr;
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

Node *tail(const List *list)
{
	return list->tail;
}

Node *next(const Node *current)
{
	return current->next;
}

Node *previous(const Node *current)
{
	return current->previous;
}

int listLength(const List *list)
{
	return list->length;
}

bool isEmpty(const List *list)
{
	return list->length == 0;
}

bool removeNode(List *list, const int position)
{
	Node *targetNode = findNode(list, position);

	if (targetNode == nullptr)
	{
		return false;
	}

	if (targetNode->previous != nullptr)
	{
		targetNode->previous->next = targetNode->next;
	}
	else
	{
		list->head = targetNode->next;
	}

	if (targetNode->next != nullptr)
	{
		targetNode->next->previous = targetNode->previous;
	}
	else
	{
		list->tail = targetNode->previous;
	}

	--list->length;
	delete targetNode;
	return true;
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

bool exists(const List *list, const int targetValue) 
{
	Node *temp = list->head;

	while (temp != nullptr)
	{
		if (temp->value == targetValue)
		{
			return true;
		}

		temp = temp->next;
	}

	return false;
}

void insertFirst(List *list, const int value)
{
	list->head = new Node{value, nullptr, list->head};

	if (isEmpty(list))
	{
		list->tail = list->head;
	}
	else
	{
		list->head->next->previous = list->head;
	}

	++list->length;
}

void insertLast(List *list, const int value)
{
	list->tail = new Node{value, list->tail, nullptr};

	if (isEmpty(list))
	{
		list->head = list->tail;
	}
	else
	{
		list->tail->previous->next = list->tail;
	}

	++list->length;
}

bool insertAfter(List *list, const int value, const int previousPosition)
{
	Node *previousNode = findNode(list, previousPosition);

	if (previousNode == nullptr)
	{
		return false;
	}

	Node *newNode = new Node{value, previousNode, previousNode->next};

	if (previousNode->next != nullptr)
	{
		previousNode->next->previous = newNode;
	}
	else
	{
		list->tail = newNode;
	}

	previousNode->next = newNode;
	++list->length;
	return true;
}

bool insertBefore(List *list, const int value, const int nextPosition)
{
	Node *nextNode = findNode(list, nextPosition);

	if (nextNode == nullptr)
	{
		return false;
	}

	Node *newNode = new Node{value, nextNode->previous, nextNode};

	if (nextNode->previous != nullptr)
	{
		nextNode->previous->next = newNode;
	}
	else
	{
		list->head = newNode;
	}

	nextNode->previous = newNode;
	++list->length;
	return true;
}

void deleteList(List *&list)
{
	while (removeNode(list, 0));
	delete list;
	list = nullptr;
}


