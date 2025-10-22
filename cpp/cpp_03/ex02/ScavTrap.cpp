#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap basic constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitpoint = other._hitpoint;
	this->_energypoint = other._energypoint;
	this->_attackdmg = other._attackdmg;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap basic destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energypoint == 0)
	{
		std::cout << "Not enough energy point to attack" << std::endl;
		return ;
	}
	else 
	{
		this->_energypoint = this->_energypoint - 1;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdmg << " points of damage !" << std::endl;
		return ;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap in Gate Keeper Mode" << std::endl;
}

void ScavTrap::displaystat()
{
	std::cout << this->_name << std::endl;
	std::cout << this->_hitpoint << std::endl;
	std::cout << this->_energypoint << std::endl;
	std::cout << this->_attackdmg << std::endl;
}