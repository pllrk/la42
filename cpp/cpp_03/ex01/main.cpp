
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) 
{
	ClapTrap machine_1("Produit 1");
	ScavTrap test_1("scaaaavvv");

	test_1.displaystat();
	machine_1.displaystat();
	test_1.guardGate();


	return 0;
}
