

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- Test 1: increment at grade 1 ---" << std::endl;
	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << "Before increment: " << a << std::endl;
		a.incrementGrade();
		std::cout << "After increment:  " << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: decrement at grade 150 ---" << std::endl;
	try
	{
		Bureaucrat b("Bob", 150);
		std::cout << "Before decrement: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement:  " << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: valid increment from default ---" << std::endl;
	try
	{
		Bureaucrat c;
		std::cout << "Before increment: " << c << std::endl;
		c.incrementGrade();
		std::cout << "After increment:  " << c << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: invalid constructor (grade 151) ---" << std::endl;
	try
	{
		Bureaucrat d("Dave", 151);
		std::cout << d << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: getters ---" << std::endl;
	try
	{
		Bureaucrat e("Eve", 42);
		std::cout << "Name:  " << e.getName() << std::endl;
		std::cout << "Grade: " << e.getGrade() << std::endl;
		std::cout << "Full:  " << e << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return 0;
}