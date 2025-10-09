
#include "Harl.hpp"

Harl::Harl()
{
}

void	Harl::complain(std::string level)
{
	Levelfunction levels[4] = 
	{
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i].level)
		{
			(this->*levels[i].function)();
			return ;
		}
	}
	std::cout << "No level like this : " << level << " !" << std::endl;
	return ;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "Harl says : Debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Harl says : Info" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Harl says : Warning" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Harl says : Error" << std::endl;
}
