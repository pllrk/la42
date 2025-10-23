
#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat basic constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat basic destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}