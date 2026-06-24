#include "Convertor.hpp"
#include <iostream>
#include <sstream>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <limits>

Convertor::Convertor() {}
Convertor::~Convertor() {}

static bool myIsNan(double value)
{
	return (value != value);
}

static bool myIsInf(double value)
{
	return (value == std::numeric_limits<double>::infinity()
			|| value == -std::numeric_limits<double>::infinity());
}

bool hasDecimalOrExponent(const std::string& literal)
{
	return (literal.find('.') != std::string::npos
			|| literal.find('e') != std::string::npos
			|| literal.find('E') != std::string::npos
			|| literal == "nan" || literal == "+inf" || literal == "-inf"
			|| literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool isCharLiteral(const std::string& literal)
{
	if (literal.size() != 1)
		return false;
	if (std::isdigit(static_cast<unsigned char>(literal[0])))
		return false; // a single digit is treated as int, not char
	return (std::isprint(static_cast<unsigned char>(literal[0])) != 0);
}

// Checks the digit string (no sign) against INT_MAX or the magnitude of INT_MIN,
// avoiding any reliance on errno for overflow detection.
static bool digitsExceedIntLimit(const std::string& digits, bool negative)
{
	std::ostringstream oss;
	if (negative)
		oss << -static_cast<long>(INT_MIN); // magnitude of INT_MIN, safe as long
	else
		oss << INT_MAX;
	std::string limit = oss.str();

	if (digits.size() > limit.size())
		return true;
	if (digits.size() == limit.size() && digits > limit)
		return true;
	return false;
}

bool isIntLiteral(const std::string& literal)
{
	if (literal.empty())
		return false;

	bool negative = (literal[0] == '-');
	std::string::size_type start = 0;
	if (literal[0] == '+' || literal[0] == '-')
	{
		if (literal.size() == 1)
			return false;
		start = 1;
	}

	std::string digits = literal.substr(start);

	for (std::string::size_type i = 0; i < digits.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(digits[i])))
			return false;
	}

	if (digitsExceedIntLimit(digits, negative))
		return false;

	return true;
}

bool isFloatLiteral(const std::string& literal)
{
	if (literal.size() < 2 || literal[literal.size() - 1] != 'f')
		return false;

	std::string core = literal.substr(0, literal.size() - 1);

	if (core == "nan" || core == "+inf" || core == "-inf")
		return true;

	if (!hasDecimalOrExponent(core))
		return false;

	char *end = 0;
	std::strtod(core.c_str(), &end);

	return (*end == '\0');
}

bool isDoubleLiteral(const std::string& literal)
{
	if (literal.empty())
		return false;
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	if (!hasDecimalOrExponent(literal))
		return false;

	char *end = 0;
	std::strtod(literal.c_str(), &end);

	return (*end == '\0');
}

void printAsChar(double value, bool isSpecial)
{
	std::cout << "char: ";
	if (isSpecial || value < 0 || value > 127 || myIsNan(value) || myIsInf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}

	int intValue = static_cast<int>(value);
	if (!std::isprint(intValue))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
}

void printAsInt(double value, bool isSpecial)
{
	std::cout << "int: ";
	if (isSpecial || myIsNan(value) || myIsInf(value) || value < INT_MIN || value > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void printAsFloat(double value)
{
	std::cout << "float: ";
	if (myIsNan(value))
		std::cout << "nanf" << std::endl;
	else if (myIsInf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		std::cout << std::fixed;
		float f = static_cast<float>(value);
		std::cout.precision(1);
		std::cout << f << "f" << std::endl;
	}
}

void printAsDouble(double value)
{
	std::cout << "double: ";
	if (myIsNan(value))
		std::cout << "nan" << std::endl;
	else if (myIsInf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << value << std::endl;
	}
}

void Convertor::convert(const std::string& literal)
{
	double value = 0.0;
	bool isSpecial = false;

	if (isCharLiteral(literal))
	{
		value = static_cast<double>(literal[0]);
	}
	else if (isIntLiteral(literal))
	{
		value = static_cast<double>(std::strtol(literal.c_str(), 0, 10));
	}
	else if (isFloatLiteral(literal) || isDoubleLiteral(literal))
	{
		std::string core = literal;
		if (!core.empty() && core[core.size() - 1] == 'f')
			core = core.substr(0, core.size() - 1);

		if (core == "nan" || core == "+inf" || core == "-inf")
			isSpecial = true;

		value = std::strtod(core.c_str(), 0);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printAsChar(value, isSpecial);
	printAsInt(value, isSpecial);
	printAsFloat(value);
	printAsDouble(value);
}