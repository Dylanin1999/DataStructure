#pragma once
#include <iostream>
#include "Queue.h"
#include <assert.h>


template <typename T>
class SeqQueue :public Queue<T>
{
public:
	SeqQueue(int sz = 10);
	~SeqQueue()
	{
		delete[] element;
	}
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x) const;
	void makeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int getSize() const;
	friend ostream& operator<<(ostream& os, SeqQueue<T>& Q);

protected:
	int rear, front;
	T *element;
	int maxSize;
	
};



template <typename T>
SeqQueue<T>::SeqQueue(int sz = 10)
{
	element = new T[maxSize];
	assert(element != nullptr);
}

template <typename T>
SeqQueue<T>::EnQueue(const T& x)
{
	if (IsFull() == true)
	{
		return false;
	}
	element[rear] = x;
	rear = (rear + 1) % maxSize;
	return true;
}


template <typename T>
bool SeqQueue<T>::DeQueue(T& x)
{
	if (IsEmpty() == true)
	{
		return false;
	}
	x = element[front];
	return true;
}

template <typename T>
bool SeqQueue<T>::IsEmpty() const
{
	return (front == rear) ? true : false;
}

template <typename T>
bool SeqQueue<T>::IsFull() const
{
	return ((rear + 1) % maxSize == front) ? true : false;
}

template <typename T>
bool SeqQueue<T>::getFront(T& x) const
{
	if (IsEmpty() == true)
	{
		return false;
	}
	x = element[front];
	return true;
}

template <typename T>
void SeqQueue<T>::makeEmpty() 
{
	front = rear = 0;
}

template <typename T>
int SeqQueue<T>::getSize() const  
{
	return (rear - front+maxSize)%maxSize
}
template <typename T>
ostream& operator<<(ostream& os, SeqQueue<T>& Q)
{
	os << "front= " << Q.front << ", rear= " << Q.rear << std::endl;
	for (int i = front;i!=rear;i=(i+1)%maxSize)
	{
		os << i << ":" << Q.element[i] << std::endl;
	}
	return os;
}





