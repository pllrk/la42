#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(HIGHTEST_GRADE), _executeGrade(HIGHTEST_GRADE), _isSigned(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int signGrade, const unsigned int executeGrade, bool isSigned) : 
	_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(isSigned)
{
	if (signGrade < HIGHTEST_GRADE || executeGrade < HIGHTEST_GRADE)
		throw AForm::GradeTooHighException();
	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();

	std::cout << "Form parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : 
	_name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _isSigned(copy._isSigned)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

std::string AForm::getName() const
{
	return this->_name;
}

unsigned int AForm::getSignGrade() const
{
	return this->_signGrade;
}

unsigned int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

bool AForm::isSigned() const
{
	return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_executeGrade)
		throw AForm::GradeTooLowException();
	this->beExecuted();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName() << std::endl;
	os << "  Signed: " << form.isSigned() << std::endl;
	os << "  Grade to sign: " << form.getSignGrade() << std::endl;
	os << "  Grade to execute: " << form.getExecuteGrade();
	return (os);
}