
#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << "came out the earth.." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " went back to the earth.." << std:: endl;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}
