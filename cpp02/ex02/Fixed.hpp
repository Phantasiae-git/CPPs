#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
private:
    int _value;
    static const int _frac_bits;
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed& fixed);
    ~Fixed();
    Fixed&  operator=  (const Fixed& fixed);
    bool operator>(const Fixed &fixed);
    bool operator<(const Fixed &fixed);
    bool operator<=(const Fixed &fixed);
    bool operator>=(const Fixed &fixed);
    bool operator==(const Fixed &fixed);
    bool operator!=(const Fixed &fixed);
    Fixed operator+(const Fixed &fixed);
    Fixed operator-(const Fixed &fixed);
    Fixed operator*(const Fixed &fixed);
	Fixed operator/(const Fixed &nfixed);
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

    static Fixed    &min(Fixed &a, Fixed &b);
	static const Fixed  &min(const Fixed &a, const Fixed &b);
	static Fixed    &max(Fixed &a, Fixed &b);
	static const Fixed  &max(const Fixed &a, const Fixed &b);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &s, const Fixed &n);

#endif