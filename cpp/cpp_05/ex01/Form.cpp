#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _executeGrade(150), _isSigned(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade, bool isSigned) : 
	_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(isSigned)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();

	std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(const Form &copy) : 
	_name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _isSigned(copy._isSigned)
{
std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << std::endl;
	os << "  Signed: " << (form.isSigned() ? "yes" : "no") << std::endl;
	os << "  Grade to sign: " << form.getSignGrade() << std::endl;
	os << "  Grade to execute: " << form.getExecuteGrade();
	return (os);
}