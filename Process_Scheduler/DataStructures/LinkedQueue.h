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
		if (Front == nullptr && Rear == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool enqueue(const T& newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		// Insert the new node
		if (IsEmpty())	//special case if this is the first node to insert
			Front = newNodePtr; // The queue is empty
		else
			Rear->setNext(newNodePtr); // The queue was not empty

		Rear = newNodePtr; // New node is the last node now
		return true;
	} // end enqueue

	bool Dequeue_In_Variable(T& frntEntry) {

		if (IsEmpty())
			return false;

		Node<T>* nodeToDeletePtr = Front;
		frntEntry = Front->getItem();
		Front = Front->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == Rear)	 // Special case: last node in the queue
			Rear = nullptr;

		// Free memory reserved for the dequeued node
		delete nodeToDeletePtr;

		return true;
	}
	void Display()
	{
		Node<T>* temp = Front;
		while (temp != nullptr)
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

	bool Peek_In_Variable(T& frntEntry) const
	{
		if (IsEmpty())
			return false;

		frntEntry = Front->getItem();
		return true;

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
		while (temp != nullptr)
		{
			if (temp->getItem() == item)
			{
				Found = true;
			}
			temp = temp->getNext();
		}
		return Found;
	}

	Node<T>* gethead()
	{
		return Front;
	}

	T returnkth(int k)
	{
		Node<T>* p = Front;
		int count = 0;
		while (p)
		{
			if (count == k)
			{
				return p->getItem();
			}
			p = p->getNext();
			count++;
		}


	}
	~LinkedQueue()
	{
		//Note that the cout statements here is just for learning purpose
		//They should be normally removed from the destructor
		//cout<<"\nStarting LinkedQueue destructor...";
		//cout<<"\nFreeing all nodes in the queue...";

		//Free all nodes in the queue
		T temp;
		while (Dequeue_In_Variable(temp));

		//cout<<"\n Is LinkedQueue Empty now?? ==> "<<boolalpha<<isEmpty();
		//cout<<"\nEnding LinkedQueue destructor..."<<endl;
	}
	LinkedQueue(const LinkedQueue<T>& other)
	{
		Front = nullptr;
		Rear = nullptr;
		Node<T>* current = other.Front;
		while (current != nullptr) {
			enqueue(current->getItem());
			current = current->getNext();
		}
	}
};

