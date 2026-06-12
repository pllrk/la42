#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat signer("Signer", 70);
	Bureaucrat intern("Intern", 150);

	std::cout << "\n--- Test 1: ShrubberyCreationForm ---" << std::endl;
	try
	{
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		signer.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: RobotomyRequestForm ---" << std::endl;
	try
	{
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
		intern.signForm(robot);
		signer.signForm(robot);
		boss.executeForm(robot);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: PresidentialPardonForm ---" << std::endl;
	try
	{
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}