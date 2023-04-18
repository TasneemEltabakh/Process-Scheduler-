
#pragma once
#include "Node.h"
#include<iostream>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
	Node<T>* Front;
	Node<T>* Rear;
public:

	PriorityQueue()
	{
		Front = nullptr;
		Rear = nullptr;
	}


	bool IsEmpty()
	{
		if (Front == nullptr && Rear == nullptr)
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
		if (Front == nullptr || Front->getItem() >= newnode->getItem()) {
			newnode->setNext(Front);
			Front = newnode;
			return;
		}
		else {
			Node<T>* temp = Front;
			while (temp->getNext() != nullptr && temp->getNext()->getItem() < newnode->getItem()) {
				temp = temp->getNext();
			}
			newnode->setNext(temp->getNext());
			temp->setNext(newnode);
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
			Front = Rear = nullptr;
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
		while (temp != nullptr)
		{
			cout << temp->getItem() << " ";
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
		while (temp != nullptr)
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
		while (temp !=nullptr)
		{
			if (temp->getItem() == item)
			{
				Found = true;
			}
			temp = temp->getNext();
		}
		return Found;
	}

};
