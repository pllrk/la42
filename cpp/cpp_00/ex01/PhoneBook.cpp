#include "PhoneClass.hpp"

PhoneBook::PhoneBook(void) : contactnbr(1), oldestindex(1)
{
}

void PhoneBook::addContact(void)
{
	std::string firstname, lastname, nickname, phonenumber, darksecret;

	std::cout << "First name ?" << std::endl;
	std::getline(std::cin, firstname);
	
	std::cout << "Last name ?" << std::endl;
	std::getline(std::cin, lastname);
	
	std::cout << "Nickname ?" << std::endl;
	std::getline(std::cin, nickname);
	
	while (true)
	{
		std::cout << "Phone number ?" << std::endl;
		std::getline(std::cin, phonenumber); 
		if (phonenumber.length() != 10)
		{
			std::cout << "Enter a phone number with 10 digits" << std::endl;
			continue;
		}
		bool all_digit = true;
		for (char c : phonenumber)
		{
			if (!std::isdigit(c))
			{
				all_digit = false;
				break;
			}
		}
		if (!all_digit)
		{
			std::cout << "Enter a phone number with 10 digits" << std::endl;
			continue;
		}
		break;
	}
	
	std::cout << "Dark secret ?" << std::endl;
	std::getline(std::cin, darksecret);

	if (firstname.empty() || lastname.empty() || nickname.empty() || phonenumber.empty() || darksecret.empty())
	{
		std::cout << "Empty field - Not good - redo with filled parameters" << std::endl;
		return ;
	}

	Contact newcontact(firstname, lastname, nickname, phonenumber, darksecret); 

	if (contactnbr < MAX_CONTACT)
	{
		the_contacts[contactnbr] = newcontact;
		contactnbr++;
	}
	else
	{
		the_contacts[oldestindex] = newcontact;
		oldestindex = (oldestindex + 1) % MAX_CONTACT;
	}

	std::cout << "Added contact ok" << std::endl;
}

void PhoneBook::searchContact(void) const
{
	if (contactnbr == 1)
	{
		std::cout << "Empty contact list" << std::endl;
		return ;
	}
	
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First name" << "|" << std::setw(10) << "Last name" << "|" << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(44, '-') << std::endl;

	for (int i = 1; i < contactnbr; i++)
	{
		std::string firstname = the_contacts[i].getfirstname();
		std::string lastname = the_contacts[i].getlastname();
		std::string nickname = the_contacts[i].getnickname();

		if (firstname.length() > 10)
			firstname = firstname.substr(0, 9) + ".";
		if (lastname.length() > 10)
			lastname = lastname.substr(0, 9) + ".";
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		
		std::cout << std::setw(10) << i << "|"
					<< std::setw(10) << firstname << "|"
					<< std::setw(10) << lastname << "|"
					<< std::setw(10) << nickname<< "|" << std::endl;
	}

	std::string input;
	int index;

	std::cout << "Enter index number" << std::endl;
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Must enter a digit" << std::endl;
		return ;
	}
	if (input.length() > 1)
	{
		std::cout << "Enter inboud index (1 - 8)" << std::endl;
		return ;
	}
	for (char c : input)
	{
		if (!std::isdigit(c))
		{
			std::cout << "Not a digit, please enter only a digit within range" << std::endl;
			return;
		}
	}
	index = std::stoi(input);
	if (index >= 1 && index < contactnbr)
	{
		std::cout << "First Name: " << the_contacts[index].getfirstname() << std::endl;
		std::cout << "Last Name: " << the_contacts[index].getlastname() << std::endl;
		std::cout << "Nickname: " << the_contacts[index].getnickname() << std::endl;
		std::cout << "Phone Number: " << the_contacts[index].getphonenumber() << std::endl;
		std::cout << "Darkest Secret: " << the_contacts[index].getdarksecret() << std::endl;
	}
	else
		std::cout << "Index out of bound" << std::endl;	
}

PhoneBook::~PhoneBook()
{
		std::cout << "Exit PhoneBook" << std::endl;
}
