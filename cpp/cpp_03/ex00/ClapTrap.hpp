

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
private:
	std::string		_name;
	int	_hitpoint;
	int	_energypoint;
	int	_attackdmg;

public:

	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator = (const ClapTrap &other);
	~ClapTrap();
	
	ClapTrap(std::string name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif