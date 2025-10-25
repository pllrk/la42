
#include <iostream>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
protected:
	std::string	_type;
public:
 	Animal();
	Animal(const Animal &other);
	Animal& operator = (const Animal &other);
	virtual ~Animal();

	Animal(std::string name);
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif