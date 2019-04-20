#pragma once
#include<stdlib.h>
#include<iostream>
using namespace std;

class list
{
public:
	list()
	{
		this->value = NULL;
		this->Next=NULL;
	}
	void addnode(void *NODE)
	{
	    list *ptr=(list*)malloc(sizeof(list));
	    ptr->value=NODE;
	    ptr->Next=NULL;

		if (this->value == NULL)
		{
            *this = *ptr;
		}
		else
		{
			list *CURR =this;
			while (CURR->Next != NULL)
			{
				CURR = CURR->Next;
			}
			CURR->Next = ptr;
		}
	}
	void* getvalue()
	{
	    return this->value;
	}
	list* getNext()
	{
	    return this->Next;
	}
	virtual void display()
	{
	    cout<<this->value;
	}
private:
	void *value=NULL;
	list *Next=NULL;
};
class point
{
public:

	point(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int getx()
	{
	    return this->x;
	}
	int gety()
	{
	    return this->y;
	}
    void display()
	{
		cout << this->x <<endl;
		cout << this->y << endl;
	}
	friend ostream& operator <<(ostream& o,point &P)
	{
	    return o<< P.x <<endl<< P.y << endl;
	}
private:
	int x;
	int y;
};
class PointList:public list
{
    void display()
	{
	   list *CURR=this;
	   while(CURR!=NULL)
       {
          ((point*)(CURR->getvalue()))->display();
           CURR=CURR->getNext();
       }
	}
};
int main()
{
    point *P=new point(2,1);
    point *Q=new point(3,4);
    point *R=new point(232,1423);
    list *L=new PointList();

    L->addnode((void*)P);
    L->addnode((void*)Q);
    L->addnode((void*)R);

    L->display();


}
