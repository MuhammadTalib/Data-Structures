#include <iostream>
#include<stdlib.h>
using namespace std;

struct NODE
{
    int value;
    struct NODE *Next=NULL;
};

void insert(NODE **start);
void display(NODE *start);
NODE* search(NODE start);
void deletee(NODE **start);
void swap(struct NODE **start,struct NODE *p1,struct NODE *p2);
void Selection_Sort(struct NODE **start);
void Bubble_Sort(struct NODE **start);
NODE* FindMin(NODE *start);
int sizeofList(NODE *start);

int sizeofList(NODE *start)
{
    struct NODE *CURR=start;
    int check=0;
    while(CURR!=NULL)
    {
        check++;
        CURR=CURR->Next;
    }
    return check;
}
NODE* FindMin(NODE *start)
{
    struct NODE *CURR=start;
    struct NODE *Check=(NODE*)malloc(sizeof(NODE));

    Check->value=start->value;
    while(CURR!=NULL)
    {
        if(CURR->value < Check->value)
        {
            Check->value=CURR->value;
            Check->Next=CURR->Next;
        }
        CURR=CURR->Next;
    }
    return Check;
}

void Selection_Sort(NODE **start)
{
    struct NODE *CURR=*start,*MIN=CURR,*Moving_Start=(NODE*)malloc(sizeof(NODE));

    while(CURR!=NULL)
    {
        MIN=FindMin(CURR);
         cout<<"MIN->weight"<<MIN->value<<endl;
        cout<<"CURR->weight"<<CURR->value<<endl;
        cout<<"min"<<MIN->value<<endl;
        swap(start,CURR,MIN);
         cout<<"MIN->weight"<<MIN->value<<endl;
        cout<<"CURR->weight"<<CURR->value<<endl;

        CURR=MIN;
        CURR=CURR->Next;

    }

}
void Bubble_Sort(struct NODE **start)
{
    struct NODE *CURR=*start,*CURRR=CURR->Next,*temp=*start;
    int i=0,j=0,n=sizeofList(*start);
    while(i<n-1)
    {
        cout<<endl<<"in 1st while"<<endl;
        while(j<n-i-1)
        {
            cout<<"in 2nd while"<<endl;
            if(CURR->value>CURRR->value)
            {
                cout<<endl<<"CURR="<<CURR->value<<endl;
                cout<<endl<<"CURRR="<<CURRR->value<<endl;
                swap(start,CURR,CURRR);
                temp=CURR;
                CURR=CURRR;
                CURRR=temp;
            }
            CURRR=CURRR->Next;
            CURR=CURR->Next;
            j++;
        }
        CURR=*start;
        CURRR=(*start)->Next;
        i++;
        j=0;
    }
}
void swap(struct NODE **start,struct NODE *p1,struct NODE *p2)
{
    if(p1->value!=p2->value )
    {
        cout<<endl<<"P1="<<p1->value<<endl;
        cout<<endl<<"P2="<<p2->value<<endl;
        struct NODE *CURR=*start;
        struct NODE *p2prev=*start,*p1prev=*start,*temp;
        temp=p2->Next;
        if((*start)->value==p1->value)
        {
            if((*start)->Next->value==p2->value)
            {
                 CURR->Next=p2->Next;
                 p2->Next=p1;
                 *start=p2;
            }
            else
            {
                while(CURR->Next!=NULL)
                {
                    if(CURR->Next->value==p2->value)
                    {
                        p2prev=CURR;
                    }
                    if(p2->Next==NULL)
                    {
                       temp=NULL;
                    }
                    CURR=CURR->Next;
                }

                CURR=(*start);
                *start=p2;
                p2->Next=p1->Next;
                p2prev->Next=p1;
                p1->Next=temp;
            }
        }

        else
        {
            while(CURR->Next!=NULL)
            {
                if((CURR->Next)->value==p1->value)
                {
                    p1prev=CURR;
                }
                if(CURR->Next->value==p2->value)
                {
                    p2prev=CURR;
                }
                CURR=CURR->Next;
            }
            if(p2prev->value==p1->value)
            {
                p1prev->Next=p2;
                p2->Next=p1;
                p1->Next=temp;
            }
            else
            {
                p1prev->Next=p2;
                p2->Next=p1->Next;
                p2prev->Next=p1;
                p1->Next=temp;
            }
        }
    }
}
void insert(NODE **start)
{
    struct NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    cout<<"Enter Input=";
    cin>>ptr->value;
      if(*start==NULL)
    {
        *start=ptr;
    }
    else
    {
         struct NODE *CURR=*start;
         while(CURR->Next!=NULL)
         {
             CURR=CURR->Next;
         }
         CURR->Next=ptr;
    }

}
void display(NODE *start)
{
    struct NODE *CURR=start;
         while(CURR->Next!=NULL)
         {
             cout<<CURR->value<<endl;
             CURR=CURR->Next;
         }
         cout <<CURR->value<<endl;
}
void deletee(NODE **start)
{
    int input;
    cout<<"Which Number You Want to Delete:";
    cin>>input;

    struct NODE *CURR=(*start)->Next,*prev=*start;
    if((*start)->value==input)
    {
        CURR=(*start)->Next;
        free(start);
        *start=CURR;

    }
    else
    {
        while(CURR->value!=NULL)
        {
            if(CURR->value==input)
            {
                prev->Next=CURR->Next;
                break;
            }
            prev=CURR;
            CURR=CURR->Next;
        }


    }

}
NODE* search(struct NODE *start)
{
    int flag;
    int input;
    cout<<"Which Number You Want to Search:";
    cin>>input;

    struct NODE *CURR=start;
    while(CURR!=NULL)
    {
        if(CURR->value==input)
        {
            return CURR;
        }
        CURR=CURR->Next;
    }
}


int main()
{
    struct NODE *start=NULL,*temp=(NODE*)malloc(sizeof(NODE)),*temp1=(NODE*)malloc(sizeof(NODE));

    insert(&start);
    insert(&start);


    Selection_Sort(&start);

    display(start);
}
