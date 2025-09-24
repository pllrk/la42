#include "PhoneClass.hpp"

int	main(void)
{
	// PhoneBook	test;
	// Contact		test2;
	std::string str;

	while (1)
	{
		std::cout << "Enter ADD or SEARCH or EXIT" << std::endl;
		std::getline(std::cin, str);
		if (str.compare("ADD") == 0)
			PhoneBook::addContact(void);
		else if (str.compare("SEARCH") == 0)
			std::cout << "searrrch" << std::endl;
		else if (str.compare("EXIT") == 0)
		{
			std::cout << "Exited" << std::endl;
			break;
		}
	}
	return (0);
}
