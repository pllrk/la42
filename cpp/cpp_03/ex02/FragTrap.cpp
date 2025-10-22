#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap basic constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitpoint = other._hitpoint;
	this->_energypoint = other._energypoint;
	this->_attackdmg = other._attackdmg;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitpoint = other._hitpoint;
		this->_energypoint = other._energypoint;
		this->_attackdmg = other._attackdmg;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap basic destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energypoint == 0)
	{
		std::cout << "Not enough energy point to attack" << std::endl;
		return ;
	}
	else 
	{
		this->_energypoint = this->_energypoint - 1;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdmg << " points of damage !" << std::endl;
		return ;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "High-five requested" << std::endl;
}

void FragTrap::displaystat()
{
	std::cout << this->_name << std::endl;
	std::cout << this->_hitpoint << std::endl;
	std::cout << this->_energypoint << std::endl;
	std::cout << this->_attackdmg << std::endl;
}