#pragma once
#include "Dbl_Node.h"
#include <iostream>
template <typename T>
class DblList
{
public:
	DblList(T uniqueVal);
	~DblList();
	int Length() const;
	bool IsEmpty();
	DblNode<T> *getHead() const;
	void setHead(DblNode<T> *ptr);
	DblNode<T> *Search(const T& x);
	DlbNode<T> *Locate(int i, int d);
	bool Insert(int i, const T& x, int d);
	bool Remove(int i, T& x, int d);
private:
	DblNode *first;

};

template <typename T>
DblList

template <typename T>
DblList::DblList(T uniqueVal)
{
	first = new DblNode<T>(uniqueVal);
	if (first == nullptr)
	{
		std::cerr << "ÄÚ´æ·ÖÅä´íÎó£¡" << std::endl;
	}
	first->rLink = first->lLink = first;
}


template<typename T>
int DblList<T>::Length() const
{
	DblNode *current = first->rLink;
	if (current == nullptr)
	{
		std::cerr << "³öÏÖ´íÎó£¡" << std::endl;
	}
	int counter{ 0 };
	while (current->rLink!=first->lLink)
	{
		counter++;
		current = current->rLink;
	}
	return counter;
}

template<typename T>
DblNode<T> *DblList<T>::Search(const T& x)
{
	DblNode *current = first->rLink;
	while (current->lLink != first && current->data != x)
	{
		current = current->rLink;
	}
	if (current->rLink != first)
	{
		return current;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
DblNode *DblList<T>::Locate(int i, int d)
{
	if (first->rLink == first || i = 0)
	{
		return first;
	}
	DblNode<T> *current;
	if (d == 0)
	{
		current = first->lLink;
	}
	else
	{
		current = first->rLink;
	}
	for (int j = 1;j<i;j++)
	{
		if (current == first)
		{
			break;
		}
		else if (d == 0)
		{
			current = current->lLink;
		}
		else
		{
			current = current->rLink;
		}
	}
	if (current != first)
	{
		return current;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
bool DblList<T>::Insert(int i, const T& x, int d)
{
	DblNode<T> *current = Locate(i, d);
	if (current == nullptr)
	{
		return false;
	}
	DblNode<T> *newNode = new DblNode<T>(x);
	if (newNode == nullptr)
	{
		std::cerr << "´æ´¢·ÖÅäÊ§°Ü£¡" << std::endl;
		exit(1);
	}
	if (d == 0)
	{
		newNode->lLink = current->lLink;
		current->lLink = newNode;
		newNode->lLink->rLink = newNode;
		newNode->rLink = current;
	}
	else
	{
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	return true;
}


template<typename T>
bool DblList<T>::Remove(int i, T& x, int d)
{
	DblNode<T> *current = Locate(i, d);
	if (current == nullptr)
	{
		return false;
	}
	current->rLink->lLink = current->lLink;
	current->lLink->rLink = current->rLink;
	x = current->data;
	delete current;
	return true;
}





template <typename T>
DblList::~DblList()
{
}