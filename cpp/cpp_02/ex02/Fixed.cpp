
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPoint = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = other._fixedPoint;
}

Fixed::Fixed(const int to_convert)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = to_convert << frac_bits;
}

Fixed::Fixed(const float to_convert)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(to_convert * (1 << frac_bits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}

bool Fixed::operator>(const Fixed &other)
{
	return (this->_fixedPoint > other._fixedPoint);
}

bool Fixed::operator<(const Fixed &other)
{
	return (this->_fixedPoint < other._fixedPoint);
}

bool Fixed::operator>=(const Fixed &other)
{
	return (this->_fixedPoint >= other._fixedPoint);
}

bool Fixed::operator<=(const Fixed &other)
{
	return (this->_fixedPoint <= other._fixedPoint);
}

bool Fixed::operator==(const Fixed &other)
{
	return (this->_fixedPoint == other._fixedPoint);
}

bool Fixed::operator!=(const Fixed &other)
{
	return (this->_fixedPoint != other._fixedPoint);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;

	result.setRawBits(this->_fixedPoint + other._fixedPoint);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;

	result.setRawBits(this->_fixedPoint - other._fixedPoint);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;

	result._fixedPoint = roundf((float)(this->_fixedPoint) * other._fixedPoint / (1 << frac_bits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result;

	if (other._fixedPoint == 0)
	{
		std::cout << "divied by 0" << std::endl;
		return (result);
	}
		
	result._fixedPoint = roundf((float)(this->_fixedPoint) * (1 << frac_bits) / other._fixedPoint);
	return (result);
}


Fixed& Fixed::operator++()
{
	this->_fixedPoint += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;

	this->_fixedPoint += 1;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->_fixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;

	this->_fixedPoint -= 1;
	return (temp);
}


Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixedPoint < b._fixedPoint)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._fixedPoint < b._fixedPoint)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixedPoint > b._fixedPoint)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._fixedPoint > b._fixedPoint)
		return (a);
	return (b);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits called" << std::endl;
	this->_fixedPoint = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	results;
	results = (float)this->_fixedPoint / (1 << frac_bits);
	return (results);
}

int		Fixed::toInt(void) const
{
	int	results;
	results =this->_fixedPoint >> frac_bits;
	return (results);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}