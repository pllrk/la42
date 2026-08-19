#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

static std::string	trim(const std::string &s)
{
	std::string::size_type	begin = s.find_first_not_of(" \t\r\n");
	if (begin == std::string::npos)
		return ("");
	std::string::size_type	end = s.find_last_not_of(" \t\r\n");
	return (s.substr(begin, end - begin + 1));
}

static void	processLine(const std::string &line, const BitcoinExchange &btc)
{
	std::string::size_type	sep = line.find('|');

	if (sep == std::string::npos)
	{
		std::cerr << "Error: bad input => " << trim(line) << std::endl;
		return ;
	}

	std::string	date = trim(line.substr(0, sep));
	std::string	rawValue = trim(line.substr(sep + 1));

	if (!btc.validateDate(date))
	{
		std::cerr << "Error: bad input => "
				  << (date.empty() ? trim(line) : date) << std::endl;
		return ;
	}

	float	value = 0.0f;
	if (!btc.parseValue(rawValue, value))
	{
		// If the value side is empty there is nothing useful to echo, so show the whole line.
		std::cerr << "Error: bad input => "
				  << (rawValue.empty() ? trim(line) : rawValue) << std::endl;
		return ;
	}
	if (value < 0.0f)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value == 0.0f)
		value = 0.0f;						// "-0" parses to negative zero; print it as 0
	if (value > 1000.0f)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}

	float	rate = btc.getRate(date);
	if (rate < 0.0f)
	{
		std::cerr << "Error: no data available for " << date << " or earlier." << std::endl;
		return ;
	}

	std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange	btc;

	try
	{
		btc.loadDatabase();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	std::ifstream	input(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	std::string	line;

	// Only swallow the first line if it really is the header.
	// A failed first read means the file is empty (or is a directory, which ifstream opens happily).
	if (!std::getline(input, line))
	{
		std::cerr << "Error: empty file." << std::endl;
		return (1);
	}
	if (trim(line) != "date | value")
		processLine(line, btc);

	while (std::getline(input, line))
	{
		if (trim(line).empty())
			continue;
		processLine(line, btc);
	}

	return (0);
}
