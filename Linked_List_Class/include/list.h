#pragma once
#include<iostream>
using namespace std;
#include"Node.h"
class list
{
public:
	list()
	{
		this->value = NULL;
	}

	void addnode(Node *Ndd)
	{
		if (value == NULL)
		{
			this->value = Ndd;
		}
		else
		{
			Node* CURR =this->value;
			while (CURR->Next != NULL)
			{
				CURR = CURR->Next;
			}
			CURR->Next = Ndd;
		}
	}
	int i = 0;

	void display()
	{
		if (this->value == NULL) {
			cout << "List is empty!" << endl;
		}
		else {
			Node* temp = this->value;
			int j = 0;
			while (temp != NULL)
			{
				temp->display();
				temp = temp->Next;

			}
			cout << endl;
		}
	}
	private:
	Node *value;
};
