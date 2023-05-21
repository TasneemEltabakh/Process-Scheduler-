
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

	bool Dequeue_In_Variable(T& variable) {
		if (IsEmpty()) {
			
			return false;
		}
		else if (Front == Rear) {
			variable = Front->getItem();
			delete Front;
			Front = Rear = nullptr;
		}
		else {
			Node<T>* delptr = Front;
			Front = Front->getNext();
			variable = delptr->getItem();
			delete delptr;
		}
		return true;
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
	// Copy constructor
	PriorityQueue(const PriorityQueue& other)
	{
		Front = nullptr;
		Rear = nullptr;

		Node<T>* temp = other.Front;
		Node<T>* prev = nullptr;

		while (temp != nullptr)
		{
			Node<T>* newnode = new Node<T>(temp->getItem());
			newnode->setItem(temp->getItem());

			if (prev == nullptr)
			{
				Front = newnode;
				Rear = newnode;
			}
			else
			{
				Rear->setNext(newnode);
				Rear = newnode;
			}

			temp = temp->getNext();
			prev = newnode;
		}
	}
	bool DeleteNode(const T& item)
	{
		if (IsEmpty())
			return false;

		if (Front->getItem() == item)
		{
			Node<T>* temp = Front;
			Front = Front->getNext();
			delete temp;

			if (Front == nullptr)
				Rear = nullptr;

			return true;
		}

		Node<T>* current = Front->getNext();
		Node<T>* prev = Front;

		while (current != nullptr)
		{
			if (current->getItem() == item)
			{
				prev->setNext(current->getNext());

				if (current == Rear)
					Rear = prev;

				delete current;
				return true;
			}

			prev = current;
			current = current->getNext();
		}

		return false;
	}
	bool DeleteNodePlace(int k)
	{
		if (k < 0 || k >= Count())
			return false;

		if (k == 0)
		{
			Node<T>* temp = Front;
			Front = Front->getNext();
			delete temp;

			if (Front == nullptr)
				Rear = nullptr;

			return true;
		}

		Node<T>* current = Front;
		Node<T>* prev = nullptr;
		int count = 0;

		while (current != nullptr && count < k)
		{
			prev = current;
			current = current->getNext();
			count++;
		}

		if (current != nullptr)
		{
			prev->setNext(current->getNext());

			if (current == Rear)
				Rear = prev;

			delete current;
			return true;
		}

		return false;
	}

};
