

#include "iter.hpp"
#include <iostream>
#include <string>
#include <algorithm>

void increment(int &n)
{
	n++;
}

void printString(std::string &str)
{
	std::cout << str << std::endl;
}

void toUpperCase(std::string &str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void display(const int &n)
{
	std::cout << n << std::endl;
}

int main(void)
{
	int		arrayInt[] = {1, 2, 3, 4, 5};
	std::string	arrayString[] = {"Hello", "World", "!"};
	const int const_arrayInt[] = {10, 20, 30, 40, 50};

	iter(arrayInt, 5, increment);
	for (int i = 0; i < 5; i++)
		std::cout << arrayInt[i] << std::endl;
	iter(arrayString, 3, printString);
	iter(arrayString, 3, toUpperCase);
	iter(arrayString, 3, printString);
	iter(const_arrayInt, 5, display);

	return (0);
}

