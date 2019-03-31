#include "stack.h"
#include <iostream>
#include <stdio.h>
#include <string>

const int maxLength = 100;
void PrintMatchedPairs(char *expression)
{
	Stack<int> s(maxLength);
	int length = strlen(expression);
	int res{ 0 };
	for (int i = 1;i<length;i++)
	{
		if (expression[i-1] == '(')
		{
			s.Push(i);
		}
		else if(expression[i-1] == ')')
		{
			if (s.Pop(res) == true)
			{
				std::cout << res << "��" << i << "ƥ��" << std::endl;
			}
			else
			{
				std::cout <<"û�����"<<i<<"��������ƥ���������"<<std::endl;
			}
		}
	}
	while (s.IsEmpty())
	{
		s.Pop(res);
		std::cout << "û�����" << res << "��������ƥ���������"<<std::endl;
	}
}