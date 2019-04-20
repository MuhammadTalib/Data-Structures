#pragma once
#include<iostream>
class Node
{
public:
	Node()
	{
		this->Next = NULL;
	}
	Node(Node &N)
	{
		this->Next = N.Next;
	}
	virtual void set(int x,int y) = 0;
	virtual void display() = 0;

	Node *Next;
};
