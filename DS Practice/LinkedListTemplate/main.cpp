#include <iostream>
#include<stdlib.h>
using namespace std;
#include"LinkedList.h"
#include"LinkedList.cpp"
int main()
{
    LinkedList<int> *intstack=new LinkedList<int>;
    intstack->AddNode(4);
    intstack->AddNode(5);

    cout<<intstack->getNODE();
    cout<<intstack->getNext()->getNODE();
    cout<<intstack->pop();
    cout<<intstack->pop();

}
