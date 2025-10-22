
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) 
{
	ClapTrap machine_1("Produit 1");
	std::cout << std::endl;
	ScavTrap test_1("scaaaavvv");
	std::cout << std::endl;
	FragTrap test_2("FRAAAAAAG");

	std::cout << std::endl;
	test_1.displaystat();
	std::cout << std::endl;
	machine_1.displaystat();
	std::cout << std::endl;
	test_1.guardGate();
	std::cout << std::endl;
	test_2.highFivesGuys();
	std::cout << std::endl;
	test_2.displaystat();
	std::cout << std::endl;

	return 0;
}
