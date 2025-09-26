

#include "Zombie.hpp"



void Zombie::announce(void) const
{
	std::cout << this << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}


int main(void)
{
	while (1)
	{
		std::cout << "Enter New or Chump or EXIT" << std::endl;
		std::getline(std::cin, str);
		if (str.compare("ADD") == 0)
			phonebook.addContact();
		else if (str.compare("SEARCH") == 0)
			phonebook.searchContact();
		else if (str.compare("EXIT") == 0 || std::cin.eof())
		{
			std::cout << "Exited" << std::endl;
			break;
		}
	}
	//free the heap zombies
	return (0);
}