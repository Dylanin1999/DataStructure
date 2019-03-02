#pragma once
#include "LineaerList.h"
template <typename T>
class SeqList :public Linear_List<T>
{
public:
	SeqList();
	~SeqList();
	
protected:
	T* data;
	int maxSize;
	int last; // 当前已存表项的最后位置
	void reSize(int newSize);

public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);
	~SeqList(delete[] data);
	int Size() const;
	int Length()const;
	int Search(T& x) const;
	int Locate(int i) const;5
	bool getData(int i, T& x)const;
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty();
	bool IsFull();
	void input();
	void output();
	SeqList<T> operator=(SeqList<T>& L);


private:
	const int defaultSize = 100;

};

