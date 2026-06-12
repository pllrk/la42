

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n--- Test 1: Form display and signing ---" << std::endl;
	try
	{
		Form formA("Tax form", 50, 25, false);
		Bureaucrat signer("Frank", 42);
		std::cout << "Before signing:\n" << formA << std::endl;
		std::cout << signer.getName() << " tries to sign " << formA.getName() << " with grade " << signer.getGrade() << std::endl;
		signer.signForm(formA);
		std::cout << "After signing:\n" << formA << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Form signing failure ---" << std::endl;
	try
	{
		Form formB("Permit", 10, 5, false);
		Bureaucrat lowRank("Greg", 100);
		std::cout << formB << std::endl;
		std::cout << lowRank.getName() << " tries to sign " << formB.getName() << " with grade " << lowRank.getGrade() << std::endl;
		lowRank.signForm(formB);
		std::cout << "After signing attempt:\n" << formB << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}