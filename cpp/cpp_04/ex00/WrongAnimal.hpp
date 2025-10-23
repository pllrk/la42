
#include "Animal.hpp"

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP


class WrongAnimal
{
protected:
	std::string	_type;
public:
 	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal& operator = (const WrongAnimal &other);
	~WrongAnimal();

	WrongAnimal(std::string name);
	void makeSound() const;
	std::string getType() const;
};

#endif