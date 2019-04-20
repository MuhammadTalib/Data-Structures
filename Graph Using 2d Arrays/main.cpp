#include <iostream>

using namespace std;
void displayArray2d(int *arr);

int main()
{
    int n=0;
    cout<<"How many vertices you want to enter:";
    cin>>n;
    int Edges[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            Edges[i][j]=0;
        }
    }
    int Vertices[n];
    for(int i=0;i<n;i++)
    {
        int connector=0;
        cout<<"Enter "<<i<<" Vertex:";
        cin>>Vertices[i];
        do
        {
            cout<<i<<" is connected with:";
            cin>>connector;
            for(int k=0;k<n;k++)
            {
                if(connector==Vertices[k])
                {
                    Edges[i][k]=1;
                }
                else
                    Edges[i][k]=0;
            }
        }while(connector<n);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Edges[i][j]<<" ";
        }
        cout<<endl;
    }

}
void displayArray2d(int *arr)
{
    cout<<*arr<<endl;
   cout<<*arr+sizeof(int);
   cout<<endl;

}
