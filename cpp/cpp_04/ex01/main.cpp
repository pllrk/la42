

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* c = new Cat();

	c->makeSound();
	j->makeSound();

	delete j;//should not create a leak
	delete c;
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	const int size = 4;
	Animal *animals[size];

	for (int i = 0; i < size; ++i)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < size; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << std::endl;
	std::cout << std::endl;

	Dog dog1;
	dog1.getBrain()->setIdea(0, "Bark");
	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "coucher");
	std::cout << "Dog1 idea : " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea : " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}