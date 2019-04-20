///Implementation Using Arrays
///Max Heap
#include <iostream>
#include <stdlib.h>
using namespace std;

void Insert(int value,int *arr);
void HeapSort(int *arr);
void MaxHeapSort(int *arr);
void swap(int *I,int *J);
void displayarray(int *arr);
void heapify(int *arr,int till);
void deletefromMinHeap(int *arr,int value);
void deletefromMaxHeap(int *arr,int value);
int main()
{
    int *Array;
    Array=new int[100];
    for(int i=0;i<100;i++)
    {
        Array[i]=NULL;
    }
    Insert(220,Array);
    Insert(18,Array);
    Insert(19,Array);
     Insert(220,Array);
    Insert(18,Array);
    Insert(19,Array);
     Insert(220,Array);
    Insert(18,Array);
    Insert(19,Array);
     Insert(220,Array);
    Insert(18,Array);
    Insert(19,Array);
     Insert(220,Array);
    Insert(18,Array);
    Insert(19,Array);

    HeapSort(Array);
    displayarray(Array);

}
void Insert(int value,int *arr)
{
    int temp=0,att=0;
    int i=0,curr=0;
    for(int i=0;i<100;i++)
    {
        if(arr[i]==NULL)
        {
            arr[i]=value;
            return ;
        }
        else if(arr[(2*i)+1]==NULL)
        {
            curr=(2*i)+1;
            arr[(2*i)+1]=value;
            {
                att=i;
                while(arr[i]<arr[curr])
                {

                    swap(&arr[i],&arr[curr]);
                    curr=i;
                    i=(i-1)/2;
                }
                i=att;

            }
            return ;
        }
        else if(arr[(2*i)+2]==NULL)
        {
            arr[(2*i)+2]=value;
            {
                att=i;
                curr=(2*i)+2;
                while(arr[i]<arr[curr])
                {
                    swap(&arr[i],&arr[curr]);
                    curr=i;
                    if(curr%2==0)
                        i=(i-2)/2;
                    else
                        i=(i-1)/2;
                }
                i=att;
            }
            return ;

        }

    }

}
void displayarray(int *Array)
{
    for(int i=0;i<20;i++)
    {
        if(Array[i]==NULL)
        {
            cout<<"Position "<<i<<"="<<"NULL"<<endl;
        }
        else
        {
            cout<<"Position "<<i<<"="<<Array[i]<<endl;
        }
    }
}
void MaxHeapSort(int *arr)
{
    //Sort in Descending Order
   int i=0,k=0;
    for(i=0;arr[i]!=NULL;i++)
    {
        arr[i]=arr[i];
    }
    i--;
    cout<<"i="<<i;
    for(int j=i;i>0;)
    {
        if(arr[j]>arr[k])
        {
            swap(&arr[j],&arr[i]);
            heapify(arr,i-1);
        }
        i--;
    }
}
void HeapSort(int *arr)
{
    int i=0;
    for(i=0;arr[i]!=NULL;i++)
    {
        arr[i]=arr[i];
    }
    i--;
    for(int j=0;i>0;)
    {
        if(arr[j]>arr[i])
        {
            swap(&arr[j],&arr[i]);
            heapify(arr,i-1);
        }
        i--;
    }

}
void swap(int *I,int *J)
{
    int temp=*I;
    *I=*J;
    *J=temp;
}
void heapify(int *arr,int till)
{
    for(int i=0;i<=till;i++)
    {
        if(arr[2*i+1] >  arr[i] && 2*i+1<=till)
        {
            swap(&arr[2*i+1],&arr[i]);
        }
        if(arr[2*i+2] > arr[i] && 2*i+2<=till)
        {
            swap(&arr[2*i+2],&arr[i]);
        }
    }

}
void deletefromMinHeap(int *arr,int value)
{
    for(int i=0;1;i++)
    {
        if(arr[i]==value)
        {
            if(arr[2*i+1]==NULL && arr[2*i+2]==NULL)
            {
                arr[i]=NULL;
                int k;
                for(k=i;arr[k+1]!=NULL;k++)
                {
                    arr[k]=arr[k+1];
                }
                arr[k]=NULL;
                break;
            }
            else if(arr[2*i+1]!=NULL && arr[2*i+2]!=NULL)
            {
                if(arr[2*i+1]<arr[2*i+2])
                {
                    swap(&arr[i],&arr[2*i+1]);
                    i=(2*i)+1-1;
                }
                else if(arr[2*i+1]>arr[2*i+2])
                {
                    swap(&arr[i],&arr[2*i+2]);
                    i=2*i+2-1;
                }
            }
            else if(arr[2*i+1]!=NULL && arr[2*i+2]==NULL)
            {
                swap(&arr[i],&arr[2*i+1]);
                i=(2*i)+1-1;
            }
        }

    }
}
void deletefromMaxHeap(int *arr,int value)
{
    for(int i=0;1;i++)
    {
        if(arr[i]==value)
        {
            if(arr[2*i+1]==NULL && arr[2*i+2]==NULL)
            {
                arr[i]=NULL;
                int k;
                for(k=i;arr[k+1]!=NULL;k++)
                {
                    arr[k]=arr[k+1];
                }
                arr[k]=NULL;
                break;
            }
            else if(arr[2*i+1]!=NULL && arr[2*i+2]!=NULL)
            {
                if(arr[2*i+1]>arr[2*i+2])
                {
                    cout<<"in if";
                    swap(&arr[i],&arr[2*i+1]);
                    i=(2*i)+1-1;
                }
                else if(arr[2*i+1]<arr[2*i+2])
                {
                    cout<<"in else";
                    swap(&arr[i],&arr[2*i+2]);
                    i=2*i+2-1;
                }
            }
            else if(arr[2*i+1]!=NULL && arr[2*i+2]==NULL)
            {
                swap(&arr[i],&arr[2*i+1]);
                i=(2*i)+1-1;
            }
        }

    }
}
