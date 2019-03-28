#include "LinkNode.h"
#include "mycircular_list.h"

template <typename T>
void Josephus(mycircular_list<T>& Js, int n, int m)
{
	LinkNode<T> *p = Js.Locate(1);
	LinkNode<T> *pre = nullptr;

	int i{ 0 };
	int j{ 0 };
	for ( i = 0; i < n-1; i++)
	{
		for (j = 0; j < m; m++)
		{
			pre = p;
			p = p->link;
		}
		std::cout << "出列的人是：" << p->data << std::endl;
		pre->link = p->link;
		delete p;
		p = pre->link;
		
	}
}

int main()
{
	int x{ 100 };
	mycircular_list<int>  circular(100);
	int  m,n;
	std::cout << "输入游戏的人数和报数间隔：";
	std::cin >> n >> m;
	circular.input(1001);
	Josephus(circular, n, m);
}