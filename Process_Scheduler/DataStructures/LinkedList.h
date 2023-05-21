#pragma once
#include "Node.h"
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;
	Node<T>* Tail;
	int size;
	bool isSorted;
public:

	
	LinkedList()
	{
		Head = nullptr;
		Tail = nullptr;
		size = 0;
		isSorted = false;
	}


	~LinkedList()
	{
		DeleteAll();
	}

	void PrintList() const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}


	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		if (Head == nullptr)
		{
			InsertAt(0, data);
		}
		else 
		{
			R->setNext(Head);
			Head = R;
		}
		
	}


	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		
	}

	Node<T>* returnTail()
	{

		Node<T>* p = Head;
		while (p)
		{
			p = p->getNext();
			if (p == nullptr)
				Tail = p;
		}
		return Tail;
	}
	

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list

	void InsertEnd(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		Node<T>* p = Head;
		if (Head == nullptr)
		{
			InsertAt(0, data);
		}
		else
		{
			while (p->getNext())
			{
				p = p->getNext();
			}

			p->setNext(R);
		}
		Tail = R;
		size++;
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	
	bool Find(T value)
	{
		Node<T>* p = Head;

		while (p)
		{
			if (p->getItem() == value)
				return true;
			else
				p = p->getNext();
		}
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	
	int CountOccurance(T value) const
	{
		int count = 0;
		Node<T>* p = Head;
		while (p)
		{
			if (p->getItem() == value)
				count++;
			p = p->getNext();
		}
		return count;
	}
	int Count()
	{
		int count = 0;
		Node<T>* p = Head;
		while (p)
		{
			count++;
			p = p->getNext();
		}
		return count;
	}
	//[4] DeleteFirst
	//Deletes the first node in the list
	
	void DeleteFirst()
	{
		Node<T>* p = Head->getNext();
		delete Head;
		Head = p;
		size--;
	}

	//[5] DeleteLast
	//Deletes the last node in the list
	
	void DeleteLast()
	{
		Node<T>* p = Head;
		Node<T>* R = Head->getNext();
		while (R->getNext())
		{
			p = p->getNext();
			R = R->getNext();
		}
		delete R;
		p->setNext(nullptr);
		size--;
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	
	bool DeleteNode(T value)
	{
		Node<T>* p = Head;
		Node<T>* R = p->getNext();
		if (p->getItem() == value)
		{
			Head = R;
			delete p;
			return true;
		}
		while (R)
		{
			if (R->getItem() == value)
			{
				p->setNext(R->getNext());
				delete R;
				return true;
			}
			else
			{
				
				p = p->getNext();
				R = R->getNext();
			}

		}
		return false;
		size--;
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted

	bool DeleteNodes(T value)
	{
		int c = 0;
		Node<T>* p = Head;
		Node<T>* R = p->getNext();
		while (R)
		{
			if (p->getItem() == value)
			{
				Head = R;
				c++;
			}
			if (R->getItem() == value)
			{
				//cout << R->getItem();
				p->setNext(R->getNext());
				R = R->getNext();//->getNext();
				c++;
			}
			else
			{

				p = p->getNext();
				R = R->getNext();
			}

		}
		if (Head->getItem() == value && Head->getNext()==nullptr)
		{
			Head = nullptr;
		}
	
		if (c != 0)
			return true;
		return false;
		size--;
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	
	void Merge(const LinkedList<T>* L)
	{
		
		Node<T>* p = this->Head;
		Node<T>* R =this-> Head->getNext();
		Node<T>* X = L->Head;
		while (R)
		{ 
			p = p->getNext();
			R = R->getNext();
		}
		
		p->setNext(X);

		
	}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)

	void Reverse() {
		Node<T>* prev = nullptr;
		Node<T>* current = Head;
		Node<T>* next = nullptr;
		while (current) {
			next = current->getNext();
			current->setNext(prev);
			prev = current;
			current = next;
		}
		Head = prev;   //Note I put the Head to prev not the current as at the end of the while current=null
	}

	////////////////////////Question 3////////////////////////////
	void PrintKth(int k) const
	{
		
		Node<T>* p = Head;
		int count = 1;
		if (k >= 0)
		{
			while (p)
			{
				count++;
				p = p->getNext();
				if (count == k)
				{
					cout << "\nprinting kth contents:\n\n";
					cout << p->getItem() << endl;
					break;
				}

			}
		}
		if (count < k)
			cout << "this index not found" << endl;

	}


	T returnkth(int k)
	{
		Node<T>* p = Head;
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
	
	/*void InsertSorted(const T& data)
	{
		Node<T>* p = Head;
		Node<T>* R = Head;
		Node<T>* X = Head->getNext();

		int count = 0;
		while (R)
		{
			count++;
			R = R->getNext();
		}
		if (count == 1)
		{
			if (Head->getItem() > data)
			{
				this->InsertBeg(data);
				return;
			}
			else if (Head->getItem() < data) {
				this->InsertEnd(data);
				return;
			}
			else
				return;

		}
		else
		{
			while (p)
			{

				if (data == p->getItem())
				{
					return;

				}
				else if (data > p->getItem()
				{
					this->InsertEnd(data);
					return;
				}
				else
				{
					this->InsertBeg(data);
					return;
				}
				p = p->getNext();
				X = X->getNext();
			}	
		}
	}*/
	void InsertAt(int index, T data)
	{
		Node<T>* p = Head;

		Node<T>* x = new Node<T>(data);
		int counter = 0;
		if (Head == nullptr)
		{
			Head = x;
			return;
		}
		else
		{
			Node<T>* R = p->getNext();
			if (index == 0)
			{
				x->setNext(Head);
				Head = x;
				return;
			}
			else if (index < 0)
			{
				return;
			}
			else
			{
				while (R)
				{
					counter++;
					if (index == counter)
					{
						p->setNext(x);
						x->setNext(R);
						return;
					}
					else
					{
						p = p->getNext();
						R = R->getNext();
					}

				}
				if (index >= counter)
				{
					p->setNext(x);
					x->setNext(nullptr);
				}
			}
		}
	}
	bool IsEmpty()
	{
		if (Head == NULL && Tail == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool Dequeue_In_Variable(T& variable) {
		if (IsEmpty()) {
			
			return false;
		}
		else if (Head == Tail)
		{
			variable = Head->getItem();
			delete Head;
			Head = Tail = nullptr;
		}
		else {
			if (Head->getNext()) {
				Node<T>* delptr = Head;
				Head = Head->getNext();
				variable = delptr->getItem();
				delete delptr;
			}
			else
				return false;
		}
		return true;
	}
	bool peek(T& variable)
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			variable = Head->getItem();
			return true;
		}
	}
	LinkedList(const LinkedList<T>& other)
	{
		Head = nullptr;
		Tail = nullptr;

		Node<T>* current = other.Head;
		while (current != nullptr) {
			T data = current->getItem();
			InsertEnd(data);
			current = current->getNext();
		}
	}
};

