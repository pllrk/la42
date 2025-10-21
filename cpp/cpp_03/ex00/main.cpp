
#include "ClapTrap.hpp"

int	main(void) 
{
	ClapTrap machine_1("Produit 1");
	ClapTrap machine_2(machine_1);
	std::string	test;
	ClapTrap machine_3;

	machine_1.attack(test);
	machine_1.beRepaired(10);
	machine_2.takeDamage(5);
	machine_2.beRepaired(4);
	
	machine_3 = machine_2;
	machine_3.beRepaired(2);

	ClapTrap machine_4("Produit 4");
	ClapTrap machine_5("Produit 5");
	ClapTrap machine_6("Produit 6");

	machine_4.attack(test);
	machine_4.beRepaired(10);
	machine_5.takeDamage(5);
	machine_5.beRepaired(4);
	machine_6.beRepaired(2);
	return 0;
}
