#include <iostream>
#include<stdlib.h>
using namespace std;

struct NODE
{
    int value;
    NODE *prev=NULL;
    NODE *Next=NULL;
};
NODE* insert(NODE *start,int value);
void display(NODE *start);
int main()
{
    NODE *start=NULL;
    start=insert(start,23);
    start=insert(start,12);
    display(start);
}

NODE* insert(NODE *start,int value)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->value=value;
    ptr->Next=NULL;
    if(start==NULL)
    {
        start=ptr;
        start->prev=NULL;
        return start;
    }
    if(start->Next==NULL)
    {
        start->Next=insert(start->Next,value);
    }
}
void display(NODE *start)
{
    while(start!=NULL)
    {
        cout<<start->value;
        display(start->Next);
    }
}
