#pragma once
#include "LinkNode.h"
#include <iostream>
template <typename T>
class mycircular_list
{
public:
	mycircular_list(const T& x);
	mycircular_list(const mycircular_list& L);
	void makeEmpty();
	int Length() const;
	LinkNode<T> *getHead() const;
	LinkNode<T> *Search(T x) const;
	LinkNode<T> *Locate(int i) const;
	bool getData(int i, T& x) const;
	bool setData(int i, T& x);
	bool Insert(int i, T& x);
	void input(T endTag);
	void output();
	~mycircular_list();

public:
	LinkNode<T> *first = new LinkNode<T>;
};

template<typename T>
mycircular_list<T>::mycircular_list(const T& x)
{
	LinkNode<T> *current = new LinkNode<T>(x);
	first->link = current;
	current->link = first;
}

template<typename T>
mycircular_list<T>::mycircular_list(const mycircular_list<T>& L)
{
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *desptr = first = new LinkNode<T>;
	while (srcptr != first)
	{
		value = L->link->data;
		desptr = new LinkNode<T>(value);
		desptr->link = srcptr->link;
		srcptr = srcptr->link;
		desptr->link = first;
	}
};


template<typename T>
LinkNode<T> *mycircular_list<T>::getHead() const
{
	return first->link;
}

template<typename T>
int mycircular_list<T>::Length() const
{
	LinkNode<T> *srcptr = first;
	int counter{ 0 };
	while (srcptr->link != first)
	{
		counter += 1;
		srcptr = srcptr->link;
	}
	return counter-1;
};

template<typename T>
void mycircular_list<T>::makeEmpty()
{
	LinkNode<T> *current = first->link;
	while (current->link != first)
	{
		LinkNode<T> *current = first->link;
		first = current->link;
		delete current;
	}
};

template<typename T>
LinkNode<T> *mycircular_list<T>::Search(T x) const
{
	LinkNode<T> *current = first->link;
	while (current->link != first)
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
};


template<typename T>
LinkNode<T> *mycircular_list<T>::Locate(int i) const
{
	if (i < 0)
	{
		return NULL;
	}
	int count{ 0 };
	LinkNode<T> *current = first->link;
	while (current->link != first&&count < i-1)
	{
		std::cout << "locating !" << std::endl;
		current = current->link;
		count++;
	}
	std::cout << "current:" << current->data << std::endl;
	return current;
};


template<typename T>
bool mycircular_list<T>::getData(int i, T& x) const
{
	if (i < 0)
	{
		return false;
	}
	LinkNode<T> *current = Locate(i);
	x = current->data;
	return true;
};

template<typename T>
bool mycircular_list<T>::setData(int i, T& x)
{
	if (i < 0)
	{
		return false;
	}
	LinkNode<T> *current = Locate(i);
	current->data = x;
	return true;
};

template<typename T>
bool mycircular_list<T>::Insert(int i, T& x)
{
	if (i < 0)
	{
		return false;
	}
	LinkNode<T> *newNode = new LinkNode<T>(x);
	if (newNode == NULL)
	{
		std::cerr << " 123" << std::endl;
	}
	if (i == 1)
	{
		newNode->link = first->link;
		first->link = newNode;
	}
	else
	{
		LinkNode<T> *current = Locate(i-1);
		newNode->link = current->link;
		current->link = newNode;
	}
	return true;
};

template<typename T>
void mycircular_list<T>::input(T endTag)
{
	LinkNode<T> *newNode = new LinkNode<T>;
	T val;
	makeEmpty();
	std::cout << "请输入数据： " << std::endl;
	std::cin >> val;
	//newNode = new LinkNode<T>(val);
	//newNode->link = first->link;
	//first->link = newNode;
	while (val != endTag)
	{
		newNode = new LinkNode<T>(val);
		if (newNode == NULL)
		{
			std::cerr << "内存分配错误" << std::endl;
			exit(1);
		}
		newNode->link = first->link;
		first->link = newNode;
		std::cin >> val;
	}
};


template<typename T>
void mycircular_list<T>::output()
{
	std::cout << "开始检测！" << std::endl;
	LinkNode<T> *current = first->link;
	if (first->link == NULL)
	{
		std::cout << "链表内空无一物！" << std::endl;
	}
	while (current->link != first)
	{
		std::cout << "链表内数据为：";
		std::cout << current->data << ", ";
		current = current->link;
	}
}


template<typename T>
mycircular_list<T>::~mycircular_list()
{

}





