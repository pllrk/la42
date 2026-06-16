#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

static void runInternTest(Intern &intern, const std::string &formName, const std::string &target,
	Bureaucrat &signer, Bureaucrat &executor)
{
	std::cout << "\n--- Request: \"" << formName << "\" for target \"" << target << "\" ---" << std::endl;
	AForm *form = intern.makeForm(formName, target);

	if (!form)
		return ;
	try
	{
		signer.signForm(*form);
		executor.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error during form workflow: " << e.what() << std::endl;
	}
	delete form;
}

int main()
{
	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	manager("Manager", 70);
	Bureaucrat	internBureaucrat("Intern Bureaucrat", 150);

	std::cout << "=== Intern Form Factory Tests ===" << std::endl;

	// Valid: shrubbery creation (signed/executed by boss)
	runInternTest(intern, "shrubbery creation", "home", boss, boss);

	// Valid with mixed case: should still be found after lowercase conversion.
	runInternTest(intern, "RoBoToMy ReQuEsT", "Bender", manager, boss);

	// Valid: presidential pardon
	runInternTest(intern, "presidential pardon", "Arthur Dent", boss, boss);

	// Invalid form name: makeForm should print explicit error and return NULL.
	runInternTest(intern, "coffee request", "Office", boss, boss);

	// Valid form but signing should fail due to low grade.
	runInternTest(intern, "robotomy request", "Marvin", internBureaucrat, boss);

	return (0);
}