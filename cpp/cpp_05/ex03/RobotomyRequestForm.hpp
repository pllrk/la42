#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
# undef SIGN_GRADE
# define SIGN_GRADE 72
# undef EXEC_GRADE
# define EXEC_GRADE 45

class RobotomyRequestForm: public AForm
{
	private:
		const std::string _target;
		void beExecuted(void) const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator =(const RobotomyRequestForm &src);
};

#endif