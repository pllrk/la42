

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	/* data */
public:
	Form();
	Form(const std::string name, int grade);
	Form(const Form &copy);
	~Form();
};

Form::Form(/* args */)
{
}

Form::~Form()
{
}


#endif