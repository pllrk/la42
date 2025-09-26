#include <iostream>
#include <string>


#ifndef ZOMBIE_CLASS
# define ZOMBIE_CLASS

class Zombie
{
private:
	std::string name;
	
	
public:
	Zombie(/* args */);
	
	void announce(void) const;
	

	~Zombie();
};

Zombie::Zombie(void)
{
}

Zombie::~Zombie()
{
}


#endif