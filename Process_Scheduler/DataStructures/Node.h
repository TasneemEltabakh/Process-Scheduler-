#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node
{
private:
	T item;
	Node<T>* next;
public:

	Node()
	{
		next = nullptr;
	}

	Node(T newItem)
	{
		item = newItem;
		next = nullptr;

	}

	void setItem(T newItem)
	{
		item = newItem;
	}

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	T getItem() const
	{
		return item;
	}

	Node<T>* getNext() const
	{
		return next;
	}
};