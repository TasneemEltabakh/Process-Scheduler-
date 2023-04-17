#pragma once
#include<iostream>
using namespace std;
class Tree_Node
{
private:
	int data;
	Tree_Node* left;
	Tree_Node* right;
public:
	Tree_Node(int val)
	{
		data = val;
		left = right = nullptr;
	}
	void setdata(int d)
	{
		data = d;
	}
	int getdata()
	{
		return data;
	}
	void setright(Tree_Node* p)
	{
		right = p;
	}
	Tree_Node*& getright()
	{
		return right;
	}
	void setleft(Tree_Node* p)
	{
		left = p;
	}
	Tree_Node*& getleft()
	{
		return left;
	}



};

class BSTree
{
private:
	Tree_Node* root;
	static void rec_insertBST(Tree_Node*& subRoot, int key)
	{

		if (subRoot == nullptr)
			subRoot = new Node(key);
		else
			rec_insertBST(subRoot->getright(), key);

	}

	static void rec_destroy_tree(Tree_Node*& subRoot)
	{

		if (subRoot != nullptr)
		{
			rec_destroy_tree(subRoot->getright());
			delete subRoot;
			subRoot = nullptr;
		}

	}

public:

	BSTree()
	{
		root = nullptr;
	}
	~BSTree()
	{
		destroy_tree();
	}

	void insertBST(int key)
	{
		rec_insertBST(root, key);

	}

	void destroy_tree()
	{
		rec_destroy_tree(root);
	}

};

