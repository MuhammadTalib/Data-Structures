#include <iostream>

using namespace std;

void printArray(int arr[], int size);


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int setpivit (int arr[], int L, int R)
{
    int pivot = arr[R];
    int i = (L - 1);

    for (int j = L; j <=R- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[R]);
    return (i + 1);
}

void quickSort(int arr[], int L, int R)
{
    if (L < R)
    {
        int pi = setpivit(arr, L, R);

        quickSort(arr, L, pi - 1);
        quickSort(arr, pi + 1, R);
    }
}
void MERGE(int new_array[],int arr[],int L,int R,int mid)
{

    cout<<endl<<"L="<<L<<"R="<<R;
      int L_arr[mid+1-L],R_arr[R+1-mid-1],Q=R+1-mid-1;
      cout<<endl<<"||"<<mid+1-L<<"||"<<R+1-mid-1<<"||";
      for(int i=L;i<R;i++)
      {

          if(arr[L]>arr[Q])
          {
              swap(&arr[L],&arr[Q]);
          }
          L++;
          if(L==mid+1)
          {
            L=0;
            Q++;
          }

      }
}
void mergesort(int arr[],int L,int R)
{
    int new_array[R+1]={NULL};
    if((L<R))
    {
        int mid=(L+R)/2;
        cout<<endl<<mid;


        mergesort(arr,L,mid);

        cout<<endl<<"Next";
        mergesort(arr,mid+1,R);
        MERGE(new_array,arr,L,R,mid);




    }

}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<endl;
}

int main()
{
    int arr[] = {9,8,1,6,5,4,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout<<"Sorted array: n"<<endl;
    printArray(arr, n);
    return 0;
}
