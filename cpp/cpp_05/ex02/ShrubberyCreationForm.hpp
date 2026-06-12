#ifndef SHRUBBERYCREATIONFORM_CLASS_H
# define SHRUBBERYCREATIONFORM_CLASS_H

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

# undef SIGN_GRADE
# define SIGN_GRADE 145
# undef EXEC_GRADE
# define EXEC_GRADE 137

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _target;
		void beExecuted(void) const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator =(const ShrubberyCreationForm &src);
};

#endif