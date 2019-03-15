#include "mycircular_list.h"
#include <iostream>

int main()
{
	int a{ 100 };
	mycircular_list<int> *circular_list = new mycircular_list<int>(a);


	circular_list->input(9);
	circular_list->output();
	int length = circular_list->Length();
	std::cout << "Length: " << length << std::endl;


	int x = 2;
	circular_list->Insert(2,x);
	circular_list->output();
	length = circular_list->Length();
	std::cout << "Length: " << length << std::endl;

	int index = 6;
	std::cout<<"result of search: " <<circular_list->Search(index)->data<<std::endl;


	std::cout << "result of head: " << circular_list->getHead()->data << std::endl;

	return 0;
}