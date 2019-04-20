#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int value;
    Node *next=NULL;
};

void insert(Node **start);
void search(Node *start);
void deletee(Node **start);
void display(Node *start);

int main()
{
    Node *start=NULL;
    insert(&start);
    insert(&start);
    insert(&start);
    insert(&start);
    deletee(&start);
    display(start);
}

void insert(Node **start)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    cout<<"Enter Value:";
    cin>>ptr->value;
    ptr->next=NULL;
    if(*start==NULL)
    {
        *start=ptr;
        (*start)->next=(*start);
    }
    else
    {
        struct Node *CURR=(*start)->next;
        while(CURR->next!=(*start))
        {
            CURR=CURR->next;
        }
        CURR->next=ptr;
        ptr->next=*start;
    }

}
void search(Node *start)
{
    Node *Curr=start;
    int input,flag=0;
    cout<<"Search:";
    cin>>input;
    do
    {
        if(Curr->value==input)
        {
            cout<<"Found"<<endl;
            flag++;
            break;
        }
        Curr=Curr->next;
    }while(Curr!=start);
    if(flag==0)
    {
        cout<<"Not Found"<<endl;
    }
}
void deletee(Node **start)
{
    Node *Curr=*start,*temp=(Node*)malloc(sizeof(Node));
    int input,flag=0;
    cout<<"Delete:";
    cin>>input;

        do
        {
            if(Curr->next->value==input)
            {
                temp=Curr->next->next;
                if((*start)->value==Curr->next->value)
                {
                    *start=temp;
                }
                free(Curr->next);
                Curr->next=temp;

                flag++;

            }
            Curr=Curr->next;
        }while(Curr!=(*start));
        if(flag==0)
        {
            cout<<"Not Found"<<endl;
        }
}
void display(Node *start)
{
    Node *Curr=start;
    cout<<Curr->value<<endl;
    Curr=Curr->next;
    while(Curr!=start)
    {
        cout<<Curr->value<<endl;
        Curr=Curr->next;
    }
}
