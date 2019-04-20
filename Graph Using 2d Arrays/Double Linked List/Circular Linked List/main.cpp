#include <iostream>
#include<stdlib.h>
using namespace std;
struct NODE
{
    int value;
    struct NODE *Next=NULL;
};
void insert();
struct NODE *ptr=(NODE*)malloc(sizeof(NODE));

struct NODE *endd=NULL;
void insert()
{
    cout<<"Enter Input=";
    cin>>ptr->value;
    if(endd==NULL)
    {
        endd=ptr;
    }
    else
    {
         struct NODE *CURR;

         cout<<"{"<<endd->value<<"}"<<endl;
         cout<<CURR->value<<endl;
         cout<<ptr->value<<endl;


         endd->Next=ptr;
         CURR->Next=endd;

          cout<<endd->Next->value<<endl;
        cout<<CURR->Next->value<<endl;
           cout<<endd->value<<endl;

    }

}
void display()
{
    cout<<"in display";
    struct NODE *CURR=endd->Next;
         while(CURR!=endd)
         {
             cout<<"In while";
             cout<<CURR->value<<endl;
             CURR=CURR->Next;
         }
}

int main()
{
    insert();
     cout<<endd->value<<endl;
    insert();
     cout<<endd->value<<endl;
     cout<<endd->Next->value<<endl;
    insert();
     cout<<endd->value<<endl;
     cout<<endd->Next->value<<endl;
    insert();
     cout<<endd->value<<endl;
     cout<<endd->Next->value<<endl;

    display();

}
