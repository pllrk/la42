
#include <iostream>
#include <string>

int main(void)
{
	std::string str;
	std::string *stringPTR;
	std::string &stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;

	std::cout << "string adress : " << &str << std::endl;
	std::cout << "string adress by stringSTR : " << stringPTR << std::endl;
	std::cout << "string adress by stringREF : " << &stringREF << std::endl;
	std::cout << "str : " << str << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "str by ref : " << stringREF << std::endl;
	
	return (0);
}
