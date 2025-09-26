#include "PhoneClass.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	// Contact		test2;
	std::string str;

	while (std::cin)
	{
		std::cout << "Enter ADD or SEARCH or EXIT" << std::endl;
		std::getline(std::cin, str);
		if (str.compare("ADD") == 0)
			phonebook.addContact();
		else if (str.compare("SEARCH") == 0)
			phonebook.searchContact();
		else if (str.compare("EXIT") == 0 || std::cin.eof())
			break;
	}
	std::cout << "Exited" << std::endl;
	return (0);
}
