#include <iostream>
#include<stdlib.h>
using namespace std;

struct NODE
{
    int value;
    NODE *Next=NULL;
};
NODE* insert(NODE *start,int val);
void display(NODE *start);
NODE* search(NODE *start,int val);
NODE* deletee(NODE *start,int val);
void swapNodes(NODE **start,NODE *ptr1,struct NODE *ptr2);
NODE* FindPrevious(NODE *start,NODE *ptr);
NODE* FindMin(NODE *start);
void SelectionSort(NODE **start);
void BubbleSort(NODE **start);
void InsertionSort(NODE **start)

NODE* insert(NODE *start,int val)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->value=val;
    ptr->Next=NULL;
    if(start==NULL)
    {
        start=ptr;
        return start;
    }
    else
    {
        start->Next=insert(start->Next,val);
    }
}
NODE* search(NODE *start,int val)
{
    if(start!=NULL)
    {
        if(start->value==val)
        {
            cout<<"Value Found";
            return start;
        }
        else
        {
            search(start->Next,val);
        }
    }
    else
    {
        cout<<"Value Not Found";
        return NULL;
    }
}
NODE* deletee(NODE *start,int val)
{
    if(start->value==val)
    {
        NODE *ptr=start->Next;
        free(start);
        start=ptr;
        return start;
    }
    else
    {
        if(start->Next!=NULL)
        {
            if(start->Next->value==val)
            {
                NODE *ptr=start->Next->Next;
                free(start->Next);
                start->Next=ptr;
            }
            else
            {
                start->Next=deletee(start->Next,val);
                return start;
            }
        }
        else
        {
            cout<<"Value Not Found";
        }
    }
}
NODE* FindPrevious(NODE *start,NODE *ptr)
{
    if(start->Next==ptr)
    {
        return start;
    }
    else
    {
        FindPrevious(start->Next,ptr);
    }
}
void display(NODE *start)
{
    if(start!=NULL)
    {
        cout<<start->value<<endl;
        display(start->Next);
    }
}
NODE* FindMin(NODE *start)
{
    NODE *CURR=start;
    NODE* MIN=start;
    while(CURR->Next!=NULL)
    {
        if(MIN->value>CURR->Next->value)
        {
            MIN=CURR->Next;
        }
        CURR=CURR->Next;
    }
    return MIN;

}
void SelectionSort(NODE **start)
{
    NODE *CURR=*start;
    while(CURR->Next!=NULL)
    {
        NODE *MIN=FindMin(CURR);
        swapNodes(start,CURR,MIN);
        CURR=MIN;
        CURR=CURR->Next;
    }
}
void swapNodes(NODE **start,NODE *ptr1,struct NODE *ptr2)
{
    if(ptr1->Next==ptr2)
    {
        NODE *ptr=(NODE*)malloc(sizeof(NODE)),* p2prev=NULL;
        ptr1->Next=ptr2->Next;
        if(ptr1==(*start))
        {
            *start=ptr2;
            (*start)->Next=ptr1;
        }
        else
        {
            p2prev=FindPrevious(*start,ptr1);
            p2prev->Next=ptr2;
            ptr2->Next=ptr1;
        }
    }
    else if(ptr1==*start)
    {
        NODE *ptr=(NODE*)malloc(sizeof(NODE)),*p2prev=FindPrevious(*start,ptr2);
        ptr=ptr1->Next;
        p2prev->Next=ptr1;
        ptr1->Next=ptr2->Next;
        ptr2->Next=ptr;
        *start=ptr2;
    }
    else if(ptr2==*start)
    {
        NODE *ptr=(NODE*)malloc(sizeof(NODE)),*p2prev=FindPrevious(*start,ptr1);
        ptr=ptr2->Next;
        p2prev->Next=ptr2;
        ptr2->Next=ptr1->Next;
        ptr1->Next=ptr;
        *start=ptr1;
    }
    else
    {
        NODE *ptr=(NODE*)malloc(sizeof(NODE)),*p1prev=FindPrevious(*start,ptr1),*p2prev=FindPrevious(*start,ptr2);
        ptr=ptr2->Next;
        p1prev->Next=ptr2;
        ptr2->Next=ptr1->Next;
        p2prev->Next=ptr1;
        ptr1->Next=ptr;
    }
}
void BubbleSort(NODE **start)
{
    NODE* CURR=*start,*last=NULL;
    while(last!=(*start)->Next)
    {

        CURR=*start;
        while(CURR->Next!=NULL)
        {
            if(CURR->value > CURR->Next->value)
            {
                swapNodes(start,CURR,CURR->Next);

            }
            CURR=CURR->Next;
            if(CURR->Next==last)
            {
                last=CURR;
            }
        }
    }
}
void InsertionSort(NODE **start)
{
    int temp;
    NODE *CURR=*start;
    while(CURR->Next!=NULL)
    {
        if(CURR->value > CURR->Next->value)
        {

        }
    }

}
int main()
{
    NODE *start=NULL;
    start=insert(start,99);
    start=insert(start,3);
    start=insert(start,6);
    start=insert(start,1);
    start=insert(start,7);
     start=insert(start,23);
    start=insert(start,45);
    start=insert(start,789);

    display(start);
    cout<<endl;
    search(start,1);

    cout<<endl;

    BubbleSort(&start);
     display(start);
}
