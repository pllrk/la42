#include <string>
#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE, false), _target("Untargeted")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE, false), _target(target)
{
	std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade(), src.isSigned()), _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	(void)src;
	return *this;
}

void ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";

	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	file.open(filename.c_str());
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
	file.close();
}