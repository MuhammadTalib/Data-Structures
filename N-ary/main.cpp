#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node **child=NULL;
};
void insert(int value,Node **start)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    *(ptr->child)=new Node[10];
    if(*start==NULL)
    {
        (*start)->data=value;
    }
    else
    {
        (*(ptr->child))->data=20;
    }
}
int main()
{
    struct Node *start=(Node*)malloc(sizeof(Node));
    int value;
    cout<<"Enter Value:";
    cin>>value;
    insert(value,&start);

    cout<<"Enter Value:";
    cin>>value;
    insert(value,&start);

    cout<<start->data;


}

