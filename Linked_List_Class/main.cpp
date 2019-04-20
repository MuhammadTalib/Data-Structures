#include<iostream>
using namespace std;
#include"Node.h"
#include "list.h"
#include"Point.h"
int main()
{

	list *L = new list();
	Node *U=new point(3,4);
	Node *V = new point(9,8);
	Node *W = new point(4, 5);

	L->addnode(U);
	L->addnode(V);
	L->addnode(W);

	L->display();


}
