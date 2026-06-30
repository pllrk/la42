
#include <iostream>
#include <string>
#include "whatever.hpp"


class Awesome 
{
private:
    int _n;
public:
    Awesome(int n = 0) : _n(n) {}

    int get() const { return _n; }

    // Overload comparison operators for min/max
    bool operator>(const Awesome& other) const { return this->_n > other._n; }
    bool operator<(const Awesome& other) const { return this->_n < other._n; }
};

// Overload << for printing
std::ostream& operator<<(std::ostream& os, const Awesome& a) {
    os << a.get();
    return os;
}

int main( void ) 
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	Awesome e(10);
    Awesome f(20);
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
	return 0;
}