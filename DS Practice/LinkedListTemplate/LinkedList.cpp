#include"LinkedList.h"
template <class NODE> NODE LinkedList<NODE>::getNODE()
{
    return this->value;
}
template <class NODE> LinkedList<NODE>* LinkedList<NODE>::getNext()
{
    return this->Next;
}
template <class NODE> void LinkedList<NODE>::AddNode(NODE const& ptr)
{
	    LinkedList *PTR=new LinkedList<NODE>;
	    PTR->value=ptr;
	    PTR->Next=NULL;

		if (this->value == NULL)
		{
           *this=*PTR;
		}
		else
		{
		    LinkedList *CURR = new LinkedList<NODE>;
		    CURR->value=this->value;
		    CURR->Next=this->Next;
			while(CURR!=NULL)
            {
                CURR=CURR->Next;
            }
            CURR=PTR;
		}
}
template <class NODE> NODE LinkedList<NODE>::pop()
{
    if(this->value!=NULL)
    {
        NODE CURR=this->value;
        if(this->Next!=NULL)
        {
            LinkedList *temp=new LinkedList<NODE>;
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
