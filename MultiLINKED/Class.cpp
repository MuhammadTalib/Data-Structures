#include "Class.h"

void Class::insert_Class(Class **start)
{
     Class *ptr=(Class*)malloc(sizeof(Class)),*CURR=*start;

    cout<<"Enter Class Name:";
    cin>>ptr->Name;

    cout<<"Total Students in class:";
    cin>>ptr->Total_Students;
    cout<<"Total:"<<ptr->Total_Students<<endl;

    ptr->next=NULL;

    if((*start)==NULL)
    {
        *start=ptr;
    }
    else
    {
        cout<<"in else"<<endl;
        while(CURR->next!=NULL)
        {
            cout<<"in while"<<endl;
            CURR=CURR->next;
        }
        CURR->next=ptr;
    }
}
void Class::display_classes(Class *start)
{
    struct Class *CURR=start;
    while(CURR!=NULL)
    {
        cout<<"Class Name:"<<CURR->Name<<endl;
        cout<<"Total Students:"<<CURR->Total_Students<<endl<<endl;
        CURR=CURR->next;
    }
}

