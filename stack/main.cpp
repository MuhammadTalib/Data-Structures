
#include <iostream>
#include<stdlib.h>
using namespace std;

struct NODE
{
    int value;
    struct NODE *Next=NULL;
};

void push(NODE **top,NODE *ptr);
NODE* pull(NODE **top);

void push(NODE **top,NODE *ptr)
{
    ptr->Next=*top;
    *top=ptr;
}
NODE* pull(NODE **top)
{
    NODE *CURR=*top;
    *top=(*top)->Next;
    return CURR;
}
int main()
{
    struct NODE *top=NULL,*ptr=(NODE*)malloc(sizeof(NODE));
    ptr->value=12;
    ptr->Next=NULL;

    push(&top,ptr);
    cout<<(pull(&top))->value;
}
