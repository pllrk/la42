
#include "Harl.hpp"

int	main(void)
{
	std::string level;
	Harl		Larh;

	std::cout << "Enter : DEBUG, INFO, WARNING, or ERROR" << std::endl;
	std::getline(std::cin, level);
	Larh.complain(level);
	return (0);	
}
