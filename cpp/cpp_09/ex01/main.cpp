#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: expected one expression as argument." << std::endl;
		return (1);
	}

	RPN	calculator;

	try
	{
		std::cout << calculator.evaluate(argv[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
