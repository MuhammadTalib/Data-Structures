#include<iostream>
using namespace std;
class nary
{
  public:
  void insert(int value,int size,nary**root)
  {
    int i;
    nary *temp=new nary;
    temp->data = value;
    temp->node = new nary*[size];
    for(i=0;i<size;i++)
    {
      temp->node[i]=NULL;
    }
    if(*root == NULL)
    {
      *root= temp;
    }
    else
    {

      int count=0;
      i=0;
      while((*root)->node[i] !=NULL)
      {
        if(i>size)
        {
          count++;
          break;
        }
        else
        {
          i++;
        }
      }
      if(count==0)
      {
        (*root)->node[i] = temp;
      }
      else
      {
        insert( value, size,&temp->node[0]);
      }
    }

  }

  void print(nary *root)
  {
    nary *curr=root;
    cout<<"Root : "<<root->data;
    root=root->node[0];
    cout<<endl<<"child 1: "<<root->data<<endl;
    root=curr->node[1];
    cout<<"child 2: "<<root->data<<endl;
    root=curr->node[2];
    cout<<"child 3: "<<root->data<<endl;
    root=curr->node[3];
    cout<<"child 4: "<<root->data<<endl;
    //root=root->node[4];
    //cout<<"Root : 5"<<root->data;

  }
  private:
  int data;
  nary* *node;
};
