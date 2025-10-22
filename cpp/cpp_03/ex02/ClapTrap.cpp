
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitpoint = other._hitpoint;
	this->_energypoint = other._energypoint;
	this->_attackdmg = other._attackdmg;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor name called" << std::endl;
	this->_name = name;
	this->_hitpoint = 10;
	this->_energypoint = 10;
	this->_attackdmg = 0;
}

ClapTrap::ClapTrap(std::string _name, int _hitpoint, int _energypoint, int _attackdmg)
{
	std::cout << "Constructor ClapTrap called through ScavTrap or FragTrap" << std::endl;
	this->_name = _name;
	this->_hitpoint = _hitpoint;
	this->_energypoint = _energypoint;
	this->_attackdmg = _attackdmg;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energypoint == 0)
	{
		std::cout << "Not enough energy point to attack" << std::endl;
		return ;
	}
	else 
	{
		this->_energypoint = this->_energypoint - 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdmg << " points of damage !" << std::endl;
		return ;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitpoint = this->_hitpoint - amount;
	std::cout << this->_name << " took " << amount << " of damage!" << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energypoint == 0)
	{
		std::cout << "Not enough energy point to repair" << std::endl;
		return ;
	}
	this->_hitpoint = this->_hitpoint + amount;
	std::cout << this->_name << " repaired for " << amount << " dammages." << std::endl;
	std::cout << this->_name << " now have " << this->_hitpoint << " hitpoint." << std::endl;
	return ;
}

void ClapTrap::displaystat()
{
	std::cout << this->_name << std::endl;
	std::cout << this->_hitpoint << std::endl;
	std::cout << this->_energypoint << std::endl;
	std::cout << this->_attackdmg << std::endl;
}