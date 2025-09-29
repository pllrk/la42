
#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie Foo = Zombie(name);
	Foo.announce();
	return ;
}
