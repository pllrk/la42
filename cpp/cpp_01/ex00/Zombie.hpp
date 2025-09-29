#include <iostream>
#include <string>


#ifndef ZOMBIE_CLASS
# define ZOMBIE_CLASS

class	Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);	
		~Zombie();
		void announce(void) const;
};

#endif

Zombie *newZombie(std::string name);
void	randomChump(std::string name);
