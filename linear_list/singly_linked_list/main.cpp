template <typenaem T> 
class LinkNode
{   
public:
    T data;
    LinkNode* link;
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



#include "list.h"

template <typename T>
class circular_link_list()
{
public:
    circular_link_list();
    circular_link_list(const circular_link_list& x);

public:
	int Length;
	T *first = nullptr;

};

template<typename T>
circular_link_list::circular_link_list(const circular_link_list<T>& x)
{
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *desptr = first = new LinkNode<T>;
    while(srcptr!=first)
    {
        value = L->link->data;
        desptr = new LinkNode<T>(value);
        desptr->link = srcptr->link;
        srcptr = srcptr->link;
        desptr->link = first;
    }
}

template<typename T>
int List<T>::Length() const
{
    LinkNode<T> *srcptr = first;
    int counter{0};
    while(srcptr->link != first)
    {
        counter +=1;
        srcptr = srcptr->link;
    }
    return counter;
}

template<typename T>
void List<T>::makeEmpty()
{
     while(ptr->link!=first)
    {
        LinkNode<T> *current = first->link;
        first = current->link;
        delete current;
    }
}

template<typename T>
LinkNode <T> *List<T>::Search(T x)
{
    LinkNode *current = first->link;
    while(current->link != first)
    {
        if (current->data == x)
        {
            break;
        }
        else
        {
            current = current->link;
        }
    }
    return current;
}


template<typename T>
LinkNode<T> *List::Locate(int i) const
{
    if (i<0)
    {
        return nullptr;   
    }
    int count{0};
    LinkNode *current = first->link;
    while(current->link != first&&count < i)
    {
        current = current->link;
    }
    return current;
}


template<typename T>
bool List<T>::getData(int i, T& x) const
{
	if (i<0)
	{
		return false;
	}
	LinkNode *current = Locate(i);
	x = current->data;
	return true;
}

template<typename T>
void List<T>::setData(int i, T& x)
{




