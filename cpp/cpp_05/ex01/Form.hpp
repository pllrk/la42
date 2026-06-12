

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;

public:
	Form();
	Form(const std::string name, const int signGrade, const int executeGrade, bool isSigned);
	Form(const Form &copy);
	~Form();
	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif