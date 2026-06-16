
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

Intern::Intern() 
{

}

Intern::Intern(const Intern& other) 
{
	*this = other;
}

Intern::~Intern() 
{

}

Intern& Intern::operator = (const Intern& other) 
{
	(void)other; // Avoid unused parameter warning
	return *this;
}

static AForm	*createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string& formName, const std::string target)
{
	const std::string	formsNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(*formsFun[])(const std::string target) = {&createShrubbery, &createRobotomy, &createPresident};
	std::string		name = formName;

	try
	{
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		for (size_t cur = 0; cur < (sizeof(formsNames) / sizeof(formsNames[0])); ++cur)
		{
			if (name == formsNames[cur])
			{
				AForm *createdForm = formsFun[cur](target);
				std::cout << "Intern creates " << formsNames[cur] << std::endl;
				return (createdForm);
			}
		}
		throw std::invalid_argument("Intern cannot create form \"" + formName + "\"");
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (NULL);
	}
}