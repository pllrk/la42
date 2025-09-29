

#include "Zombie.hpp"



int main(void)
{
	Zombie *z;

	z = newZombie("On Heap	");
	z->announce();
	randomChump("On stack ");
	delete z;
	return (0);
}
