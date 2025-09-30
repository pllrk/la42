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
		Zombie();
		~Zombie();
		void announce(void) const;
		void set_name(std::string name);
};

#endif

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie	*zombieHorde( int N, std::string name );
