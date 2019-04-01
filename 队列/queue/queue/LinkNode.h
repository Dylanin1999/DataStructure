#ifndef __linkNode__
#define __linkNode__
#include <iostream>

template <typename T> 
class LinkNode
{   
public:
    T data;
    LinkNode<T> *link;
    LinkNode(const T& item, LinkNode<T> *ptr= NULL)
    {
        link = ptr;
        data = item;      
    }
    LinkNode(LinkNode<T> *ptr = NULL)
    {
        link = ptr;
    }
};
#endif 
