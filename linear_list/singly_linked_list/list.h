#ifndef LIST_H
#define LIST_H

#include "list.h"
#include <iostream>
template<typename T>
class LinkNode
{
public:
    T data;
    LinkNode* link;
    LinkNode(LinkNode<T> *ptr = nullptr)
    {
        link = ptr;
    }
    LinkNode(const T& item,LinkNode<T>* ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};


template <typename T>
class List
{
public:
    List();
    List(const T& x);
    List(List<T>& L);
    ~List();
    void makeEmpty();
    int Length() const;
    LinkNode<T> *getHead()const;
    LinkNode<T> *Seacher()const;
    LinkNode<T> *Local() const;
    bool getData(int i,T& x)const;
    void setData(int i,T& x);
    bool Insert(int i,T& x);
    bool Remove(int i,T& x);
    bool IsEmpty() const;
    bool IsFull()const;
    void Sort();
    void Input();
    void Output();
    List<T>& operator=(List<T>& L);
 protected:
    LinkNode<T> *first;

};


template<typename T>
List<T>::List(List<T>& L)
{
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *desptr = first = new LinkNode<T>;
	while(srcptr->link != nullptr)
	{
		value = srcptr->link->data;
		desptr->link=new LinkNode<T>(value);
		desptr=desptr->link;
		srcptr=srcptr->link;
		desptr->link=nullptr;
	}

}


template<class T>
int List<T>::Length() const
{
	LinkNode<T> *p = first->link;
	int count{0};
	while(p!=nullptr)
	{
		p = p->link;
		count++;
	}
	return count;
}

template<typename T>
void List<T>::makeEmpty()
{
	LinkNode<T> *q;
	while(first->link!=nullptr)
	{
		q=first->link;
		first->link=q->link;
		delete q;
	}
}

template<typename T>
LinkNode <T> *List<T>::Search(T x )
{
	LinkNode<T> *current = first->link;
	while(current!=nullptr)
	{
		if(current->data == x)
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
LinkNode<T> *List::Local(int i) const
{
	LinkNode *current = first;
	int count{0};
	while(current->link != nullptr&&count<i)
	{
		current = curent->link;
		count++;
	}
	return current;
}


template<typename T>
bool List<T>::getData(int i,T& x) const
{
	if(i<=0)
	{
		return false;
	}
	LinkNode *current = Local(i);
	if(current == nullptr)
	{
		return false;
	}
	else
	{
		x = current->data;
		return true;
	}
}

template<typename T>
void List<T>::setData(int i,T& x)
{
	if(i<0)
	{
		return;
	}
	LinkNode<T> *current = Local(i);
	if(curent == nullptr)
	{
		return;
	}
	else
	{
		current->data = x;
	}
}


template<typename T>
bool List<T>::Insert(int i,T& x)
{
	if(i<0)
	{
		std::cerr<<"请输入正确的插入位置！"<<std::endl;
		return false;
	}
	LinkNode *current = Local(i);
	if(current == nullptr)
	{
		return false;
	}

	LinkNode *newNode =  new LinkNode<T>(x);
	if(newNode == nullptr)
	{
		std::cerr<<"分配错误"<<std::endl;
	}
	newNode->link = current->link;
	current->link = newNode;
}
#endif // LIST_H
