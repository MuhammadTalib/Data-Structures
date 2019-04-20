#include <iostream>
#include<stdlib.h>
using namespace std;
struct BST
{
    int data;
    int height;
    BST *LeftChild=NULL;
    BST *RightChild=NULL;
};
BST* findparent(struct BST *node,struct BST *CURR);
int getheight(struct BST *CURR);
void insertNode(BST **root);
void InOrder(struct BST *Root);
void insert(struct BST **start,int data);
void checkheight();
void shiftleft(BST **node);
void ShiftRight(BST **node);
void PreOrder(struct BST *Root);
int abs(int a);
int main()
{
    cout<<"AVL"<<endl;


    struct BST *root=NULL;

    insert(&root,135);
    insert(&root,120);
    insert(&root,30);

    insert(&root,60);
    insert(&root,20);
    insert(&root,18);

    insert(&root,75);
    insert(&root,87);
    insert(&root,56);

    insert(&root,93);
    insert(&root,150);
    insert(&root,22);

    insert(&root,69);
    insert(&root,70);
     insert(&root,74);


   cout<<endl<<"Display"<<endl;
   InOrder(root);
cout<<endl;
    PreOrder(root);


}
void insert(struct BST **start,int data)
{
	struct BST *ptr=(BST*)malloc(sizeof(BST));
	ptr->data=data;
	ptr->LeftChild=NULL;
	ptr->RightChild=NULL;

	if((*start)==NULL)
	{
		*start=ptr;
		(*start)->height=0;
	}
	else
	{
		struct BST *CURR=*start;
		while(CURR!=NULL)
		{
			if(ptr->data >= CURR->data)
			{
				if(CURR->RightChild==NULL)
				{
                    CURR->RightChild=ptr;
                    CURR->RightChild->height=0;

					break;
				}
				else if(CURR->RightChild!=NULL)
				{
					CURR=CURR->RightChild;
				}
			}
			else if(ptr->data < CURR->data)
			{
				if(CURR->LeftChild==NULL)
				{
					CURR->LeftChild=ptr;
					CURR->LeftChild->height=0;

					break;
				}
				else if(CURR->LeftChild!=NULL)
				{
					CURR=CURR->LeftChild;
				}
			}
		}
		cout<<endl<<ptr->data<<endl<<endl;
		InOrder(*start);

		while(1)
        {
            if(getheight(CURR->RightChild) > getheight(CURR->LeftChild))
            {
                    CURR->height=(CURR->RightChild->height)+1;

                    if((abs(getheight(CURR->LeftChild) - getheight(CURR->RightChild)))>1)
                    {
                        cout<<endl<<CURR<<"UNBALA"<<endl;
                        if(getheight(CURR->RightChild->LeftChild) > getheight(CURR->RightChild->RightChild))
                        {
                                BST *nodeparent=findparent(*start,CURR->RightChild);
                                ShiftRight(&(CURR->RightChild));
                        }
                        if(getheight(CURR->RightChild) > getheight(CURR->LeftChild))
                        {
                            cout<<endl<<"Normal case"<<endl;
                            if(CURR==*start)
                            {
                                shiftleft(start);
                                CURR=(*start);
                            }
                            else
                            {
                                BST *nodeparent=findparent(*start,CURR);
                                if(CURR->data==nodeparent->LeftChild->data)
                                {
                                    shiftleft(&CURR);
                                    nodeparent->LeftChild=CURR;
                                }
                                else if(CURR->data==nodeparent->RightChild->data)
                                {
                                    shiftleft(&CURR);
                                    nodeparent->RightChild=CURR;
                                }
                                break;
                            }
                        }
                    }
                    if(CURR!=*start)
                    {
                        CURR=findparent(*start,CURR);
                    }
                    else
                    {
                        cout<<endl<<"balanced"<<endl;
                        break;
                    }
            }
            else
            {
                CURR->height=(CURR->LeftChild->height)+1;

                if((abs(getheight(CURR->LeftChild) - getheight(CURR->RightChild)))>1)
                {
                    if(getheight(CURR->LeftChild->RightChild) > getheight(CURR->LeftChild->LeftChild))
                    {
                        shiftleft(&(CURR->LeftChild));
                    }
                    if(getheight(CURR->RightChild) < getheight(CURR->LeftChild))
                    {
                        if(CURR==*start)
                        {
                            ShiftRight(start);
                            CURR=(*start);
                        }
                        else
                        {
                            BST *nodeparent=findparent(*start,CURR);
                            if(CURR->data==nodeparent->LeftChild->data)
                            {
                                ShiftRight(&CURR);
                                nodeparent->LeftChild=CURR;
                            }
                            else if(CURR->data==nodeparent->RightChild->data)
                            {
                                ShiftRight(&CURR);
                                nodeparent->RightChild=CURR;
                            }
                            break;
                        }
                    }
                    }
                    if(CURR!=*start)
                    {
                        CURR=findparent(*start,CURR);
                    }
                    else
                    {
                        break;
                    }
            }
        }
    }
}
void PreOrder(struct BST *Root)
{
    if(Root!=NULL)
    {
        cout<<Root->data<<endl;
        if(Root->LeftChild!=NULL)
        {
            PreOrder(Root->LeftChild);
        }
        PreOrder(Root->RightChild);

    }
}
void InOrder(struct BST *Root)
{
    if(Root!=NULL)
    {
        if(Root->LeftChild!=NULL)
        {
            InOrder(Root->LeftChild);
        }
        cout<<Root->data<<endl;
        InOrder(Root->RightChild);
    }
}
int getheight(struct BST *CURR)
{
    if(CURR==NULL)
    {
        return -1;
    }
    else
    {
        return CURR->height;
    }

}
int abs(int a)
{
    if(a<0)
    {
        return (-1*a);
    }
    return a;
}
void shiftleft(BST **node)
{

    BST *CURR=(BST*)malloc(sizeof(BST));

    CURR->data=(*node)->data;
    CURR->height= ((*node)->RightChild->height)-1;
    CURR->LeftChild=(*node)->LeftChild;
    CURR->RightChild=(*node)->RightChild->LeftChild;

    (*node)->RightChild->LeftChild=CURR;
    *node=(*node)->RightChild;
}
void ShiftRight(BST **node)
{

    BST *CURR=(BST*)malloc(sizeof(BST));

    CURR->data=(*node)->data;
    CURR->height= ((*node)->LeftChild->height)-1;
    CURR->LeftChild=(*node)->LeftChild->RightChild;
    CURR->RightChild=(*node)->RightChild;

    (*node)->LeftChild->RightChild=CURR;
    *node=(*node)->LeftChild;
}

BST* findparent(BST *node,BST *CURR)
{

    if( node->RightChild!=NULL && node->RightChild->data==CURR->data)
    {
        return node;
    }
    if( node->LeftChild!=NULL && node->LeftChild->data==CURR->data)
    {
        return node;
    }

    else if(CURR->data > node->data)
    {
        findparent(node->RightChild,CURR);
    }
    else if(CURR->data < node->data)
    {
        findparent(node->LeftChild,CURR);
    }
}
