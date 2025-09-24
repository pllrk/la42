#include <iostream>
#include <string>
#include <iomanip>

#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

class Contact
{
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darksecret;

public:
	Contact(void);
	Contact(const std::string& fname, const std::string& lname, const std::string& nname, const std::string& pnumber, 
			const std::string& dsecret);

	std::string getfirstname(void) const;
	std::string getlastname(void) const;
	std::string getnickname(void) const;
	std::string getphonenumber(void) const;
	std::string getdarksecret(void) const;

	bool isempty(void) const;

	~Contact();
};

class PhoneBook
{
private:
	static	const int MAX_CONTACT = 8;
	Contact the_contacts[MAX_CONTACT];
	int		contactnbr;
	int		oldestindex;

public:
	PhoneBook(void);

	void addContact(void);
	void searchContact(void) const;

	~PhoneBook();
};


#endif
