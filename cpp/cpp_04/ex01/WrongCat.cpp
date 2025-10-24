
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat basic constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat basic destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "coin (wrongcat called)" << std::endl;
}