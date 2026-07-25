#include "Span.hpp"

Span::Span(unsigned int N) : _max(N){}

Span::Span(const Span &other)
{
	*this = other;
}

Span 		&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_max = other._max;
		_nums = other._nums;
	}
	return (*this);
}

Span::~Span() {};

void 		Span::addNumber(int value)
{
	if (_nums.size() >= _max)
		throw std::runtime_error("It's full");
	_nums.push_back(value);
}

long 		Span::shortestSpan() const
{
	if (_nums.size() < 2)
		throw std::runtime_error("Not enough nums to do things");
	
	std::vector<int> tmp = _nums;
	std::sort(tmp.begin(), tmp.end());

	long shortest = static_cast<long>(tmp[1]) - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++)
	{
		long span = static_cast<long>(tmp[i]) - tmp[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

long 		Span::longestSpan() const
{
	if (_nums.size() < 2)
		throw std::runtime_error("Not enough nums to do things");
	std::vector<int>::const_iterator minIt = std::min_element(_nums.begin(), _nums.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_nums.begin(), _nums.end());
	return (static_cast<long>(*maxIt) - static_cast<long>(*minIt));
}
