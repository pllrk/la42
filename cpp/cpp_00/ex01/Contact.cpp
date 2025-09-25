#include "PhoneClass.hpp"

Contact::Contact(void) : firstname(""), lastname(""), nickname(""), phonenumber(""), darksecret("") 
{
}

Contact::Contact(const std::string& fname, const std::string& lname, const std::string& nname, const std::string& number, const std::string& secret) 
	: firstname(fname), lastname(lname), nickname(nname), phonenumber(number), darksecret(secret) 
{
}

std::string Contact::getfirstname(void) const 
{
	return (firstname);
}

std::string Contact::getlastname(void) const
{
	return (lastname);
}

std::string Contact::getnickname(void) const
{
	return (nickname);
}

std::string Contact::getphonenumber(void) const
{
	return (phonenumber);
}

std::string Contact::getdarksecret(void) const
{
	return (darksecret);
}

bool Contact::isempty(void) const
{
	return (firstname.empty() && lastname.empty() && nickname.empty() && phonenumber.empty() && darksecret.empty());
}

Contact::~Contact()
{
}
