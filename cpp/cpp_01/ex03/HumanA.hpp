
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
private:
	std::string _nameA;
	Weapon	&_wepA;
public:
	HumanA(std::string name, Weapon &Weapon);
	~HumanA();
	void attack();
	// void setWeapon(Weapon Weapon);
};

#endif
