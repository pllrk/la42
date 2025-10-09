
#include <iostream>
#include <string>

#ifndef HARL_HPP
# define HARL_HPP

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	struct Levelfunction
	{
		std::string level;
		void (Harl::*function)(void);
	};
	

public:
	Harl();
	~Harl();
	void	complain(std::string level);
};


#endif