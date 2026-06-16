
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE, false), _target("Untargeted")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE, false), _target(target)
{
	std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade(), src.isSigned()), _target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	(void)src;
	return *this;
}

void PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}