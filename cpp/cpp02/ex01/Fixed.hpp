#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int mValue;
    static const int mFractionalBits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &fixed);
    Fixed(int const value);
    Fixed(float const value);
    Fixed &operator=(const Fixed &fixed);
    friend std::ostream &operator<<(std::ostream &out, Fixed const &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

#endif
