#include <iostream>

using namespace std;

#include "IntList.h"

IntList::IntList()
{
    head = 0;
}
void IntList::push_front(int value)
{
    IntNode *newNode = new IntNode(value);
    
    newNode->next = head;
    head = newNode;
}
ostream & operator<<(ostream &out, const IntList &rhs)
{
    out<<rhs.head;
    
    return out;
}
bool IntList::exists(int value) const
{
    if(head == 0)
    {
        return false;
    }
    return exists(head, value);
}
bool IntList::exists(IntNode *node, int value) const
{
   
    if(node->data == value)
    {
        return true;
    }
    else
    {
        if(node->next == 0)
        {
           return false;
        }
    }
    return exists(node->next, value);
}
ostream & operator<<(ostream &out, IntNode *myPtr)
{
    
    if(myPtr==0)
    {
        out << "";
    }
    else if(myPtr->next == 0)
    {
        out << myPtr->data;
    }
    else
    {
        out << myPtr->data << " ";
        myPtr = myPtr->next;
        out << myPtr;
    }
    
    return out;
    
}
