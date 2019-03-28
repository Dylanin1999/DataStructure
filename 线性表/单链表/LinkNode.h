#ifndef __linkNode__
#define __linkNode__
template <typename T> 
class LinkNode
{   
public:
    T data;
    LinkNode<T>* link;
    LinkNode(const T& item, const LinkNode<T>* ptr=nullptr)
    {
        link = ptr;
        data = item;      
    }
    LinkNode(LinkNode<T> *ptr = nullptr)
    {
        link = nullptr;
    }
};
#endif 
