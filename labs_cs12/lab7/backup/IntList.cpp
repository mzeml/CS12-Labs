#include <iostream>

#include "IntList.h"
using namespace std;

IntList::IntList()
{
    head = 0;
    tail = 0;
}

IntList::~IntList()
{
    IntNode* temp = 0;
    
    for(temp = head; temp != 0; temp = head)
    {
        head = head->data;
        delete data;
    }
}
void IntList::display() const
{
    IntNode* temp = 0;
    for(temp = head;temp != 0; temp = head)
    {
        cout << temp->data;
        if(temp->next != 0)
        {
            cout << " ";
        }
    }
    
}
void IntList::push_front(int val)
{
    IntNode* temp = new IntNode(val);
    
    if(head == 0)
    {
        tail = 0;
    }
    
    temp->next = head;
    temp = head;
}
void IntList::pop_front()
{
    if(head == 0)
    {
        tail = 0;
    }
    IntNode * temp = head;
    head = head-> next;
    delete temp;
    
}
bool IntList::empty() const
{
    if(head == 0 && tail == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}