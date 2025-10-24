
#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Meuuh" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}