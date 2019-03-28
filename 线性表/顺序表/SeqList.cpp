#include "SeqList.h"


template<typename T>
void SeqList<T>::reSize(int newSize)
{
	if (newSize<=0)
	{
		std::cerr << "无效的数组大小" << std::endl;
	}
	if (newSize != maxSize)
	{
		T* newarray = new T[newSize];
		if (newarray == NULL)
		{
			std::cerr << "内存分配错误" << std::endl;
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
			std::cerr << "内存分配错误" << std::endl;
			exit();
		}
	}
}

template<typename T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	if (L.IsEmpty())
	{
		std::cerr << "传入表为空,请检查" << std::endl;
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
bool SeqList<T>::(int i, T & x)
{
	if (last == maxSize)
	{
		std::cerr << "链表已满请,请扩容!" << std:::endl;
		return false;
	}
	else if (i<1 || i>last + 1)
	{
		std::cerr << "请输入正确的插入位置" << std::endl;
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
bool SeqList<T>::Remove(int i, T & x)
{
	if (last == -1)
	{
		std::cerr << "表为空,不能删除" << std::endl;
		return false;
	}
	if (i<1||i>last+1)
	{
		std::cerr << "请输入正确范围!" << std::endl;
		return false;
	}
	for (int num = i;num<last+1;num++)
	{
		data[num - 1] = data[num];
	}
	last -= 1;
	
	return true;
}
template <typename T>
void SeqList<T>::input()
{
	std::cout << "开始建立顺序表，请输入表中的元素个数：";
	while (1)
	{
		std::cin >> last;
		if (last <= maxSize -1 )
		{
			break;
		}
		std::cout << "表元素个数输入有误，范围不能超过：" << maxSize - 1;
	}
	for (int i = 0;i<=last;i++)
	{
		std::cin >> data[i];
		std::cout << i + 1 << std::endl;
	}
}

template <typename T>
void SeqList<T>::output()
{
	std::cout << "顺序表当前元素的最后位置为：" << last << std::endl;
	if (int i = 0; i <= last;i++)
	{
		for (int i = 0;i<=last;i++)
		{
			std::cout << "#" << i + 1 << ":" << data[i] << std::endl;
		}
	}
}

template <typename T>
SeqList<T>& SeqList<T>::operator=(SeqList<T>& L)
{
	
}