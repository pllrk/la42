

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap& operator = (const FragTrap &other);
	~FragTrap();
	// Besoin de ça au dessus car déjà dans la classe ClapTrap ?
	
	FragTrap(std::string _name, int _hitpoint = 100, int _energypoint = 100, int _attackdmg = 30) : ClapTrap(_name, _hitpoint, _energypoint, _attackdmg) {};

	void	attack(const std::string& target);
	void	highFivesGuys();

	void	displaystat();
};
