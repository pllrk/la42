

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	const WrongAnimal *wronmeta = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();

	std::cout << wronmeta->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound();
	wronmeta->makeSound();

	std::cout << std::endl;

	delete wrongcat;
	delete wronmeta;
	delete j;
	delete i;
	delete meta;
	
	return 0;
}