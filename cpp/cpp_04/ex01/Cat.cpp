
#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat basic constructor called" << std::endl;
	_brain = new Brain();
	_type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		this->_type = other._type;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat basic destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}