#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int mValue;
        static const int mFractionalBits = 8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
