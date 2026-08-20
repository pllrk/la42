#include "RPN.hpp"
#include <sstream>
#include <cctype>

/* ================== Orthodox Canonical Form ================== */

RPN::RPN() {}

RPN::RPN(const RPN &other) : _operands(other._operands) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_operands = other._operands;
	return (*this);
}

RPN::~RPN() {}

/* ================== Token classification ================== */

bool	RPN::isOperator(const std::string &token) const
{
	if (token.length() != 1)
		return (false);

	char	c = token[0];
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	RPN::isOperand(const std::string &token) const
{
	// The subject guarantees every operand fed to the program is a single digit
	// (< 10). Anything longer is therefore not a valid operand token.
	if (token.length() != 1)
		return (false);

	return (std::isdigit(static_cast<unsigned char>(token[0])) != 0);
}

/* ================== Arithmetic ================== */

int	RPN::applyOperator(char op, int left, int right) const
{
	switch (op)
	{
		case '+' :
			return (left + right);
		case '-' :
			return (left - right);
		case '*' :
			return (left * right);
		case '/' :
			if (right == 0)
				throw DivisionByZero();
			return (left / right);
	}
	throw BadToken();	// unreachable: isOperator() already filtered the token
}

/* ================== Evaluation ================== */

int	RPN::evaluate(const std::string &expression)
{
	// Start from a clean slate so the same object can evaluate several
	// expressions without leftovers from a previous (possibly failed) run.
	_operands.clear();

	std::stringstream	ss(expression);
	std::string			token;

	// operator>> on a stringstream splits on any run of whitespace,
	// so "8 9  *" and "8\t9 *" tokenize identically.
	while (ss >> token)
	{
		if (isOperand(token))
		{
			_operands.push_back(token[0] - '0');	// '7' - '0' == 7
			continue ;
		}

		if (!isOperator(token))
			throw BadToken();

		if (_operands.size() < 2)
			throw MissingOperand();

		// back() is the top of the stack, so the FIRST value taken is the
		// RIGHT-hand operand: it was pushed last.
		// Getting this backwards silently breaks '-' and '/' only.
		int	right = _operands.back();
		_operands.pop_back();
		int	left = _operands.back();
		_operands.pop_back();

		_operands.push_back(applyOperator(token[0], left, right));
	}

	if (_operands.empty())
		throw MissingOperand();		// empty or whitespace-only expression
	if (_operands.size() > 1)
		throw LeftoverOperand();	// e.g. "1 2 3 +" leaves two values behind

	return (_operands.back());
}

/* ================== Exceptions ================== */

const char	*RPN::BadToken::what() const throw()
{
	return ("Error: invalid token in expression.");
}

const char	*RPN::MissingOperand::what() const throw()
{
	return ("Error: not enough operands.");
}

const char	*RPN::LeftoverOperand::what() const throw()
{
	return ("Error: too many operands.");
}

const char	*RPN::DivisionByZero::what() const throw()
{
	return ("Error: division by zero.");
}
