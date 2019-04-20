#include <iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node **child=NULL;
};
void insert(Node **start)
{
    (*start)->data=10;
}
int main()
{
    Node *start=(Node*)malloc(sizeof(Node));
    insert(&start);
    cout<<start->data;
}

