
#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog basic constructor called" << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignment called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		this->_type = other._type;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog basic destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woaf" << std::endl;
}

Brain* Dog::getBrain() const
{
	return _brain;
}