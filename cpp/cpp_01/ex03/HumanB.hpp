
#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
private:
	std::string _nameB;
	Weapon	*_wepB;
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &Weapon);
};

#endif
