#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Queue{

private:

    void *value;
    struct Queue *Next=NULL;

public:
void enqueue(Queue **top,void* value)
{
   Queue*ptr;
    ptr=(Queue*)malloc(sizeof(Queue));
    ptr->value=value;
    ptr->Next=NULL;

    if(*top==NULL)
    {
        (*top)=ptr;
    }
    else
    {
         struct Queue *CURR=*top;
         while(CURR->Next!=NULL)
         {
             CURR=CURR->Next;
         }
         CURR->Next=ptr;
    }

}
void* dequeue(Queue **top)
{
    void* CURR=(*top)->value;
    *top=(*top)->Next;
    return CURR;
}
};


/*
int main()
{
    struct NODE *top=(NODE*)malloc(sizeof(NODE));
    top=NULL;
    int *a;
    int b=20;


    enqueue(&top,&b);


    cout<<endl<<(top->value)<<endl;

    int *v=(int*)(dequeue(&top));
    cout<<"v="<<*v;
}
*/
