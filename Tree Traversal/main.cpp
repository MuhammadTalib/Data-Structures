#include<iostream>
#include<stdlib.h>
using namespace std;

struct BTNode
{
	int value;
	struct BTNode *LeftChild=NULL;
	struct BTNode *RightChild=NULL;
};
int j=0;
void insert(BTNode **start);
BTNode* BinarySearchTree(BTNode *start);
void display(BTNode *start);
void deletee(BTNode **start);
void insert_recursion(BTNode **start);
BTNode* FindMax(BTNode *start);
BTNode* FindParent(BTNode *start,BTNode *child);
void InOrder(struct BTNode *Root)
{
    if(Root!=NULL)
    {
        if(Root->LeftChild!=NULL)
        {
            InOrder(Root->LeftChild);
        }
        cout<<Root->value<<endl;
        InOrder(Root->RightChild);
    }

}
void PostOrder(struct BTNode *Root)
{
    if(Root!=NULL)
    {
        if(Root->LeftChild!=NULL)
        {
            PostOrder(Root->LeftChild);
        }
        PostOrder(Root->RightChild);
        cout<<Root->value<<endl;
    }
}
void PreOrder(struct BTNode *Root)
{
    if(Root!=NULL)
    {
        cout<<Root->value<<endl;
        if(Root->LeftChild!=NULL)
        {
            PreOrder(Root->LeftChild);
        }
        PreOrder(Root->RightChild);

    }
}
int main()
{
	struct BTNode *root=NULL,*copyroot=root;
	struct BTNode *ptr=(BTNode*)malloc(sizeof(BTNode));
	insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);

    cout<<endl;

    cout<<"InOrder Traversal";
    InOrder(root);

    cout<<"PreOrder Traversal";
    PreOrder(root);

    cout<<"PostOrder Traversal";
    PostOrder(root);

}

void insert(struct BTNode **start)
{
	struct BTNode *ptr=(BTNode*)malloc(sizeof(BTNode));
	cin>>ptr->value;
	ptr->LeftChild=NULL;
	ptr->RightChild=NULL;


	if((*start)==NULL)
	{
		*start=ptr;
	}
	else
	{
		struct BTNode *CURR=*start;
		while(CURR!=NULL)
		{
			if(ptr->value >= CURR->value)
			{
				if(CURR->RightChild==NULL)
				{
					CURR->RightChild=ptr;
					break;
				}
				else if(CURR->RightChild!=NULL)
				{
					CURR=CURR->RightChild;
				}
			}
			else if(ptr->value < CURR->value)
			{
				if(CURR->LeftChild==NULL)
				{
					CURR->LeftChild=ptr;
					break;
				}
				else if(CURR->LeftChild!=NULL)
				{
					CURR=CURR->LeftChild;
				}
			}


		}
	}
}
int i=0,input;
BTNode* BinarySearchTree(BTNode *start)
{
    if(i==0)
    {
         cin>>input;
         i++;
    }
    BTNode *CURR=start;
    while(CURR!=NULL)
    {

        if(input==CURR->value)
        {
            return CURR;
        }
        else if(input<CURR->value)
        {
            CURR=CURR->LeftChild;
            BinarySearchTree(CURR);
        }
        else if(input>CURR->value)
        {
            CURR=CURR->RightChild;
            BinarySearchTree(CURR);
        }
    }
    if(CURR==NULL)
    {
        return NULL;
    }
}
void display(BTNode *start)
{
	BTNode *CURR=start;
	if(CURR!=NULL)
	{

		cout<<CURR->value<<endl;

		display(CURR->LeftChild);

		display(CURR->RightChild);
	}

}
void insert_recursion(BTNode **start)
{
    struct BTNode *ptr2=(BTNode*)malloc(sizeof(BTNode));
    ptr2->value=134;
    ptr2->LeftChild=NULL;
    ptr2->RightChild=NULL;
    *start=ptr2;

    struct BTNode *ptr3=(BTNode*)malloc(sizeof(BTNode));
    ptr3->value=112;
    ptr3->LeftChild=NULL;
    ptr3->RightChild=NULL;

    *start=(*start)->LeftChild;
    cout<<"1111";
    *start=ptr3;
}
BTNode* FindMax(BTNode *start)
{
    if(start->RightChild==NULL)
    {
        return start;
    }
    else if(start->RightChild!=NULL)
    {
        FindMax(start->RightChild);
    }
}
BTNode* FindParent(BTNode *start,BTNode *child)
{
    if(start->LeftChild==child || start->RightChild==child)
    {
        return start;
    }
    if(start->value > child->value)
    {
        FindParent(start->LeftChild,child);
    }
    if(start->value < child->value)
    {
        FindParent(start->RightChild,child);
    }
}
void deletee(BTNode **start)
{
    BTNode *CURR=*start,*prev=NULL;
    if(j==0)
    {
        cout<<"Which Number You want to delete:";
        cin>>input;
        j++;
    }
    if((*start)->value==input)
    {
        if((*start)->RightChild==NULL)
        {
            *start=(*start)->LeftChild;
        }
        else if((*start)->LeftChild==NULL)
        {
            *start=(*start)->RightChild;
        }
        else if((*start)->LeftChild==NULL && (*start)->RightChild==NULL)
        {
            *start=NULL;
        }
        else
        {
            CURR=FindMax((*start)->LeftChild);
            cout<<"1";
            CURR->LeftChild=(*start)->LeftChild;
            cout<<"2";
            CURR->RightChild=(*start)->RightChild;
            cout<<"3";
            *start=CURR;
            cout<<"4";
            BTNode* parent=FindParent(*start,CURR);
            cout<<"5";
            free(parent->RightChild);
            cout<<"ddwf";

        }
    }
    else
    {
        while(CURR!=NULL)
        {
            if(CURR->value==input)
            {
                if(CURR==prev->LeftChild)
                {
                    if(CURR->RightChild==NULL)
                    {
                        prev->LeftChild=CURR->LeftChild;
                        free(CURR);
                    }
                    else if(CURR->LeftChild==NULL)
                    {
                        prev->LeftChild=CURR->RightChild;
                        free(CURR);
                    }
                }
                else if(CURR==prev->RightChild)
                {
                    if(CURR->RightChild==NULL)
                    {
                        prev->RightChild=CURR->LeftChild;
                        free(CURR);
                    }
                    if(CURR->LeftChild==NULL)
                    {
                        prev->RightChild=CURR->RightChild;
                        free(CURR);
                    }
                }
                else if(CURR->LeftChild==NULL && CURR->RightChild==NULL)
                {
                    CURR=NULL;
                    free(CURR);
                }
                break;

            }
            if(CURR->value > input)
            {
                prev=CURR;
                CURR=CURR->LeftChild;
            }
            else if(CURR->value < input)
            {
                prev=CURR;
                CURR=CURR->RightChild;
            }
        }

    }

}
