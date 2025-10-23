
#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog basic constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog basic destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woaf" << std::endl;
}