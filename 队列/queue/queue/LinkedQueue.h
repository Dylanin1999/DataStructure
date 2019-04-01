#pragma once
#include "Queue.h"
#include "LinkNode.h"
#include <iostream>

template <typename T>
class LinkedQueue :public Queue<T>
{
public:
	LinkedQueue():
	~LinkedQueue();
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x);
	void makeEmpty();
	bool IsEmpty() const;
	int getSize() const;
	friend ostream& operator<<(ostream& os, LinkedQueue<T>& Q);
private:
	LinkNode<T> *front, *rear;

};

template <typename T>
void LinkedQueue<T>::makeEmpty()
{
	LinkNode<T>* p;
	while (front != nullptr)
	{
		p = front;
		front = front->link;
		delete p;
	}
}

template <typename T>
bool LinkedQueue<T>::EnQueue(const T& x)
{
	if (front == nullptr)
	{
		front = rear = new LinkNode<T>(x);
		if (front == nullptr)
		{
			std::cout << "内存分配失败" << std::endl;
			return false;
		}
	}
	else
	{
		rear->link = new LinkNode<T>(x);
		if (rear->link == nullptr)
		{
			std::cout << "内存分配失败" << std::endl;
			return false;
		}
	}
	return true;
}

template <typename T>
bool LinkedQueue<T>::DeQueue(T& x)
{
	if (IsEmpty() == true)
	{
		std::cout << "无法删除，队列为空" << std::endl;
		return false;
	}
	LinkNode<T> *p = front;
	x = front->data;
	front = front->link;
	delete p;
	return true;
}

template <typename T>
bool LinkedQueue<T>::getFront(T& x)
{
	if (IsEmpty() == true)
	{
		return false;
	}
	x = front->data;
	return true;
}

template <typename T>
int LinkedQueue<T>::getSize() const 
{
	LinkNode<T> *p = front;
	int count{ 0 };
	while (p->link != nullptr)
	{
		count += 1;
	}
	return count;
}


template <typename T>
ostream& operator<<(ostream& os, LinkedQueue<T>& Q)
{
	os << "队列中元素个数有" << Q.getSize() << std::endl;
	LinkNode<T> *p = Q.front;
	int i = 0;
	while (p != nullptr)
	{
		os << ++i << ":" << p->data << std::endl;
		p = p->link;
	}
	return os;
}


