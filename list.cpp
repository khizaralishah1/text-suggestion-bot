#include <iostream>
#include <string>
#include "list.h"
using namespace std;

node* node::head = nullptr;
node* node::last = nullptr;

void node::insert(string val)
{
    if(head == nullptr)
    {
        head = new node(val);
        last = head;
        return;
    }

    //see if that word exists before
    if ( !exists(val) )
    {
        last->next = new node(val);
    }
    else
        traverse->frequency++;
}

bool node::exists(string val)
{
    traverse = head;

    while(traverse != nullptr)
    {
        if(traverse->data == val)
            return true;
        traverse = traverse->next;
    }

    return false;
}