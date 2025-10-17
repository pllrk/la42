

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_fixedPoint;
	static const int	frac_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int to_convert);
	Fixed(const float to_convert);
	Fixed& operator=(const Fixed &other);

	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);

	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

	~Fixed();
	
	int 	getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif