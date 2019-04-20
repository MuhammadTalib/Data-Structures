#pragma once
#include <iostream>
#include<stdlib.h>
using namespace std;

template <class NODE> class LinkedList
{
public:

    NODE getNODE();
    LinkedList* getNext();
    void AddNode(NODE const& ptr);
    NODE pop();

private:
    NODE value=NULL;
    LinkedList<NODE> *Next=NULL;
};
