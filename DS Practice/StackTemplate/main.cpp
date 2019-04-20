#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class NODE> class GenericStack {
public:
	NODE value=NULL;
	GenericStack *Next = NULL;


	void push(NODE const& ptr)
	{
	    GenericStack *PTR=new GenericStack<NODE>;
	    PTR->value=ptr;
	    PTR->Next=NULL;

		if (this->value == NULL)
		{
           *this=*PTR;
		}
		else
		{
		    GenericStack *CURR = new GenericStack<NODE>;
		    CURR->value=this->value;
		    CURR->Next=this->Next;
			*this=*PTR;
			this->Next=CURR;
		}
	}
	NODE pop();

};



template <class NODE> NODE GenericStack<NODE>::pop()
{
    if(this->value!=NULL)
    {
        NODE CURR=this->value;
        if(this->Next!=NULL)
        {
            GenericStack *temp=new GenericStack<NODE>;
            temp=this->Next;
            this->value = temp->value;
            this->Next=temp->Next;
            return CURR;
        }
        else
        {
            this->value=NULL;
            return CURR;
        }
    }
    else
    {
        return NULL;
    }
}
int main()
{
    GenericStack<int>  *intStack=new GenericStack<int>;
    intStack->push(7);
    intStack->push(9);
    intStack->push(2);
    while(intStack->value!=NULL)
    {
        cout << intStack->pop();
    }
    cout << endl;
    system("pause");
}
