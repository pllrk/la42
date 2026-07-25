

#include <iostream>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	myList.push_back(5);

	int valueToFind = 40;
	std::list<int>::iterator it = easyfind(myList, valueToFind);

	if (it != myList.end())
	{
		std::cout << "Value " << valueToFind << " found in the list." << std::endl;
	}
	else
	{
		std::cout << "Value " << valueToFind << " not found in the list." << std::endl;
	}

	return 0;	
}