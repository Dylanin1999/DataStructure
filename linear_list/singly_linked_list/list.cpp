#include "list.h"
#include <iostream>

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
int List<T>::Length()const
{
	LinkNode<T> *p = first->link;
	int count = 0;
	while(current!=nullptr)
	{
		if(current->data == x) break;
		else current = current->link;
	}
	return current;
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
LinkNode<T> *Local(int i) const
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


















