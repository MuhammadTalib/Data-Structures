#include <iostream>
#include <stdlib.h>
using namespace std;

struct Edge
{
    void *value=NULL;
    Edge *Next=NULL;
};
struct Vertex
{
    int value;
    Edge *edge=NULL;
    Vertex *Next=NULL;

    bool visited=false;
};
void insert(Vertex **vertex,int value);
void display(Vertex *vertex);
int main()
{
    Vertex* Vertex=NULL;
    insert(&Vertex,1);
    insert(&Vertex,2);
    insert(&Vertex,3);

    display(Vertex);
}
void insert(Vertex **vertex,int value)
{
    Vertex *ptr=(Vertex*)malloc(sizeof(Vertex));
    ptr->value=value;
    ptr->edge=NULL;
    ptr->Next=NULL;
    ptr->visited=false;

    if(*vertex==NULL)
    {
        *vertex=ptr;
    }
    else
    {
        Vertex *CURR=*vertex;
        while(CURR->Next!=NULL)
        {
            CURR=CURR->Next;
        }
        CURR->Next=ptr;
    }
}
void display(Vertex *vertex)
{
    while(vertex!=NULL)
    {
        cout<<vertex->value<<endl;
        vertex=vertex->Next;
    }
}
