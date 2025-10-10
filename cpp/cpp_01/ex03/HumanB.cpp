

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
	if (this->_wepB != NULL)
		std::cout << this->_nameB << " attacked with " << this->_wepB->getType() << std::endl;
	else
		std::cout << this->_nameB << " has no weapon !!" << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_wepB = &Weapon;
}