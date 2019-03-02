#include "SeqList.h"


template<typename T>
void SeqList<T>::reSize(int newSize)
{
	if (newSize<=0)
	{
		std::cerr << "��Ч�������С" << std::endl;
	}
	if (newSize != maxSize)
	{
		T* newarray = new T[newSize];
		if (newarray == NULL)
		{
			std::cerr << "�ڴ�������" << std::endl;
		}

		int n = last + 1;
		T* srcptr = data;
		T* destptr = newarray;
		while (n--)
		{
			*destptr++ = *srcptr;
		}
		delete[] data;
		data = newarray;
		maxSize = newSize;
	}
}

template <typename T>
SeqList::SeqList(int sz)
{
	if (sz>0)
	{
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data = nullptr)
		{
			std::cerr << "�ڴ�������" << std::endl;
			exit();
		}
	}
}

template<typename T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	if (L.IsEmpty())
	{
		std::cerr << "�����Ϊ��,����" << std::endl;
	}

	maxSize = L.Size();
	last = L.Length() - 1;
	data = new T[maxSize];
	datat = L;

}

template<typename T>
SeqList<T>::~SeqList(data)
{
}

template<typename T>
int SeqList<T>::Size() const
{

	return 0;
}

template<typename T>
int SeqList<T>::Search(T & x) const
{
	for (int i = 0;i<=last;i++)
	{
		if (data[i]==x)
		{
			return i + 1;
		}
	}
	return 0;
}

template<typename T>
int SeqList<T>::Locate(int i) const
{
	if (i>=1&&i<=last+1)
	{
		return data[i - 1];
	}
	return 0;
}

template <typename T>
SeqList::~SeqList()
{
	delete[] data;
}

template <typename T>
bool Insert(int i, T & x)
{
	if (last == maxSize)
	{
		std::cerr << "����������,������!" << std:::endl;
		return false;
	}
	else if (i<1 || i>last + 1)
	{
		std::cerr << "��������ȷ�Ĳ���λ��" << std::endl;
		return false;
	}
	else
	{
		for (int num = last;num>=i-1; num--)
		{
			data[num] = data[num - 1];
		}
		data[i - 1] = x;
		last += 1;
	}
	return true;
}

template <typename T>
bool Remove(int i, T & x)
{
	if (last == -1)
	{
		std::cerr << "��Ϊ��,����ɾ��" << std::endl;
		return false;
	}
	if (i<1||i>last+1)
	{
		std::cerr << "��������ȷ��Χ!" << std::endl;
		return false;
	}
	for (int num = i;num<last+1;num++)
	{
		data[num - 1] = data[num];
	}
	last -= 1;
	
	return true;
}
