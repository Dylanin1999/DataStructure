#pragma once
#include <iostream>
#include "stack.h"
#include "LinkNode.h"

template <typename T>
class LinkedStack: public Stack<T>
{
public:
	LinkedStack() :Top(nullptr) {}
	~LinkedStack()
	{
		makeEmpty();
	}
	void Push(const T& x);
	bool Pop(T& x);
	bool getTop(T& x) const;
	bool isEmpty() const;
	int getSize() const;
	void makeEmpty();
	friend ostream& operator<<(ostream& os, SeqStack<T>& s);

private:
	LinkNode<T> *Top;
};


template <typename T>
void LinkedStack<T>::makeEmpty()
{
	LinkNode<T> *p;
	while (Top != nullptr)
	{
		p = Top;
		Top = Top->lik;
		delete p;
	}
}

template <typename T>
void LinkedStack<T>::Push(const T& x)
{
	Top = new LinkNode<T>(x, Top);
	assert(Top != nullptr);
}

template <typename T>
bool LinkedStack<T>::Pop(T& x)
{
	if (isEmpty() == true) 
	{
		return false;
	}
	LinkNode<T> *p = Top;
	Top = Top->link;
	x = p->data;
	delete p;
	return false;
}

template <typename T>
bool LinkedStack<T>::getTop(T& x) const
{
	if (isEmpty() == true)
	{
		return false;
	}
	x = Top->data;
	return true;
}

template <typename T>
int LinkedStack<T>::getTop(T& x) const
{
	LinkNode<T> *p = Top;
	int k = 0;
	while (Top != nullptr)
	{
		Top = Top->link;
		k++;
	}
	return k;
}

template <typename T>
ostream& operator<<(ostream& os, SeqStack<T>& s)
{
	os << "栈中元素个数 = " << s.getSize() << std::endl;
	LinkNode<T> *p = s.Top;
	int i = 0;
	while (p != nullptr)
	{
		os << ++i; << ":" << p->data; << std::endl;
		p = p->link;
	}
	return os;
}