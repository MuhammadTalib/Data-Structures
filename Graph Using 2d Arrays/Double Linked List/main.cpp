#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node{
int value;
struct Node *next=NULL;
struct Node *prev=NULL;
};

void insertt(struct Node **start);
void display(Node *start);
void searchh();
void deletee();
void InsertionSort(struct Node **start);
int sizeofList(Node *start);

void swap(struct Node **start,struct Node *p1,struct Node *p2)
{
    if(p1->value!=p2->value )
    {
        cout<<endl<<"P1="<<p1->value<<endl;
        cout<<endl<<"P2="<<p2->value<<endl;
        struct Node *CURR=*start;
        struct Node *p2prev=*start,*p1prev=*start,*temp;
        temp=p2->next;
        if((*start)->value==p1->value)
        {
            if((*start)->next->value==p2->value)
            {
                 CURR->next=p2->next;
                 p2->next=p1;
                 *start=p2;
            }
            else
            {
                while(CURR->next!=NULL)
                {
                    if(CURR->next->value==p2->value)
                    {
                        p2prev=CURR;
                    }
                    if(p2->next==NULL)
                    {
                       temp=NULL;
                    }
                    CURR=CURR->next;
                }

                CURR=(*start);
                *start=p2;
                p2->next=p1->next;
                p2prev->next=p1;
                p1->next=temp;
            }
        }

        else
        {
            while(CURR->next!=NULL)
            {
                if((CURR->next)->value==p1->value)
                {
                    p1prev=CURR;
                }
                if(CURR->next->value==p2->value)
                {
                    p2prev=CURR;
                }
                CURR=CURR->next;
            }
            if(p2prev->value==p1->value)
            {
                p1prev->next=p2;
                p2->next=p1;
                p1->next=temp;
            }
            else
            {
                p1prev->next=p2;
                p2->next=p1->next;
                p2prev->next=p1;
                p1->next=temp;
            }
        }
    }
}

int sizeofList(Node *start)
{
    struct Node *CURR=start;
    int check=0;
    while(CURR!=NULL)
    {
        check++;
        CURR=CURR->next;
    }
    return check;
}
void InsertionSort(struct Node **start)
{
    struct Node *CURR=*start,*hold=(Node*)malloc(sizeof(Node)),*temp=(Node*)malloc(sizeof(Node));
    int i=0,j=0,n=sizeofList(*start);
    CURR=*start;
    hold->value=CURR->next->value;
    hold->next->value=CURR->next->next->value;
    temp=(*start)->next->next;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j>=0;j--)
        {
            cout<<endl<<"In 2nd for"<<endl;
            if(CURR->value > hold->value)
            {
                cout<<"in if"<<endl;
                cout<<endl<<"CURR="<<CURR->value;
                cout<<endl<<"CURR->NEXT="<<CURR->next->value;

                swap(start,CURR,CURR->next);

                cout<<endl<<"CURR="<<CURR->value;
                cout<<endl<<"CURR->NEXT="<<CURR->next->value;

                CURR=CURR->prev;
                cout<<endl<<"TT"<<endl;
                if(CURR->prev!=NULL)
                {
                    cout<<"in ifff";
                     CURR=CURR->prev;
                }
                display(*start);
                cout<<endl;
            }
            cout<<"without if";
        }
        cout<<"after for"<<endl;

        hold->value=temp->value;
        CURR=temp->prev->prev;
        temp=temp->next;
         cout<<"after updating"<<endl;

    }


}
void insertt(struct Node **start)
{
    struct Node *ptr;
    ptr=(Node*)malloc(sizeof(Node));
    cout<<"Enter Number:";
    cin>>ptr->value;
    ptr->next=NULL;
    if(*start==NULL)
    {
        *start=ptr;
    }
    else
    {
        struct Node *CURR=*start;
        while(CURR->next!=NULL)
        {
            CURR=CURR->next;
        }
        CURR->next=ptr;
        CURR->next->prev=CURR;
    }
}

void searchh(struct Node *start)
{
    struct Node *CURR=start;
    int input,flag=0;
    cout<<"Enter Number";
    cin>>input;
    while(CURR!=NULL)
    {
        if(CURR->value==input)
        {
            flag++;
            break;
        }
        CURR=CURR->next;
    }
    (flag)?cout<<"Found":cout<<"Not Found";

}

void display(struct Node *start)
{

    struct Node *CURRR=start;
    while(CURRR->next!=NULL)
    {
        cout<<CURRR->value<<endl;
        CURRR=CURRR->next;
    }
   cout<<CURRR->value<<endl;
}

void deletee(struct Node **start)
{
     struct Node *CURR=*start;
    int input,flag=0;
    cout<<"Enter Number";
    cin>>input;
    if((*start)->value==input)
    {
        CURR=(*start)->next;
        free(*start);
        *start=CURR;
    }
    else
    {
        while(CURR!=NULL)
        {
            if(CURR->value==input)
            {
                CURR->prev->next=CURR->next;
                if(CURR->next!=NULL)
                    CURR->next->prev=CURR->prev;
            }
            CURR=CURR->next;
        }
    }
}
int main()
{
    struct Node *start=NULL,*P1,*P2;
    insertt(&start);
    insertt(&start);
    insertt(&start);
    insertt(&start);
    insertt(&start);
    InsertionSort(&start);
    display(start);


}
