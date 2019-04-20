#include <iostream>
#include<stdlib.h>
using namespace std;
struct Vertex;
struct Edge;

struct Vertex
{
    int data;
    Vertex *next=NULL;
    Edge *edge=NULL;

};
struct Edge
{
    Vertex *data=NULL;
    Edge *Next=NULL;
};
void insert(Vertex **vertex);
void setConnections(Vertex **vertex);
void display(Vertex *vertex);
int main()
{
    Vertex *vertex=NULL;
   insert(&vertex);
   insert(&vertex);
    insert(&vertex);

    display(vertex);

    setConnections(&vertex);




}
void display(Vertex *vertex)
{
    if(vertex!=NULL)
    {
        cout<<vertex->data<<endl;
        display(vertex->next);
    }
}
void insert(Vertex **vertex)
{
    Vertex *ptr=(Vertex*)malloc(sizeof(Vertex));
    cout<<"Enter Node:";
    cin>>ptr->data;
    ptr->next=NULL;
    ptr->edge=NULL;


    if(*vertex==NULL)
    {
        (*vertex)=ptr;
    }
    else
    {
        Vertex *CURR=*vertex;
        while(CURR->next!=NULL)
        {
            CURR=CURR->next;

        }
        CURR->next=ptr;
    }
}
void setConnections(Vertex **vertex)
{
    Vertex *CURR=*vertex,*CURRE=*vertex;
    Edge *edge=(*vertex)->edge;
    while(CURR!=NULL)
    {
        int input;
        cout<<endl<<"Connect "<<CURR->data<<" with:";
        cin>>input;

        while(CURRE!=NULL)
        {
            if(CURRE->data=input)
            {
                if(CURR->edge==NULL)
                {
                    CURR->edge->data=CURRE;
                }
                else
                {
                    edge=CURR->edge;
                    while(edge->Next!=NULL)
                    {
                        edge=edge->Next;
                    }
                    edge->Next->data=CURRE;
                }
                break;
            }
        }
    }
}









