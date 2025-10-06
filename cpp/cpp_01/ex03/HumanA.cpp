

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon): _nameA(name), _wepA(Weapon)
{
	std::cout << "HumanA " << name << " took " << _wepA.getType() << std::endl;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << this->_nameA << " attacks with their " << this->_wepA.getType() << std::endl;
	return ;
}

// void	HumanA::setWeapon(Weapon Weapon)
// {
// 	this->_wepA = Weapon;
// }
