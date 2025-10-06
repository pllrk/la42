

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _wepB(NULL)
{
	this->_nameB = name;
	std::cout << "HumanB " << name << " has no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << this->_nameB << " attacked with " << this->_wepB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_wepB = &Weapon;
}