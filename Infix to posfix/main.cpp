
#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct NODE
{
    char value;
    struct NODE *Next=NULL;
};
struct BinaryTree
{
    char value;
    struct BinaryTree *RightChild=NULL;
    struct BinaryTree *LeftChild=NULL;
};
struct StackNode
{
    BinaryTree *value;
    struct StackNode *Next=NULL;
};

void push(NODE **top,char value);
char pull(NODE **top);
void InfixToPostfixConversion(NODE *start,NODE **postfix);
void PostfixtoTreeConversion(BinaryTree **root,NODE *postfix);
void InfixToPrefixConversion(NODE *start,NODE **prefix);
int Evaluate(NODE *CURR);
void display(NODE *start);
void InOrder(struct BinaryTree *Root);
void reverseNode(NODE **start);

int CheckPrecedence(char value)
{
    if(value=='|')
        return 1;
    else if(value=='&')
        return 2;
    else if(value=='<' || value=='>' || value=='=' || value=='~')
        return 3;
    else if(value=='-' || value=='+')
        return 4;
    else if(value=='/' || value=='*')
        return 5;
    else
        return NULL;

}

void InfixToPostfixConversion(NODE *start,NODE **postfix)
{
    NODE *top=(NODE*)malloc(sizeof(NODE)),*CURR=(NODE*)malloc(sizeof(NODE)),*PostfixCurr=*postfix,*TopCurr;
    CURR=start;
    top=NULL;
    if(CURR==start)
    {
        (*postfix)->value=CURR->value;
        (*postfix)->Next=NULL;
        CURR=CURR->Next;
    }
    while(CURR!=NULL)
    {
        if((CURR->value>='a' && CURR->value<='z')||(CURR->value>='A' && CURR->value<='Z')||(CURR->value>='0' && CURR->value<='9'))
        {
            PostfixCurr->Next=CURR;
            PostfixCurr=PostfixCurr->Next;
        }
        else if(CURR->value=='*' || CURR->value=='+' || CURR->value=='-' || CURR->value=='/' || CURR->value=='=' || CURR->value=='>' || CURR->value=='<' || CURR->value=='~' ||CURR->value=='&' || CURR->value=='|' || CURR->value=='('||CURR->value==')')
        {
            while(1)
            {
                if(top==NULL || CheckPrecedence(top->value)<CheckPrecedence(CURR->value) || CURR->value=='(' || top->value=='(')
                {

                    push(&top,CURR->value);
                    TopCurr=top;
                    break;
                }
                else if( (CheckPrecedence(top->value)>=CheckPrecedence(CURR->value)) && CURR->value != ')' )
                {
                    PostfixCurr->Next=top;
                    PostfixCurr=PostfixCurr->Next;
                    pull(&top);
                }
                else if(CURR->value == ')')
                {

                    while(top->value!='(')
                    {
                        PostfixCurr->Next=top;
                        PostfixCurr=PostfixCurr->Next;
                        cout<<PostfixCurr->Next->value;

                        pull(&top);
                    }

                    pull(&top);
                    break;
                }

            }
        }
        CURR=CURR->Next;

    }
    while(top!=NULL)
    {
        PostfixCurr->Next=top;
        PostfixCurr=PostfixCurr->Next;
        pull(&top);
    }

}
void display(NODE *start)
{
    struct NODE *CURR=start;
    while(CURR!=NULL)
    {
        cout<<CURR->value;
        CURR=CURR->Next;
    }
}
void insertt(NODE **start)
{
    struct NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    ptr->value=getche();
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

void BTpush(StackNode **top,BinaryTree* value)
{
    StackNode *ptr=(StackNode*)malloc(sizeof(StackNode));
    ptr->value=value;
    ptr->Next=NULL;

    if(*top==NULL)
    {
        *top=ptr;
    }
    else
    {
        ptr->Next=*top;
        *top=ptr;
    }
}
BinaryTree* BTpull(StackNode **top)
{
    StackNode *CURR=*top;
    *top=(*top)->Next;
    return CURR->value;
}
void push(NODE **top,char value)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->value=value;
    ptr->Next=NULL;

    if(*top==NULL)
    {
        *top=ptr;
    }
    else
    {
        ptr->Next=*top;
        *top=ptr;
    }
}
int intpull(NODE **top)
{
    NODE *CURR=*top;
    *top=(*top)->Next;
    return CURR->value;
}
char pull(NODE **top)
{
    NODE *CURR=*top;
    *top=(*top)->Next;
    return CURR->value;
}
int main()
{

    NODE* Infix=NULL,*Postfix=(NODE*)malloc(sizeof(NODE)),*Prefix=(NODE*)malloc(sizeof(NODE));
    BinaryTree *root=(BinaryTree*)malloc(sizeof(BinaryTree));
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);

    InfixToPostfixConversion(Infix,&Postfix);

 //   PostfixtoTreeConversion(&root,Postfix);


    cout<<"Evaluated Value=" <<Evaluate(Postfix)<<endl;


}
void PostfixtoTreeConversion(BinaryTree **root,NODE *postfix)
{
    StackNode *top=(StackNode*)malloc(sizeof(StackNode));
    NODE *CURR=postfix;
    while(CURR!=NULL)
    {
        if((CURR->value>='a' && CURR->value<='z')||(CURR->value>='A' && CURR->value<='Z')||(CURR->value>='0' && CURR->value<='9'))
        {
            BinaryTree *ptr=(BinaryTree*)malloc(sizeof(BinaryTree));
            ptr->value=CURR->value;
            ptr->LeftChild=NULL;
            ptr->RightChild=NULL;
            BTpush(&top,ptr);
        }
        else if(CURR->value=='*' || CURR->value=='+' || CURR->value=='-' || CURR->value=='/' || CURR->value=='=' || CURR->value=='>' || CURR->value=='<' || CURR->value=='~' ||CURR->value=='&' || CURR->value=='|')
        {
            BinaryTree *ptr=(BinaryTree*)malloc(sizeof(BinaryTree));
            ptr->value=CURR->value;
            ptr->RightChild=BTpull(&top);
            ptr->LeftChild=BTpull(&top);
            BTpush(&top,ptr);
        }
        CURR=CURR->Next;
    }
    *root=BTpull(&top);
}
int Evaluate(NODE *CURR)
{
    cout<<endl;
    struct NODE *top=NULL;
    int variables[120]={NULL};
    while(CURR!=NULL)
    {
        if((CURR->value>='a' && CURR->value<='z')||(CURR->value>='A' && CURR->value<='Z'))
        {
            if(variables[CURR->value-65]==NULL)
            {
                cout<<"Enter Value of "<<CURR->value<<" :";
                cin>>variables[CURR->value-65];
            }
            push(&top,variables[CURR->value-65]);
        }
        else if(CURR->value>='0' && CURR->value<='9')
        {
            push(&top,CURR->value-48);
        }
        else if(CURR->value=='*' || CURR->value=='+' || CURR->value=='-' || CURR->value=='/' || CURR->value=='=' || CURR->value=='>' || CURR->value=='<' || CURR->value=='~' ||CURR->value=='&' || CURR->value=='|')
        {
            int temp=0,tempo=0;
            switch(CURR->value)
            {
                case('+'):
                {
                    temp=intpull(&top)+intpull(&top);
                    break;
                }
                case('*'):
                {
                    temp=intpull(&top)*intpull(&top);
                    break;
                }
                case('-'):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)-tempo;
                    break;
                }
                case('/'):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)/tempo;
                    break;
                }
                case('<'):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)<tempo;
                    break;
                }
                case('>'):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)>tempo;
                    break;
                }
                case('|'):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)||tempo;
                    break;
                }
                case('&'):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)&&tempo;
                    break;
                }
                case('~'):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)!=tempo;
                    break;
                }
                case('='):
                {
                    tempo=intpull(&top);
                    temp=intpull(&top)==tempo;
                    break;
                }

            }
            push(&top,temp);

        }
        CURR=CURR->Next;
    }
    return pull(&top);
}
void InOrder(struct BinaryTree *Root)
{
    if(Root!=NULL)
    {
        if(Root->LeftChild!=NULL)
        {
            InOrder(Root->LeftChild);
        }
        cout<<Root->value;
        InOrder(Root->RightChild);
    }

}
void reverseNode(NODE **start)
{
    NODE *CURR=(NODE*)malloc(sizeof(NODE)),*top=(NODE*)malloc(sizeof(NODE));
    top=NULL;
    while(*start!=NULL)
    {
        push(&top,(*start)->value);
        *start=(*start)->Next;
    }
    *start=CURR;
    while(top!=NULL)
    {
        CURR->value=top->value;
        CURR->Next=(NODE*)malloc(sizeof(NODE));
        pull(&top);
        CURR=CURR->Next;
    }

}
void InfixToPrefixConversion(NODE *start,NODE **prefix)
{
    NODE *CURR=(NODE*)malloc(sizeof(NODE));
    NODE *Postfix=(NODE*)malloc(sizeof(NODE));
    reverseNode(&start);
    display(start);
    cout<<endl;
    CURR=start;
    while(CURR!=NULL)
    {
        if(CURR->value==')')
        {
            CURR->value='(';
        }
        else if(CURR->value=='(')
        {
            CURR->value=')';
        }
        CURR=CURR->Next;
    }
    display(start);
    cout<<endl<<"postfix"<<endl;
    InfixToPostfixConversion(start,prefix);

    reverseNode(prefix);
    display(*prefix);

    cout<<endl;
    NODE *alphatop=(NODE*)malloc(sizeof(NODE)),*operatop=(NODE*)malloc(sizeof(NODE));
    alphatop=NULL;
    operatop=NULL;

    while(CURR!=NULL)
    {
        if((CURR->value>='a' && CURR->value<='z')||(CURR->value>='A' && CURR->value<='Z'))
        {
            push(&alphatop,CURR->value);
        }
        else if (CURR->value=='*' || CURR->value=='+' || CURR->value=='-' || CURR->value=='/' || CURR->value=='=' || CURR->value=='>' || CURR->value=='<' || CURR->value=='~' ||CURR->value=='&' || CURR->value=='|')
        {
            if(operatop==NULL || (CheckPrecedence(operatop->value)<CheckPrecedence(CURR->value)))
            {
                push(&operatop,CURR->value);
            }
            else if(CheckPrecedence(operatop->value)>=CheckPrecedence(CURR->value))
            {
                push(&alphatop,operatop->value);
                pull(&operatop);
                push(&operatop,CURR->value);
            }
        }
        CURR=CURR->Next;
    }
    while(operatop!=NULL)
    {
        push(&alphatop,operatop->value);
        pull(&operatop);
    }
    *prefix=alphatop;
}
