# include <cstdlib>
# include <ctime>
# include <iostream>
# include <list>
# include <string>
# include <vector>
# include "Span.hpp"

static void printHeader(const std::string &title)
{
	std::cout << "\n===== " << title << " =====\n";
}

static void printStats(const Span &sp, const std::string &label)
{
	try
	{
		std::cout << label << " shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << label << " longest span : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << label << " error: " << e.what() << std::endl;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	printHeader("Basic example");
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printStats(sp, "Basic");
	}

	printHeader("Capacity limit");
	{
		Span sp(3);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
		}
		catch (const std::exception &e)
		{
			std::cout << "Overflow handled: " << e.what() << std::endl;
		}
	}

	printHeader("Not enough values");
	{
		Span sp(10);
		try
		{
			sp.addNumber(42);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Shortest-span guard: " << e.what() << std::endl;
		}

		try
		{
			Span empty(10);
			std::cout << empty.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Longest-span guard: " << e.what() << std::endl;
		}
	}

	printHeader("Range insertion from vector");
	{
		std::vector<int> values;
		for (int i = 0; i < 6; ++i)
			values.push_back(i * 10);

		Span sp(6);
		sp.addNumbers(values.begin(), values.end());
		printStats(sp, "Vector");
	}

	printHeader("Range insertion from list");
	{
		std::list<int> values;
		for (int i = 1; i <= 5; ++i)
			values.push_back(i * -5);

		Span sp(5);
		sp.addNumbers(values.begin(), values.end());
		printStats(sp, "List");
	}

	printHeader("Duplicates and negatives");
	{
		Span sp(6);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(-5);
		sp.addNumber(-5);
		sp.addNumber(20);
		sp.addNumber(-15);
		printStats(sp, "Signed");
	}

	printHeader("Large stress test");
	{
		Span sp(10001);
		for (int i = 0; i < 10001; ++i)
			sp.addNumber(std::rand() % 1000000);
		printStats(sp, "Random");
	}

	printHeader("addNumbers overflow");
	{
		Span sp(3);
		std::vector<int> values;
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);

		try
		{
			sp.addNumbers(values.begin(), values.end());
		}
		catch (const std::exception &e)
		{
			std::cout << "addNumbers overflow handled: " << e.what() << std::endl;
		}
	}
	return (0);
}
