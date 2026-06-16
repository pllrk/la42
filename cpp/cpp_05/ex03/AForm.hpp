

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string 	_name;
	const unsigned int 	_signGrade;
	const unsigned int 	_executeGrade;
	bool 				_isSigned;

	virtual void beExecuted(void) const = 0;

public:
	AForm();
	AForm(const std::string name, const unsigned int signGrade, const unsigned int executeGrade, bool isSigned);
	AForm(const AForm &copy);
	virtual ~AForm();
	AForm &operator=(const AForm &src);
	
	std::string 	getName() const;
	bool 			isSigned() const;
	unsigned int 	getSignGrade() const;
	unsigned int 	getExecuteGrade() const;
	
	void 			beSigned(const Bureaucrat &bureaucrat);
	void 			execute(const Bureaucrat &executor) const;

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

	class FormNotSignedException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &Form);

#endif