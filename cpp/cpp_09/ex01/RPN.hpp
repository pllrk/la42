#ifndef	RPN_HPP
# define RPN_HPP

#include <list>
#include <string>
#include <exception>

class RPN
{
	private :
		// A raw std::list used as a LIFO stack:
		//   push        -> push_back()
		//   look at top -> back()
		//   remove top  -> pop_back()
		// No adaptor, so the container actually spent for this module is
		// unambiguously std::list. vector and deque stay free for ex02.
		std::list<int>	_operands;

		bool	isOperator(const std::string &token) const;
		bool	isOperand(const std::string &token) const;
		int		applyOperator(char op, int left, int right) const;

	public :
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int		evaluate(const std::string &expression);

		class	BadToken : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class	MissingOperand : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class	LeftoverOperand : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class	DivisionByZero : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

#endif
