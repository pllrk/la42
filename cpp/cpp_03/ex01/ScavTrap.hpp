
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator = (const ScavTrap &other);
	~ScavTrap();
	// Besoin de ça au dessus car déjà dans la classe ClapTrap ?
	
	ScavTrap(std::string _name, int _hitpoint = 100, int _energypoint = 50, int _attackdmg = 20) : ClapTrap(_name, _hitpoint, _energypoint, _attackdmg) {};

	void	attack(const std::string& target);
	void	guardGate();

	void	displaystat();
};
