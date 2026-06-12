
#ifndef PRESIDENTIALPARDONFORM_CLASS_H
# define PRESIDENTIALPARDONFORM_CLASS_H

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

# undef SIGN_GRADE
# define SIGN_GRADE 25
# undef EXEC_GRADE
# define EXEC_GRADE 5

class PresidentialPardonForm: public AForm
{
	private:
		const std::string _target;
		void beExecuted(void) const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator =(const PresidentialPardonForm &src);
};

#endif