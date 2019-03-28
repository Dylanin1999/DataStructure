#pragma once
#include <iostream>
using namespace std;
template<class T>
class Linear_List
{
public:
	Linear_List();
	~Linear_List();
	virtual int Size() const = 0; 
	virtual int Length() const = 0;
	virtual int Search(T& x) const = 0;
	virtual int Locate(int i) const = 0;
	virtual bool getData(int i, T& x) const = 0;
	virtual void setData(int i, T& x) = 0;
	virtual bool Insert(int i, T& x) = 0;
	virtual bool Remove(int i, T& x) = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual void sort() = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	virtual Linear_List<T> operator=(Linear_List<T>& L) = 0;
private:
};


