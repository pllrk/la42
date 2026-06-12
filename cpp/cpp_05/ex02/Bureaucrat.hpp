

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

# define HIGHTEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

class Bureaucrat
{
	private :
		const std::string 	_name;
		unsigned int		_grade;
	
	public :
		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &src);

		std::string		getName() const;
		unsigned int	getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form) const;
		void executeForm(AForm const &form) const;

		class GradeTooHighException: public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif