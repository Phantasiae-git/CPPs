#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>


class Fixed
{
private:
    int _value;
    static const int _frac_bits;
public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed&  operator=  (const Fixed& fixed);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


#endif