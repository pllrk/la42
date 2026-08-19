#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>

/* ================== Orthodox Canonical Form ================== */

BitcoinExchange::BitcoinExchange() : _dbPath("data.csv") {}

BitcoinExchange::BitcoinExchange(const std::string &dbPath) : _dbPath(dbPath) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _dbPath(other._dbPath), _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_dbPath = other._dbPath;
		_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/* ================== Database ================== */

void	BitcoinExchange::loadDatabase()
{
	std::ifstream file(_dbPath.c_str());
	if (!file.is_open())
		throw CantReadDataFile();

	std::string line;
	std::getline(file, line);				// skip the "date,exchange_rate" header

	while (std::getline(file, line))
	{
		std::stringstream ss(line);			// wrap the line so we can cut it field by field
		std::string date, rawValue;			// left of the comma / right of the comma

		if (!std::getline(ss, date, ',') || !std::getline(ss, rawValue))
			continue;						// no comma at all -> malformed row, ignore it

		float rate = 0.0f;
		if (!parseValue(rawValue, rate))
			continue;
		_database[date] = rate;
	}
}

/* ================== Exchange logic ================== */

float	BitcoinExchange::getRate(const std::string &date) const
{
	if (_database.empty())
		return (-1.0f);

	// ISO dates are fixed-width and zero-padded, so lexicographic order == chronological order.
	// lower_bound gives the first key that is NOT less than `date`, i.e. the first key >= date.
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return (it->second);				// exact match

	if (it == _database.begin())
		return (-1.0f);						// every key is later: no lower date exists

	--it;									// step back to the greatest key strictly below `date`
	return (it->second);
}

/* ================== Validation ================== */

bool	BitcoinExchange::validateDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (std::string::size_type i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);

	int	daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// A year is leap if divisible by 4, EXCEPT centuries, which must also be divisible by 400.
	// 1900 -> not leap, 2000 -> leap.
	bool	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (leap)
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return (false);

	return (true);
}

bool	BitcoinExchange::parseValue(const std::string &value, float &out) const
{
	std::string::size_type	begin = value.find_first_not_of(" \t\r\n");
	if (begin == std::string::npos)
		return (false);						// empty or whitespace only
	std::string::size_type	end = value.find_last_not_of(" \t\r\n");
	std::string				s = value.substr(begin, end - begin + 1);

	// Reject anything that is not part of a plain decimal number.
	// This is what stops "inf" and "nan", which some libstdc++ versions would happily read.
	for (std::string::size_type i = 0; i < s.length(); ++i)
	{
		char	c = s[i];
		if (!std::isdigit(static_cast<unsigned char>(c)) && c != '.' && c != '+' && c != '-')
			return (false);
	}

	std::stringstream	ss(s);
	float				f = 0.0f;

	ss >> f;
	if (ss.fail())
		return (false);						// nothing numeric at the front
	ss >> std::ws;							// eat trailing blanks
	if (!ss.eof())
		return (false);						// leftovers, e.g. "1.2abc" or "1.2.3"

	out = f;
	return (true);
}

/* ================== Exception ================== */

const char	*BitcoinExchange::CantReadDataFile::what() const throw()
{
	return ("Error: could not open file.");
}
