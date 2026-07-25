#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <vector>
# include <algorithm>

class Span
{
	private:
		std::vector<int> _nums;
		unsigned int _max;

	public :
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int value);

		template<typename It>
		void addNumbers(It begin, It end)
		{
			if (static_cast<unsigned int>(std::distance(begin, end)) > (_max - _nums.size()))
				throw std::runtime_error("Span is full, wont add numbers");
			_nums.insert(_nums.end(), begin, end);
		}
		
		long shortestSpan() const;
		long longestSpan() const;
};

#endif
