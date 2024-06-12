/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:09:45 by phanta            #+#    #+#             */
/*   Updated: 2024/06/10 11:54:32 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac_bits=8;

Fixed::Fixed() : _value(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const int n) : _value(n<<_frac_bits)
{
    std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float n) : _value(roundf(n*(1<<_frac_bits)))
{
    std::cout<<"Float constructor called"<< std::endl;
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout<<"Copy constructor called"<<std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->_value=fixed.getRawBits();

    return(*this);
}

//comparison ops

bool    Fixed::operator!=(const Fixed &fixed)
{
    return(this->_value!=fixed.getRawBits());
}

bool    Fixed::operator<(const Fixed &fixed)
{
    return(this->_value<fixed.getRawBits());
}

bool    Fixed::operator>(const Fixed &fixed)
{
    return(this->_value>fixed.getRawBits());
}

bool    Fixed::operator<=(const Fixed &fixed)
{
    return(this->_value<=fixed.getRawBits());
}

bool    Fixed::operator>=(const Fixed &fixed)
{
    return(this->_value>=fixed.getRawBits());
}

bool    Fixed::operator==(const Fixed &fixed)
{
    return(this->_value==fixed.getRawBits());
}

//arithmetic ops

Fixed	Fixed::operator+(const Fixed &fixed)
{
	return (Fixed(this->toFloat()+fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
    return (Fixed(this->toFloat()-fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
    return (Fixed(this->toFloat()*fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
    return (Fixed(this->toFloat()/fixed.toFloat()));
}

//increment ops

Fixed   &Fixed::operator++()//pre
{
    this->_value++;
    return *this;
}

Fixed   Fixed::operator++(int)//post
{
    Fixed pre=*this;
    this->_value++;
    return pre;
}

Fixed   &Fixed::operator--()
{
    this->_value++;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed pre=*this;
    this->_value--;
    return pre;
}

//minmax

Fixed    &Fixed::min(Fixed &a, Fixed &b)
{
    if(a<b)
        return(a);
    return(b);
}
const Fixed    &Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits()<b.getRawBits())
        return(a);
    return(b);
}

Fixed    &Fixed::max(Fixed &a, Fixed &b)
{
    if(a>b)
        return(a);
    return(b);
}

const Fixed    &Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits()>b.getRawBits())
        return(a);
    return(b);
}

int Fixed::getRawBits( void ) const
{
    return(this->_value);
}

void Fixed::setRawBits( int const raw )
{
    this->_value=raw;
}

float Fixed::toFloat( void ) const
{
     return ((float)_value / (1<<_frac_bits));
}

int Fixed::toInt( void ) const
{
    return (_value>>_frac_bits);
}

std::ostream	&operator<<(std::ostream &s, const Fixed &n)
{
    return (s<<n.toFloat());
}