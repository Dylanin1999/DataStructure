#pragma once
#include "stack.h"
#include <assert.h>
#include <iostream>
const int stackIncreament = 20;
template <typename T>
class SeqStack : public Stack<T>
{
public:
	SeqStack(int sz = 50);
	~SeqStack() { delete[] elements };
	void Push(const T& x);
	bool Pop(T& x);
	bool getTop(T &x);
	bool IsEmpty() const;
	bool IsFull() const;
	int getSize() const;
	void MakeEmpty();
	friend ostream& operator<<(ostream& os, SeqStack<T>& s);
protected:
private:
	T *elements;
	int top;
	int maxSize;
	void overflowProcess();
};

template <typename T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz)
{
	elements = new T[maxSize];
	assert(elements != nullptr);9
}


template <typename T>
void SeqStack<T>::overflowProcess()
{
	T *newArray = new T[maxSize + stackIncreament];
	if (newArray = nullptr)
	{
		std::cerr << "´æ´¢·ÖÅäÊ§°Ü£¡" << std::endl;
		exit(1);
	}
	maxSize = maxSize + stackIncreament;
	delete[]elements;
	elements = newArray;
}

template <typename T>
void SeqStack<T>::Pop(T& x)
{
	if (IsEmpty() == true)
	{
		overflowProcess();
		elements[++top] = x;
	}
}

template <typename T>
bool SeqStack<T>::getTop(T &x)
{
	if (IsEmpty() == true )
	{
		return false;
	}
	x = elements[top];
	return;
}

template <typename T>
ostream& operator << (ostream& os, SeqStack<T>& s)
{
	os << "top =" << s.top << std::endl;
	for (int i = 0; i < s.top; i++)
	{
		os << i << ":" << s.elements[i] << std::endl;
	}
	return os;
}

