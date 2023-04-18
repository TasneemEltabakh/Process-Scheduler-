#pragma once
#include "Node.h"
#include<iostream>
using namespace std;

template <typename T>
class LinkedQueue
{
private:
	Node<T>* Front;
	Node<T>* Rear;
public:

	LinkedQueue()
	{
		Front = nullptr;
		Rear = nullptr;
	}


	bool IsEmpty()
	{
		if (Front == NULL && Rear == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	void enqueue(T item)
	{
		Node<T>* newnode = new Node<T>(item);
		newnode->setItem(item);
		if (IsEmpty())
		{
			Front = newnode;
			Rear = newnode;

		}
		else
		{
			Rear->setNext(newnode);
			Rear = newnode;
		}

	}

	void Dequeue_In_Variable(T& variable) {
		if (IsEmpty())
		{
			cout << "The Queue is Empty";
		}
		else if (Front == Rear)
		{
			variable = Front->getItem();
			delete Front;
			Front = Rear = NULL;
		}
		else
		{
			Node<T>* delptr = Front;
			Front = Front->getNext();
			variable = delptr->getItem();
			delete delptr;
		}
	}
	void Display()
	{
		Node<T>* temp = Front;
		while (temp != NULL)
		{
			cout << temp->getItem() << ", ";
			temp = temp->getNext();
		}
		cout << endl;
	}

	T Peek()
	{
		return Front->getItem();
	}

	int Count()
	{
		int Counter = 0;
		Node<T>* temp = Front;
		while (temp != NULL)
		{
			Counter += 1;
			temp = temp->getNext();
		}
		return Counter;
	}
	bool isFound(T item)
	{
		bool Found = false;
		Node<T>* temp = Front;
		while (temp != NULL)
		{
			if (temp->getItem() == item)
			{
				Found = true;
			}
			temp = temp->getNext();
		}
		return Found;
	}

	void Dequeue_In_Variable(T& variable) {
		if (IsEmpty())
		{
			cout << "The Queue is Empty";
		}
		else if (Front == Rear)
		{
			variable = Front->getItem();
			delete Front;
			Front = Rear = NULL;
		}
		else
		{
			Node<T>* delptr = Front;
			Front = Front->getNext();
			variable = delptr->getItem();
			delete delptr;
		}
	}

	Node<T>* gethead()
	{
		return Front;
	}

};