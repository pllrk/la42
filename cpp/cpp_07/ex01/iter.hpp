
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> //size_t

template <typename T>
void	iter(T *array, const size_t length, void (*fun)(T&))
{
	for (size_t i = 0; i < length; i++)
		fun(array[i]);
}

template <typename T>
void	iter(const T *array, const size_t length, void (*fun)(T&))
{
	for (size_t i = 0; i < length; i++)
		fun(array[i]);
}

#endif
