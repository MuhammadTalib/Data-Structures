
#include<iostream>
#include<string>
using namespace std;

void Hashing_insert(int arr[],int size);
int Linear_Probbing(int arr[],int size,int input,int index,string WhatToDo);
int Hashing_Search(int arr[],int size);
int Quadratic_Probbing(int arr[],int size,int input,int index,string WhatToDo);
void display(int *arr,int size);

int main()
{
	int arr[10]={NULL};
	int n=sizeof(arr)/sizeof(arr[0]);
	Hashing_insert(arr,n); //1
	Hashing_insert(arr,n);//2
	Hashing_insert(arr,n);//3
	Hashing_insert(arr,n);//4
	Hashing_insert(arr,n);//5
    Hashing_insert(arr,n);//6

	Hashing_Search(arr,n);

	display(arr,n);
}
void display(int *arr,int size)
{
    cout<<"||"<<(sizeof(arr))<<"||";
	for(int i=0;i<size;i++)
	{
		if(arr[i]==NULL)
		{
			cout<<endl<<i<<"="<<"NULL";
		}
		else
		{
			cout<<endl<<i<<"="<<arr[i];
		}
	}
}
int Quadratic_Probbing(int arr[],int size,int input,int index,string WhatToDo)
{
    int i=1,newindex;
    while(i<10)
    {
        newindex=index+(i*i);
        i++;
        if(newindex > size-1)
        {
            newindex=newindex%size;
        }
        if(arr[newindex]==NULL && WhatToDo=="insert")
        {
            return newindex;
        }
        if(arr[newindex]==input && WhatToDo=="search")
        {
            return newindex;
        }
    }



}
int Linear_Probbing(int arr[],int size,int input,int index,string WhatToDo)
{

	int act=index,flag=1;
	if(WhatToDo=="insert")
	{
		do
		{
			index++;
			if(arr[index]==size)
			{
				index=0;
			}
			if(index==act)
			{
				break;
			}
		}
		while(arr[index]!=NULL);
		return index;
	}
	else if(WhatToDo=="search")
	{
		do
		{
			index++;
			if(arr[index]==size)
			{
				index=0;
			}
			if(index==act)
			{
				cout<<"Number Not Found";
				flag=0;
				break;
			}
		}
		while(input!=arr[index]);
		if(flag>0)
		{
			cout<<"Found at index="<<index;
		}
		return index;
	}
}

void Hashing_insert(int arr[],int size)
{
	int input,index;
	cout<<"Enter Input=";
	cin>>input;
	index=input%size;
	if(arr[index]!=NULL)
	{
		index=Quadratic_Probbing(arr,size,input,index,"insert");
	}
	arr[index]=input;
}
int Hashing_Search(int arr[],int size)
{
	int input,index;
	cout<<"Search Number=";
	cin>>input;
	index=input%size;
	if(arr[index]==NULL)
	{
		cout<<"Number Not Found"<<endl;
	}
	else
	{
		if(arr[index]!=input)
		{
			index=Quadratic_Probbing(arr,size,input,index,"search");
			if(index==NULL)
            {
                cout<<"Number Not Found";
            }
            else
            {
                cout<<"Found at index "<<index<<endl;
            }
		}
	}
}

