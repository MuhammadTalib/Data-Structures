#include <iostream>
#include<stdlib.h>
using namespace std;

struct NaryTree
{
    int value;
    NaryTree **child=NULL;
};
void insert(NaryTree **tree,int val);
int main()
{
    NaryTree *tree=NULL;
    insert(&tree,3);
    cout<<tree->value;
}
void insert(NaryTree **tree,int val)
{
    NaryTree *ptr=(NaryTree*)malloc(sizeof(NaryTree));
    ptr->value=val;
    ptr->child=NULL;
    if(*tree==NULL)
    {
        *tree=ptr;
    }
}
