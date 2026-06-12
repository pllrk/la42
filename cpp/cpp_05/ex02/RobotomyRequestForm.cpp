#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE, false), _target("Untargeted")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE, false), _target(target)
{
	std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade(), src.isSigned()), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	(void)src;
	return *this;
}

void RobotomyRequestForm::beExecuted(void) const
{
	static bool seeded = false;

	if (!seeded)
	{
		std::srand((unsigned int)std::time(0));
		seeded = true;
	}
	std::cout << "Bzzzzzzzzzz... drilling noises..." << std::endl;
	int randomNumber = 1 + std::rand() / ((RAND_MAX + 1u) / 2);
	if (randomNumber == 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}