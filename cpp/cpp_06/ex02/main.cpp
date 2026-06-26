#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "base.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (std::cout << "Generating A..." << std::endl, new A());
		case 1:
			return (std::cout << "Generating B..." << std::endl, new B());
		case 2:
			return (std::cout << "Generating C..." << std::endl, new C());
		default:
			return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
std::cout << "(identify Base*)A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "(identify Base*)B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "(identify Base*)C" << std::endl;
	else
		std::cout << "(identify Base*)Unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "(identify Base&)A" << std::endl;
	}
	catch (const std::exception &e)
	{
		(void) e;
	}

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "(identify Base&)B" << std::endl;
	}
	catch (const std::exception &e)
	{
		(void) e;
	}

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "(identify Base&)C" << std::endl;
	}
	catch (const std::exception &e)
	{
		(void) e;
	}
}

int main(void)
{
	std::srand(std::time(0));
	for (int cur = 0; cur < 2; ++cur)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
}
