#include <iostream>
#include <stdlib.h>
#include<stdio.h>
using namespace std;

struct Edge
{
    void *value=NULL;
    Edge *Next=NULL;
    int weight=0;
};
struct Vertex
{
    char value;
    Edge *edge=NULL;
    Vertex *Next=NULL;
    bool visited=false;
};
struct Edges
{
    Vertex *FisrtVertex=NULL;
    Vertex *SecondVertex=NULL;
    Edges *Next=NULL;
    int weight;
};


void insert(Vertex **vertex,char value);
void display(Vertex *vertex);
void displayEdge(Edge *edge);
void AddEdge(Edge **edge,Vertex *vertex);
void setconnections(Vertex **vertex);
void DepthfirstTraversal(Vertex *vertex);
void BreadthfirstTraversal(Vertex *vertex);
Vertex* BreadthfirstSearch(Vertex *vertex,int find);
Vertex* pull(Edge **top);
void push(Edge **top,Vertex* value);
struct Edge* top=(Edge*)malloc(sizeof(Edge));
void enqueue(Edge **top,Vertex* value);
Vertex* dequeue(Edge **top);
bool path(Vertex *source,Vertex *destination);
void makedAllFalse(Vertex **vertex);
Vertex* KrushkalSpanningTree(Vertex *vertex);
void Sort(Vertex **vertex);
void swap(struct Edge **start,struct Edge *p1,struct Edge *p2);
void Selection_Sort(Edges **start);
void Selection_SortV(Vertex **start);
void Bubble_Sort(struct Edge**start);
Edge* FindMin(Edge *start);
Vertex* FindMinVertex(Vertex *start);
void Selection_Sort_Vertex(Vertex **start);
void ArrangeEdges(Vertex *start,Edges **E);
void displayKedges(Edges *E);
void swap(struct Edges **start,struct Edges **p1,struct Edges **p2);
Edges* FindMin(Edges *start);
int TotalVertices(Vertex *vertex);
bool intersection(Vertex** V1,Vertex **V2);
Vertex* findVertex(Vertex* V,Vertex* S);
void AddEdgeE(Edge **edge,Vertex *vertex,int weight);
Vertex** Union(Vertex** V1,Vertex **V2,int TotalVertices);
int main()
{


/*
    Vertex* Verte=NULL;
    insert(&Verte,'A');

    Queue *top=(Queue*)malloc(sizeof(Queue));

    top->enqueue(&top,Verte);

    cout<<"v="<<((Vertex*)(top->dequeue(&top)))->value<<endl;
*/

    top=NULL;
    Vertex* Vertex=NULL;
    insert(&Vertex,'A');
    insert(&Vertex,'B');
    insert(&Vertex,'C');
    insert(&Vertex,'D');



    //display(Vertex);
    setconnections(&Vertex);
   // display(Vertex);
    //top=NULL;
    //cout<<"BEFORE"<<endl;


    //DepthfirstTraversal(Vertex);
    //BreadthfirstTraversal(Vertex);


     //struct Vertex *A=BreadthfirstSearch(Vertex,'A');
     //makedAllFalse(&Vertex);
    // struct Vertex *B=BreadthfirstSearch(Vertex,'E');
     //makedAllFalse(&Vertex);

    // cout<<"A:"<<A->value<<endl;
    // cout<<"B:"<<B->value<<endl;

    // display(Vertex);
   // cout<<"PATH:"<<path(A,B);

    KrushkalSpanningTree(Vertex);

}
void insert(Vertex **vertex,char value)
{
    Vertex *ptr=(Vertex*)malloc(sizeof(Vertex));
    ptr->value=value;
    ptr->edge=NULL;
    ptr->Next=NULL;
    ptr->visited=false;

    if(*vertex==NULL)
    {
        *vertex=ptr;
    }
    else
    {
        Vertex *CURR=*vertex;
        while(CURR->Next!=NULL)
        {
            CURR=CURR->Next;
        }
        CURR->Next=ptr;
    }
}
void AddEdge(Edge **edge,Vertex *vertex)
{
    struct Edge *ptr=(Edge*)malloc(sizeof(Edge));
    cout<<"Weight:";
    cin>>ptr->weight;
    ptr->value=vertex;
    ptr->Next=NULL;

    if(*edge==NULL)
    {
        *edge=ptr;
    }
    else
    {
        Edge *CURR=*edge;
        while(CURR->Next!=NULL)
        {
            CURR=CURR->Next;
        }
        CURR->Next=ptr;
    }
}
void display(Vertex *vertex)
{
    while(vertex!=NULL)
    {
        cout<<vertex->value<<"  ";
        displayEdge(vertex->edge);
        vertex=vertex->Next;
        cout<<endl;
    }
}
void displayEdge(Edge *edge)
{
    while(edge!=NULL)
    {
        Vertex* vertex=(Vertex*)edge->value;
        cout<<vertex->value<<edge->weight<<" ";
        edge=edge->Next;
    }
}
void setconnections(Vertex **vertex)
{
    Vertex *CURR=*vertex,*finder=*vertex;
    while(CURR!=NULL)
    {
         finder=*vertex;
        char input;
        cout<<"Connect "<<CURR->value<<" with:";
        cin>>input;
        while(finder!=NULL)
        {
            if(finder->value==input)
            {
                AddEdge(&(CURR->edge),finder);
                break;
            }
            finder=finder->Next;
        }
        if(finder==NULL)
        {
            CURR=CURR->Next;
        }
    }
}
void push(Edge **top,Vertex* value)
{
    Edge *ptr=(Edge*)malloc(sizeof(Edge));
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
Vertex* pull(Edge **top)
{
    Edge *CURR=*top;
    *top=(*top)->Next;
    return (Vertex*)CURR->value;
}
int i=0;
void DepthfirstTraversal(Vertex *vertex)
{

    if(vertex->visited==false)
    {
        cout<<vertex->value<<endl;
        vertex->visited=true;
        push(&top,vertex);
    }
    Edge *CURR=vertex->edge;

    while(((Vertex*)(CURR->value))->visited!=false )
    {
       CURR=CURR->Next;
       if(CURR==NULL)
       {
            i=1;
            break;
       }
    }
    if(i!=1)
    {
        DepthfirstTraversal((Vertex*)CURR->value);
    }
    else if(i==1 && top!=NULL)
    {
        i=0;
        DepthfirstTraversal(pull(&top));
    }

}
void BreadthfirstTraversal(Vertex *vertex)
{
    cout<<vertex->value<<endl;
    vertex->visited=true;
    Edge *CURR=vertex->edge;
    while(CURR!=NULL )
    {
        if( ((Vertex*)(CURR->value))->visited==false)
        {
            ((Vertex*)(CURR->value))->visited=true;
            enqueue(&top,(Vertex*)CURR->value);
        }
        CURR=CURR->Next;
    }
    if(top!=NULL)
    {
        BreadthfirstTraversal(dequeue(&top));
    }
}
void enqueue(Edge **top,Vertex* value)
{
    Edge *ptr=(Edge*)malloc(sizeof(Edge));
    ptr->value=value;
    ptr->Next=NULL;
    if(*top==NULL)
    {
        (*top)=ptr;
    }
    else
    {
         struct Edge *CURR=*top;
         while(CURR->Next!=NULL)
         {
             CURR=CURR->Next;
         }
         CURR->Next=ptr;
    }

}
Vertex* dequeue(Edge **top)
{
    Edge* CURR=(Edge*)malloc(sizeof(Edge));
    Vertex *ptr=(Vertex*)malloc(sizeof(Vertex));

    CURR=(*top);

    *top=(*top)->Next;
    ptr=(Vertex*)(CURR->value);
    return ((Vertex*)(CURR->value));
}
bool path(Vertex *source,Vertex *destination)
{
    cout<<"source->value"<<source->value<<endl;
    Edge *CURR=source->edge;
    while(CURR!=NULL)
    {
        cout<<"CURR"<<(Vertex*)CURR->value<<endl;
        if((Vertex*)CURR->value==destination)
        {
            return true;
        }
        if(((Vertex*)(CURR->value))->visited==false)
        {
            ((Vertex*)(CURR->value))->visited=true;
            enqueue(&top,(Vertex*)CURR->value);
        }
        CURR=CURR->Next;
    }
    if(top!=NULL)
    {
        path(dequeue(&top),destination);
    }
    else
    {
        return false;
    }
}
Vertex* BreadthfirstSearch(Vertex *vertex,int find)
{
    if(vertex->value==find)
    {
        return vertex;
    }
    vertex->visited=true;
    Edge *CURR=vertex->edge;
    while(CURR!=NULL )
    {
        if( ((Vertex*)(CURR->value))->visited==false)
        {
            ((Vertex*)(CURR->value))->visited=true;
            enqueue(&top,(Vertex*)CURR->value);
        }
        CURR=CURR->Next;
    }
    if(top!=NULL)
    {
        cout<<"top"<<((Vertex*)(top->value))->value<<endl;
        BreadthfirstSearch(dequeue(&top),find);
    }

}
void makedAllFalse(Vertex **vertex)
{
    Vertex *CURR=*vertex;
    while(CURR!=NULL)
    {
        CURR->visited=false;
        CURR=CURR->Next;
    }
}
Vertex* KrushkalSpanningTree(Vertex *vertex)
{
    Vertex *KrushkalSpanning=NULL;

    int TotalVertice=TotalVertices(vertex);
    cout<<TotalVertice<<endl;
     Edges *start=NULL;
    ArrangeEdges(vertex,&start);
    displayKedges(start);
    cout<<"Arranged";
    Selection_Sort(&start);
    cout<<"After Sort";
    displayKedges(start);
    Vertex *CURR=vertex,*Subset[TotalVertice][TotalVertice]={{NULL,NULL}};
    for(int i=0;i<TotalVertice;i++)
    {
        Subset[i][0]=CURR;
        CURR=CURR->Next;
    }
    CURR=vertex;
    while(CURR!=NULL)
    {
        insert(&KrushkalSpanning,CURR->value);
        CURR=CURR->Next;
    }
    Edges *UV=start;
    for(int i=0;UV!=NULL;i++)
    {
        cout<<"UV";
        displayKedges(UV);
        cout<<endl;
        if(intersection(Subset[UV->FisrtVertex->value-65],Subset[UV->SecondVertex->value-65])==false)
        {
            cout<<endl<<intersection(Subset[UV->FisrtVertex->value-65],Subset[UV->SecondVertex->value-65])<<endl;
            Vertex *V=findVertex(UV->FisrtVertex,KrushkalSpanning);
            AddEdgeE(&(V->edge),UV->SecondVertex,UV->weight);
           Union(&Subset[i][UV->FisrtVertex->value-65],&Subset[i][UV->SecondVertex->value-65],TotalVertice);
            cout<<"||"<<Subset[i][UV->FisrtVertex->value-65]->value;
            cout<<Subset[i][UV->FisrtVertex->value-65+1]->value<<"||";

        }
        UV=UV->Next;

        cout<<endl;
        display(KrushkalSpanning);
    }


}
Vertex** Union(Vertex** V1,Vertex **V2,int TotalVertices)
{
    cout<<"uNION";
    int i,j,k=0;
    Vertex *Result=new Vertex[TotalVertices];
    for(i=0;V1[i]!=NULL;i++)
    {
        Result[k]=*V1[k];
        //cout<<Result[k].value<<endl;
        k++;
    }
    for(j=0;V2[j]!=NULL;j++)
    {
        Result[k]=*V2[j];
        //cout<<Result[k].value<<endl;
        k++;
    }
    *V1=Result;
    return (Vertex**)Result;
}
Vertex* findVertex(Vertex* V,Vertex* S)
{
    while(S!=NULL)
    {
        if(V->value==S->value)
        {
            return S;
        }
        S=S->Next;
    }
}
bool intersection(Vertex** V1,Vertex **V2)
{
    cout<<V1[0]->value<<V2[0]->value;
    bool status=false;
    for(int i=0;V1[i]!=NULL;i++)
    {
        for(int j=0;V2[j]!=NULL;j++)
        {
            if(V1[i]->value==V2[j]->value)
            {
                cout<<V1[i]->value<<V2[j]->value;
                return true;
            }
        }
    }
    return false;
}
/*
void swap(struct Edge **start,struct Edge **p1,struct Edge **p2)
{
    if((*p1)->value!=(*p2)->value )
    {
        struct Edge *CURR=*start;
        struct Edge *p2prev=*start,*p1prev=*start,*temp;
        temp=(*p2)->Next;
        if((*start)->weight==(*p1)->weight)
        {
            if((*start)->Next->weight==(*p2)->weight)
            {
                 CURR->Next=(*p2)->Next;
                 (*p2)->Next=*p1;
                 *start=*p2;
            }
            else
            {
                while(CURR->Next!=NULL)
                {
                    if(CURR->Next->weight==(*p2)->weight)
                    {
                        p2prev=CURR;
                    }
                    if((*p2)->Next==NULL)
                    {
                       temp=NULL;
                    }
                    CURR=CURR->Next;
                }

                CURR=(*start);
                *start=*p2;
                (*p2)->Next=(*p1)->Next;
                p2prev->Next=*p1;
                (*p1)->Next=temp;
            }
        }

        else
        {
            while(CURR->Next!=NULL)
            {
                if((CURR->Next)->weight==(*p1)->weight)
                {
                    p1prev=CURR;
                }
                if(CURR->Next->weight==(*p2)->weight)
                {
                    p2prev=CURR;
                }
                CURR=CURR->Next;
            }
            if(p2prev->weight==(*p1)->weight)
            {
                p1prev->Next=(*p2);
                (*p2)->Next=(*p1);
                (*p1)->Next=temp;
            }
            else
            {
                p1prev->Next=*p2;
                (*p2)->Next=(*p1)->Next;
                p2prev->Next=(*p1);
                (*p1)->Next=temp;
            }
        }
    }
}
void swapVertex(struct Vertex **start,struct Vertex **p1,struct Vertex **p2)
{
    if((*p1)->edge->weight!=(*p2)->edge->weight )
    {
        struct Vertex *CURR=*start;
        struct Vertex *p2prev=*start,*p1prev=*start,*temp;
        temp=(*p2)->Next;
        if((*start)->edge->weight==(*p1)->edge->weight)
        {
            if((*start)->Next->edge->weight==(*p2)->edge->weight)
            {
                 (*start)->Next=(*p2)->Next;
                 (*p2)->Next=*p1;
                 *start=*p2;
            }
            else
            {
                while(CURR->Next!=NULL)
                {
                    if(CURR->Next->edge->weight==(*p2)->edge->weight)
                    {
                        p2prev=CURR;
                    }
                    if((*p2)->Next==NULL)
                    {
                       temp=NULL;
                    }
                    CURR=CURR->Next;
                }

                CURR=(*start);
                *start=*p2;
                (*p2)->Next=(*p1)->Next;
                p2prev->Next=*p1;
                (*p1)->Next=temp;
            }
        }

        else
        {
            while(CURR->Next!=NULL)
            {
                if((CURR->Next)->edge->weight==(*p1)->edge->weight)
                {
                    p1prev=CURR;
                }
                if(CURR->Next->edge->weight==(*p2)->edge->weight)
                {
                    p2prev=CURR;
                }
                CURR=CURR->Next;
            }
            if(p2prev->edge->weight==(*p1)->edge->weight)
            {
                p1prev->Next=(*p2);
                (*p2)->Next=(*p1);
                (*p1)->Next=temp;
            }
            else
            {
                p1prev->Next=*p2;
                (*p2)->Next=(*p1)->Next;
                p2prev->Next=(*p1);
                (*p1)->Next=temp;
            }
        }
    }
}
Edge* FindMin(Edge *start)
{
    struct Edge *CURR=start;
    struct Edge *Check=(Edge*)malloc(sizeof(Edge));

    Check->value=start->value;
    Check->weight=start->weight;
    Check->Next=start->Next;
    while(CURR->Next!=NULL)
    {
        if(CURR->Next->weight < Check->weight)
        {
            Check->value=CURR->Next->value;
            Check->weight=CURR->Next->weight;
            Check->Next=CURR->Next->Next;
        }
        CURR=CURR->Next;
    }
    return Check;
}

void Selection_Sort(Edge **start)
{
    struct Edge *CURR=*start,*MIN=CURR;

    while(CURR->Next!=NULL)
    {
        MIN=FindMin(CURR);
        if(MIN->weight!=CURR->weight)
        {
            swap(start,&CURR,&MIN);
            CURR=MIN;
        }

        CURR=CURR->Next;
    }

}
void Selection_Sort_Vertex(Vertex **start)
{
    struct Vertex *CURR=*start,*MIN=CURR;
    while(CURR->Next!=NULL)
    {
        MIN=FindMinVertex(CURR);
        if(MIN->edge->weight!=CURR->edge->weight)
        {
            swapVertex(start,&CURR,&MIN);
            CURR=MIN;
        }
        CURR=CURR->Next;
    }

}
Vertex* FindMinVertex(Vertex *start)
{
    struct Vertex *CURR=start;
    struct Vertex *Check=(Vertex*)malloc(sizeof(Vertex));
    Check=start;
    while(CURR->Next!=NULL)
    {
        if(CURR->Next->edge->weight < Check->edge->weight)
        {
            Check=CURR->Next;
        }
        CURR=CURR->Next;
    }
    return Check;
}*/
void ArrangeEdges(Vertex *start,Edges **E)
{
    struct Edges *ECURR=*E;
    Vertex *CURR=start;
    Edges* ptr=(Edges*)malloc(sizeof(Edges));

    while(CURR!=NULL)
    {
        Edge *CURRE=CURR->edge;
        while(CURRE!=NULL)
        {

            if(*E==NULL)
            {
                *E=(Edges*)malloc(sizeof(Edges));
                (*E)->FisrtVertex=CURR;
                (*E)->SecondVertex=(Vertex*)CURRE->value;
                (*E)->weight=CURRE->weight;
                (*E)->Next=NULL;
                cout<<"hahaha";
            }
            else
            {
                ECURR=*E;
                while(ECURR->Next!=NULL)
                {
                    cout<<"in while";
                    ECURR=ECURR->Next;
                    cout<<"1d"<<endl;
                }
                cout<<"2d"<<endl;
                ECURR->Next=(Edges*)malloc(sizeof(Edges));
                ECURR->Next->FisrtVertex=CURR;
                ECURR->Next->SecondVertex=(Vertex*)CURRE->value;
                ECURR->Next->weight=CURRE->weight;
                ECURR->Next->Next=NULL;
            }
            CURRE=CURRE->Next;
        }
        CURR=CURR->Next;

    }
    cout<<endl;

}

void displayKedges(Edges *E)
{
    cout<<endl;
    while(E!=NULL)
    {
        cout<<E->FisrtVertex->value<<endl;
        cout<<E->SecondVertex->value<<endl;
        cout<<E->weight<<endl;
        E=E->Next;
    }

}
Edges* FindMin(Edges *start)
{
    struct Edges *CURR=start;
    struct Edges *Check=(Edges*)malloc(sizeof(Edges));

    Check->FisrtVertex=start->FisrtVertex;
    Check->SecondVertex=start->SecondVertex;
    Check->weight=start->weight;
    Check->Next=start->Next;

    while(CURR->Next!=NULL)
    {
        if(CURR->Next->weight <= Check->weight)
        {
            Check->FisrtVertex=CURR->Next->FisrtVertex;
            Check->SecondVertex=CURR->Next->SecondVertex;
            Check->weight=CURR->Next->weight;
            Check->Next=CURR->Next->Next;
        }
        CURR=CURR->Next;
    }
    return Check;
}

void Selection_Sort(Edges **start)
{
    struct Edges *CURR=*start,*MIN=CURR;
    while(CURR->Next!=NULL)
    {
        MIN=FindMin(CURR);
        if(MIN->weight!=CURR->weight)
        {
            swap(start,&CURR,&MIN);
            CURR=MIN;
        }
        CURR=CURR->Next;
    }

}
void swap(struct Edges **start,struct Edges **p1,struct Edges **p2)
{
    if((*p1)->weight!=(*p2)->weight )
    {
        struct Edges *CURR=*start;
        struct Edges *p2prev=*start,*p1prev=*start,*temp;
        temp=(*p2)->Next;
        if((*start)->weight==(*p1)->weight)
        {
            if((*start)->Next->weight==(*p2)->weight)
            {
                 CURR->Next=(*p2)->Next;
                 (*p2)->Next=*p1;
                 *start=*p2;
            }
            else
            {
                while(CURR->Next!=NULL)
                {
                    if(CURR->Next->weight==(*p2)->weight)
                    {
                        p2prev=CURR;
                    }
                    if((*p2)->Next==NULL)
                    {
                       temp=NULL;
                    }
                    CURR=CURR->Next;
                }

                CURR=(*start);
                *start=*p2;
                (*p2)->Next=(*p1)->Next;
                p2prev->Next=*p1;
                (*p1)->Next=temp;
            }
        }

        else
        {
            while(CURR->Next!=NULL)
            {
                if((CURR->Next)->weight==(*p1)->weight)
                {
                    p1prev=CURR;
                }
                if(CURR->Next->weight==(*p2)->weight)
                {
                    p2prev=CURR;
                }
                CURR=CURR->Next;
            }
            if(p2prev->weight==(*p1)->weight)
            {
                p1prev->Next=(*p2);
                (*p2)->Next=(*p1);
                (*p1)->Next=temp;
            }
            else
            {
                p1prev->Next=*p2;
                (*p2)->Next=(*p1)->Next;
                p2prev->Next=(*p1);
                (*p1)->Next=temp;
            }
        }
    }
}
int TotalVertices(Vertex *vertex)
{
    int i=0;
    while(vertex!=NULL)
    {
        i++;
        vertex=vertex->Next;
    }
    return i;

}
void AddEdgeE(Edge **edge,Vertex *vertex,int weight)
{
    struct Edge *ptr=(Edge*)malloc(sizeof(Edge));
    ptr->weight=weight;
    ptr->value=vertex;
    ptr->Next=NULL;

    if(*edge==NULL)
    {
        *edge=ptr;
    }
    else
    {
        Edge *CURR=*edge;
        while(CURR->Next!=NULL)
        {
            CURR=CURR->Next;
        }
        CURR->Next=ptr;
    }
}

