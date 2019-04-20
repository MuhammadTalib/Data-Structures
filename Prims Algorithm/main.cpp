#include <iostream>
#include <stdlib.h>
#include<stdio.h>
using namespace std;
struct Subset;
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
    Subset *subset=NULL;
};
struct Edges
{
    Vertex *FisrtVertex=NULL;
    Vertex *SecondVertex=NULL;
    Edges *Next=NULL;
    int weight;
};
struct Subset
{
    Vertex *value=NULL;
    Subset *Next=NULL;
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
Vertex* PrimsSpanningTree(Vertex *vertex);
void Selection_Sort(Edges **start);
void ArrangeEdges(Vertex *start,Edges **E);
void displayKedges(Edges *E);
void swap(struct Edges **start,struct Edges **p1,struct Edges **p2);
Edges* FindMin(Edges *start);
int TotalVertices(Vertex *vertex);
bool intersection(Subset* V1,Subset *V2);
Vertex* findVertex(Vertex* V,Vertex* S);
void AddEdgeE(Edge **edge,Vertex *vertex,int weight);
void Union(Subset** V1,Subset **V2,int TotalVertices);
void insertSUBSET(Subset **subset,Vertex* value);
void displaysubset(Subset *sub);
void ArrangePrimsEdges(Vertex *vertex,Edges **E);
int main()
{

    top=NULL;
    Vertex* Vertex=NULL;
    insert(&Vertex,'A');
    insert(&Vertex,'B');
    insert(&Vertex,'C');
    insert(&Vertex,'D');

    setconnections(&Vertex);

    PrimsSpanningTree(Vertex);

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
    Edges *start=NULL;
    ArrangeEdges(vertex,&start);
    Selection_Sort(&start);
    cout<<"sORTED";
    Vertex *CURR=vertex;
    for(int i=0;i<TotalVertice;i++)
    {
        insert(&KrushkalSpanning,CURR->value);
        CURR->subset=NULL;
        insertSUBSET(&(CURR->subset),CURR);
        CURR=CURR->Next;
    }
    Edges *UV=start;
    for(int i=0;UV!=NULL;i++)
    {
        if(intersection(UV->FisrtVertex->subset,UV->SecondVertex->subset)==false)
        {
            Vertex *V=findVertex(UV->FisrtVertex,KrushkalSpanning);
            AddEdgeE(&(V->edge),UV->SecondVertex,UV->weight);
            Union(&(UV->FisrtVertex->subset),&(UV->SecondVertex->subset),TotalVertice);
        }
        UV=UV->Next;
        display(KrushkalSpanning);
    }


}
void Union(Subset** V1,Subset **V2,int TotalVertices)
{

    Subset *Result=NULL,*C1=*V1,*C2=*V2;
    while(C1!=NULL)
    {
        insertSUBSET(&Result,(C1)->value);
        (C1)=(C1)->Next;
    }
    while(C2!=NULL)
    {
        insertSUBSET(&Result,(C2)->value);
        C2=C2->Next;
    }
    *V1=Result;
    *V2=Result;
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
bool intersection(Subset* V1,Subset *V2)
{
    while(V1!=NULL)
    {
        while(V2!=NULL)
        {
            if(V1->value->value==V2->value->value)
            {
                return true;
            }
            V2=V2->Next;
        }
        V1=V1->Next;
    }

    return false;
}
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

            }
            else
            {
                ECURR=*E;
                while(ECURR->Next!=NULL)
                {
                    ECURR=ECURR->Next;
                }
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
void insertSUBSET(Subset **subset,Vertex* value)
{
    Subset *ptr=(Subset*)malloc(sizeof(Subset));
    ptr->value=value;
    ptr->Next=NULL;
    if(*subset==NULL)
    {
        *subset=ptr;
    }
    else
    {
        Subset *CURR=*subset;
        while(CURR->Next!=NULL)
        {
            CURR=CURR->Next;
        }
        CURR->Next=ptr;
    }
}
void displaysubset(Subset *sub)
{
    while(sub!=NULL)
    {
        cout<<sub->value->value<<"  ";
        sub=sub->Next;
        cout<<endl;
    }
}
Vertex* PrimsSpanningTree(Vertex *vertex)
{
    Vertex *PrimsSpanning=NULL;
    Vertex *CURR=vertex;
     int TotalVertice=TotalVertices(vertex);
    for(int i=0;i<TotalVertice;i++)
    {
        insert(&PrimsSpanning,CURR->value);
        CURR->subset=NULL;
        insertSUBSET(&(CURR->subset),CURR);
        CURR=CURR->Next;
    }

    Edges *start=NULL;
    ArrangePrimsEdges(vertex,&start);
    Edges *UV=start;
    for(int i=0;i<TotalVertice;i++)
    {
        Selection_Sort(&UV);
        cout<<"sORTED";
        displayKedges(UV);
        if(intersection(UV->FisrtVertex->subset,UV->SecondVertex->subset)==false)
        {
            Vertex *V=findVertex(UV->FisrtVertex,PrimsSpanning);
            AddEdgeE(&(V->edge),UV->SecondVertex,UV->weight);
            Union(&(UV->FisrtVertex->subset),&(UV->SecondVertex->subset),TotalVertice);
            ArrangePrimsEdges(UV->SecondVertex,&UV);

        }
        UV=UV->Next;
        display(PrimsSpanning);
    }

}

void ArrangePrimsEdges(Vertex *vertex,Edges **E)
{
    struct Edges *ECURR=*E;

    Edges* ptr=(Edges*)malloc(sizeof(Edges));

    Edge *CURRE=vertex->edge;
    while(CURRE!=NULL)
    {
        if(*E==NULL)
        {
            *E=(Edges*)malloc(sizeof(Edges));
            (*E)->FisrtVertex=vertex;
            (*E)->SecondVertex=(Vertex*)CURRE->value;
            (*E)->weight=CURRE->weight;
            (*E)->Next=NULL;
        }
        else
        {
            ECURR=*E;
            while(ECURR->Next!=NULL)
            {
                ECURR=ECURR->Next;
            }
            ECURR->Next=(Edges*)malloc(sizeof(Edges));
            ECURR->Next->FisrtVertex=vertex;
            ECURR->Next->SecondVertex=(Vertex*)CURRE->value;
            ECURR->Next->weight=CURRE->weight;
            ECURR->Next->Next=NULL;
        }
        CURRE=CURRE->Next;
    }
}
