#include <iostream>
#include<stdlib.h>
using namespace std;
#define nullptr NULL;
struct Node
{
    int value;
    Node *next=NULL;
};
int OpenHashFuction();
void Insert(Node **Array);

int main()
{
    Node *Array;
    Array=new Node[10];
    Insert(&Array);

}
int OpenHashFuction(int n,int input)
{
    return input%n;
}
void Insert(Node **Array)
{
    int input;
    cout<<"Enter Input=";
    cin>>input;
    int index=OpenHashFuction(10,input);
    while(Array[index]!=NULL)
    {
        cout<<"In while";
        Array[index]=(Node*)Array[index]->next;
        cout<<"In while";
    }
    cout<<"after  while";
    cout<<(*Array[index]).value;
    (*Array[index]).value=input;
    cout<<"after  Assignment";
}
