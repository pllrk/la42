#ifndef	BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange
{
	private :
		std::string						_dbPath;
		std::map<std::string, float>	_database;

	public :
		BitcoinExchange();
		BitcoinExchange(const std::string &dbPath);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadDatabase();
		float	getRate(const std::string &date) const;
		bool	validateDate(const std::string &date) const;
		bool	parseValue(const std::string &value, float &out) const;

		class	CantReadDataFile : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

#endif
