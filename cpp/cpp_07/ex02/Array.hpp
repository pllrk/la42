
#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T* 				_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;

		class out_of_range : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# include "Array.tpp"

#endif
